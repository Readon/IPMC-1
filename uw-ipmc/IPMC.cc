/**
 * This file is intended to contain foundational IPMC structures.  This mainly
 * consists of allocations of common extern driver instances, and the core init
 * functions.
 */

/* Include system related */
#include <FreeRTOS.h>
#include <IPMC.h>
#include <task.h>
#include <semphr.h>
#include <event_groups.h>
#include <algorithm>
#include <functional>
#include <alloca.h>
#include <sys/time.h>

/* Include Xilinx related */
#include "xparameters.h"
#include "xscutimer.h"
#include "xscugic.h"
#include "xil_exception.h"
#include "xgpiops.h"

/* Include libs */
#include <libs/LogTree.h>
#include <libs/printf.h>
#include "libs/Utils.h"
#include "libs/XilinxImage.h"
#include "libs/Authentication.h"
#include "libs/base64/base64.h"
#include <libs/BackTrace.h>
#include <services/ipmi/IPMIFormats.h>

/* Include drivers */
#include <drivers/ps_xadc/PSXADC.h>
#include <drivers/ps_uart/PSUART.h>
#include <drivers/ps_spi/PSSPI.h>
#include <drivers/ps_isfqspi/PSISFQSPI.h>
#include <drivers/pl_uart/PLUART.h>
#include <drivers/pl_gpio/PLGPIO.h>
#include <drivers/pl_spi/PLSPI.h>
#include <drivers/watchdog/PSWDT.h>
#include <drivers/network/Network.h>
#include <drivers/spi_flash/SPIFLASH.h>
#include <drivers/spi_eeprom/SPIEEPROM.h>
#include <drivers/tracebuffer/TraceBuffer.h>
#include <drivers/ipmb/IPMBPair.h>
#include <drivers/ipmb/PSIPMB.h>
#include <drivers/pim400/PIM400.h>
#include <drivers/esm/ESM.h>
#include <drivers/ad7689/AD7689.h>
extern "C" {
#include "led_controller.h"
}

/* Include services */
#include <services/ipmi/ipmbsvc/IPMBSvc.h>
#include <services/ipmi/ipmbsvc/IPMICommandParser.h>
#include <services/ipmi/commands/IPMICmd_Index.h>
#include <services/ipmi/sdr/SensorDataRepository.h>
#include <services/ipmi/sdr/SensorDataRecord01.h>
#include <services/ipmi/sdr/SensorDataRecord02.h>
#include <services/ipmi/sdr/SensorDataRecord12.h>
#include <services/ipmi/sensor/SensorSet.h>
#include <services/ipmi/sensor/Sensor.h>
#include <services/ipmi/sensor/HotswapSensor.h>
#include <services/ipmi/sensor/ThresholdSensor.h>
#include <services/ipmi/MStateMachine.h>
#include <services/persistentstorage/PersistentStorage.h>
#include <services/console/UARTConsoleSvc.h>
#include <services/influxdb/InfluxDB.h>
#include <services/telnet/Telnet.h>
#include <services/lwiperf/Lwiperf.h>
#include <services/xvcserver/XVCServer.h>
#include <services/sntp/sntp.h>
#include <services/ftp/FTPServer.h>
#include <PayloadManager.h>


u8 IPMC_HW_REVISION = 1; // TODO: Detect, Update, etc
uint16_t IPMC_SERIAL = 0xffff;

/**
 * A FreeRTOS EventGroup initialized by main() before the scheduler starts.
 *
 * [1] 1b = ipmc_service_init() has exited.
 * [0] 1b = driver_init() has exited.
 */
EventGroupHandle_t init_complete;

PS_WDT *SWDT;
PS_UART *uart_ps0;
PS_ISFQSPI *isfqspi;
XGpioPs gpiops;

LogTree LOG("ipmc");
LogTree::Filter *console_log_filter;

SPI_EEPROM *eeprom_mac;
SPI_EEPROM *eeprom_data;
PersistentStorage *persistent_storage;

CommandParser console_command_parser;
std::shared_ptr<UARTConsoleSvc> console_service;

IPMBSvc *ipmb0;
EventReceiver ipmi_event_receiver;
IPMICommandParser *ipmi_command_parser;
SensorDataRepository sdr_repo;
SensorDataRepository device_sdr_repo;
SensorSet ipmc_sensors(&device_sdr_repo);
SemaphoreHandle_t fru_data_mutex;
std::vector<uint8_t> fru_data;
MStateMachine *mstatemachine = NULL;
PL_GPIO *handle_gpio;
LED_Controller atcaLEDs;
PayloadManager *payload_manager = NULL;

u8 mac_address[6];
Network *network;
InfluxDB *influxdbclient;
TelnetServer *telnet;

ESM *esm;

AD7689 *adc[2];

PS_XADC *xadc;

bool firmwareUpdateFailed = false;

static void init_device_sdrs(bool reinit=false);
static void init_fru_data(bool reinit=false);
static void tracebuffer_log_handler(LogTree &logtree, const std::string &message, enum LogTree::LogLevel level);
static void register_core_console_commands(CommandParser &parser);
static void console_log_handler(LogTree &logtree, const std::string &message, enum LogTree::LogLevel level);
static void watchdog_ontrip();
static size_t flash_read(uint8_t *buf, size_t size);
static size_t flash_write(uint8_t *buf, size_t size);

/** Stage 1 driver initialization.
 *
 * This function contains initialization for base hardware drivers.  It may or
 * may not activate or enable features.  It should not depend on any service,
 * nor make any service connections.  This will be called in the bootloader
 * application project as well, where most IPMC services will not be run.
 *
 * \param use_pl  Select whether or not the PL is loaded and PL drivers should
 *                be initialized.
 *
 * \note This function is called before the FreeRTOS scheduler has been started.
 */
void driver_init(bool use_pl) {
	/* Connect the TraceBuffer to the log system
	 *
	 * We don't need to keep a reference.  This will never require adjustment.
	 */
	new LogTree::Filter(LOG, tracebuffer_log_handler, LogTree::LOG_TRACE);

	// Initialize the watchdog.
	SWDT = new PS_WDT(XPAR_PS7_WDT_0_DEVICE_ID, 8, LOG["watchdog"], watchdog_ontrip);

	// Initialize the UART console.
	/* We use a large outbuf to prevent bursts of log messages (such as IPMI
	 * logs from FRU Data reads) from overflowing.
	 */
	uart_ps0 = new PS_UART(XPAR_PS7_UART_0_DEVICE_ID, XPAR_PS7_UART_0_INTR, 4096, 1<<16);
	console_log_filter = new LogTree::Filter(LOG, console_log_handler, LogTree::LOG_NOTICE);
	console_log_filter->register_console_commands(console_command_parser);
	LOG["console_log_command"].register_console_commands(console_command_parser);

	isfqspi = new PS_ISFQSPI(XPAR_PS7_QSPI_0_DEVICE_ID, XPAR_PS7_QSPI_0_INTR);

	PS_SPI *ps_spi0 = new PS_SPI(XPAR_PS7_SPI_0_DEVICE_ID, XPAR_PS7_SPI_0_INTR);
	eeprom_data = new SPI_EEPROM(*ps_spi0, 0, 0x8000, 64);
	eeprom_mac = new SPI_EEPROM(*ps_spi0, 1, 0x100, 16);
	persistent_storage = new PersistentStorage(*eeprom_data, LOG["persistent_storage"], SWDT);
	persistent_storage->register_console_commands(console_command_parser, "eeprom.");
	configASSERT(eeprom_mac->read(250, mac_address, 6));
	LOG["network"].log(stdsprintf("Our MAC address is %02hhx:%02hhx:%02hhx:%02hhx:%02hhx:%02hhx",
			mac_address[0], mac_address[1], mac_address[2], mac_address[3], mac_address[4], mac_address[5]), LogTree::LOG_NOTICE);
	configASSERT(eeprom_mac->read(0, reinterpret_cast<uint8_t*>(&IPMC_SERIAL), sizeof(IPMC_SERIAL)));

	// This has to be lower, so the serial number has been read by the time we register (or not register) set_serial.
	register_core_console_commands(console_command_parser);

	init_device_sdrs(false);
	init_fru_data(true);

	XGpioPs_Config* gpiops_config = XGpioPs_LookupConfig(XPAR_PS7_GPIO_0_DEVICE_ID);
	configASSERT(XST_SUCCESS == XGpioPs_CfgInitialize(&gpiops, gpiops_config, gpiops_config->BaseAddr));

	const int hwaddr_gpios[] = {39,40,41,45,47,48,49,50};
	uint8_t ipmbaddr = IPMBSvc::lookup_ipmb_address(hwaddr_gpios);
	LogTree &log_ipmb0 = LOG["ipmi"]["ipmb"]["ipmb0"];
	log_ipmb0.log(stdsprintf("Our IPMB0 address is %02Xh", ipmbaddr), LogTree::LOG_NOTICE);
	PS_IPMB *ps_ipmb[2];
	ps_ipmb[0] = new PS_IPMB(XPAR_PS7_I2C_0_DEVICE_ID, XPAR_PS7_I2C_0_INTR, ipmbaddr);
	ps_ipmb[1] = new PS_IPMB(XPAR_PS7_I2C_1_DEVICE_ID, XPAR_PS7_I2C_1_INTR, ipmbaddr);
	IPMBPair *ipmb0pair = new IPMBPair(ps_ipmb[0], ps_ipmb[1], &(log_ipmb0["outgoing_messages"]));
	ipmi_command_parser = new IPMICommandParser(ipmicmd_default, *ipmicmd_index);
	ipmb0 = new IPMBSvc(ipmb0pair, ipmbaddr, ipmi_command_parser, log_ipmb0, "ipmb0", SWDT);
	ipmb0->register_console_commands(console_command_parser, "ipmb0.");
	ipmi_event_receiver.ipmb = ipmb0;
	ipmi_event_receiver.lun = 0;
	ipmi_event_receiver.addr = 0x20; // Should be `0xFF "Disabled"`, maybe?

	console_log_filter->reconfigure(log_ipmb0, LogTree::LOG_INFO); // XXX For IPMI Testing

	// TODO: Clean up this part
	if (use_pl) {
		PL_I2C *i2c = new PL_I2C(XPAR_AXI_IIC_PIM400_DEVICE_ID, XPAR_FABRIC_AXI_IIC_PIM400_IIC2INTC_IRPT_INTR);
		(new PIM400(*i2c, 0x5E))->register_console_commands(console_command_parser, "pim400");

		LED_Controller_Initialize(&atcaLEDs, XPAR_AXI_ATCA_LED_CTRL_DEVICE_ID);

		for (int i = 0; i < 2; i++) {
			adc[i] = new AD7689(XPAR_AD7689_S_0_DEVICE_ID + i);
		}

		xadc = new PS_XADC(XPAR_XADCPS_0_DEVICE_ID);

		handle_gpio = new PL_GPIO(XPAR_AXI_GPIO_0_DEVICE_ID, XPAR_FABRIC_AXI_GPIO_0_IP2INTC_IRPT_INTR);
	}
}


/** IPMC service initialization.
 *
 * This function contains the initialization for IPMC services, and is
 * responsible for connecting and enabling/activating drivers and IPMC related
 * services.  It will not be called from the bootloader or non-IPMC application
 * projects, and the PL is assumed to be loaded.
 *
 * \note This function is called before the FreeRTOS scheduler has been started.
 */
void ipmc_service_init() {
	console_service = UARTConsoleSvc::create(*uart_ps0, console_command_parser, "console", LOG["console"]["uart"], true);

	UART* esm_uart = new PL_UART(XPAR_ESM_AXI_UARTLITE_ESM_DEVICE_ID, XPAR_FABRIC_ESM_AXI_UARTLITE_ESM_INTERRUPT_INTR);
	PL_GPIO* esm_gpio = new PL_GPIO(XPAR_ESM_AXI_GPIO_ESM_DEVICE_ID);
	NegResetPin* esm_reset = new NegResetPin(*esm_gpio, 0);

	PL_SPI* esm_spi = new PL_SPI(XPAR_ESM_AXI_QUAD_SPI_ESM_DEVICE_ID, XPAR_FABRIC_ESM_AXI_QUAD_SPI_ESM_IP2INTC_IRPT_INTR);
	SPIFlash* esm_flash = new SPIFlash(*esm_spi, 0);
	NegResetPin* esm_flash_reset = new NegResetPin(*esm_gpio, 1);

	esm = new ESM(esm_uart, esm_reset, esm_flash, esm_flash_reset);
	esm->register_console_commands(console_command_parser, "esm.");

	{
		mstatemachine = new MStateMachine(std::dynamic_pointer_cast<HotswapSensor>(ipmc_sensors.find_by_name("Hotswap")), LOG["mstatemachine"]);
		mstatemachine->register_console_commands(console_command_parser, "");

		// Since we can't do this processing in the ISR itself, we'll have to settle for this.
		SemaphoreHandle_t handle_isr_sem = xSemaphoreCreateBinary();
		UWTaskCreate("handle_switch", TASK_PRIORITY_SERVICE, [handle_isr_sem]() -> void {
			// Wait for IPMC initialization to complete.
			// The first time we update the physical handle state, the MStateMachine startup lock is cleared.
			xEventGroupWaitBits(init_complete, 0x03, pdFALSE, pdTRUE, portMAX_DELAY);

			while (1) {
				xSemaphoreTake(handle_isr_sem, pdMS_TO_TICKS(100));

				bool isPressed = handle_gpio->isPinSet(0);
				LED_Controller_SetOnOff(&atcaLEDs, 0, isPressed);
				mstatemachine->physical_handle_state(isPressed ? MStateMachine::HANDLE_CLOSED : MStateMachine::HANDLE_OPEN);
			}
		});
		handle_gpio->setIRQCallback([handle_isr_sem](uint32_t pin) -> void { xSemaphoreGive(handle_isr_sem); });
	}
	payload_manager = new PayloadManager(mstatemachine, LOG["payload_manager"]);

	// Last services should be network related
	network = new Network(LOG["network"], mac_address, [](Network *network) {
		// Network Ready callback, start primary services
		sntp_init();

		// Start secondary services
		influxdbclient = new InfluxDB(LOG["influxdb"]);
		influxdbclient->register_console_commands(console_command_parser, "influxdb.");

		telnet = new TelnetServer(LOG["telnetd"]);

		// Start iperf server
		new Lwiperf(5001);

		// Start XVC server
		new XVCServer(XPAR_AXI_JTAG_0_BASEADDR);

		// Start FTP server
		VFS::addFile("virtual/flash.bin", VFS::File(flash_read, flash_write, 16 * 1024 * 1024));
		VFS::addFile("virtual/esm.bin", esm->createFlashFile());
		new FTPServer(Auth::ValidateCredentials);

		// Start the sensor gathering thread
		// TODO: Move at some point
		UWTaskCreate("statd", TASK_PRIORITY_BACKGROUND, []() -> void {
			const std::string ipmc_mac = stdsprintf("%02x:%02x:%02x:%02x:%02x:%02x",
					mac_address[0], mac_address[1], mac_address[2], mac_address[3], mac_address[4], mac_address[5]);

			ADC::Channel::Callback tmp36 = [](float r) -> float  { return (r - 0.5) * 100.0; };
			ADC::Channel v12pyld  (*adc[0], 0, 5.640);
			ADC::Channel v5pyld   (*adc[0], 4, 2.400);
			ADC::Channel v3p3pyld (*adc[0], 6, 1.600);
			ADC::Channel v3p3mp   (*adc[0], 7, 1.600);
			ADC::Channel tCDBbot  (*adc[1], 0, tmp36);
			ADC::Channel v1p0eth  (*adc[1], 2);
			ADC::Channel v2p5eth  (*adc[1], 4, 1.216);
			ADC::Channel v1p2phy  (*adc[1], 5);
			ADC::Channel tCDBtop  (*adc[1], 7, tmp36);

			while (1) {
				vTaskDelay(pdMS_TO_TICKS(10000));

				const InfluxDB::Timestamp timestamp = InfluxDB::getCurrentTimestamp();

				const size_t heapBytes = configTOTAL_HEAP_SIZE - xPortGetFreeHeapSize();

				influxdbclient->write("ipmc.system", {{"id", ipmc_mac}, {"name", "heap.free"}}, {{"value", std::to_string(heapBytes)}}, timestamp);
				influxdbclient->write("ipmc.temperature", {{"id", ipmc_mac}, {"name", "xadc"}}, {{"value", std::to_string(xadc->getTemperature())}}, timestamp);
				influxdbclient->write("ipmc.temperature", {{"id", ipmc_mac}, {"name", "adc0"}}, {{"value", std::to_string(adc[0]->getTemperature())}}, timestamp);
				influxdbclient->write("ipmc.temperature", {{"id", ipmc_mac}, {"name", "adc1"}}, {{"value", std::to_string(adc[1]->getTemperature())}}, timestamp);
				influxdbclient->write("ipmc.voltage", {{"id", ipmc_mac}, {"name", "vccaux"}}, {{"value", std::to_string(xadc->getVccAux())}}, timestamp);
				influxdbclient->write("ipmc.voltage", {{"id", ipmc_mac}, {"name", "vbram"}}, {{"value", std::to_string(xadc->getVbram())}}, timestamp);
				influxdbclient->write("ipmc.voltage", {{"id", ipmc_mac}, {"name", "vccpint"}}, {{"value", std::to_string(xadc->getVccPInt())}}, timestamp);
				influxdbclient->write("ipmc.voltage", {{"id", ipmc_mac}, {"name", "vccpaux"}}, {{"value", std::to_string(xadc->getVccPAux())}}, timestamp);
				influxdbclient->write("ipmc.voltage", {{"id", ipmc_mac}, {"name", "vccpdro"}}, {{"value", std::to_string(xadc->getVccPdro())}}, timestamp);

				influxdbclient->write("cdb.temperature", {{"id", ipmc_mac}, {"name", "top"}}, {{"value", std::to_string((float)tCDBtop)}}, timestamp);
				influxdbclient->write("cdb.temperature", {{"id", ipmc_mac}, {"name", "bot"}}, {{"value", std::to_string((float)tCDBbot)}}, timestamp);
				influxdbclient->write("cdb.voltage", {{"id", ipmc_mac}, {"name", "v12pyld"}}, {{"value", std::to_string((float)v12pyld)}}, timestamp);
				influxdbclient->write("cdb.voltage", {{"id", ipmc_mac}, {"name", "v5pyld"}}, {{"value", std::to_string((float)v5pyld)}}, timestamp);
				influxdbclient->write("cdb.voltage", {{"id", ipmc_mac}, {"name", "v3p3pyld"}}, {{"value", std::to_string((float)v3p3pyld)}}, timestamp);
				influxdbclient->write("cdb.voltage", {{"id", ipmc_mac}, {"name", "v3p3mp"}}, {{"value", std::to_string((float)v3p3mp)}}, timestamp);
				influxdbclient->write("cdb.voltage", {{"id", ipmc_mac}, {"name", "v1p0eth"}}, {{"value", std::to_string((float)v1p0eth)}}, timestamp);
				influxdbclient->write("cdb.voltage", {{"id", ipmc_mac}, {"name", "v2p5eth"}}, {{"value", std::to_string((float)v2p5eth)}}, timestamp);
				influxdbclient->write("cdb.voltage", {{"id", ipmc_mac}, {"name", "v1p2phy"}}, {{"value", std::to_string((float)v1p2phy)}}, timestamp);

				float esmTemp = 0.0;
				if (esm->getTemperature(esmTemp)) {
					influxdbclient->write("esm.temperature", {{"id", ipmc_mac}, {"name", "temp"}}, {{"value", std::to_string(esmTemp)}}, timestamp);
				}
			}
		});
	});
	network->register_console_commands(console_command_parser, "network.");
}

static void add_to_sdr_repo(SensorDataRepository &repo, const SensorDataRecord &sdr, SensorDataRepository::reservation_t &reservation) {
	while (true) {
		try {
			repo.add(sdr, reservation);
			return;
		}
		catch (SensorDataRepository::reservation_cancelled_error) {
			reservation = repo.reserve();
		}
	}
}

/**
 * Initialize Device SDRs for this controller.
 */
static void init_device_sdrs(bool reinit) {
	SensorDataRepository::reservation_t reservation = device_sdr_repo.reserve();

#define ADD_TO_REPO(sdr) add_to_sdr_repo(device_sdr_repo, sdr, reservation)

	{
		// Management Controller Device Locator Record for ourself.
		SensorDataRecord12 mcdlr;
		mcdlr.initialize_blank("UW ZYNQ IPMC");
		mcdlr.device_slave_address(ipmb0->ipmb_address);
		mcdlr.channel(0);
		mcdlr.acpi_device_power_state_notification_required(false);
		mcdlr.acpi_system_power_state_notification_required(false);
		mcdlr.is_static(false);
		mcdlr.init_agent_logs_errors(false);
		mcdlr.init_agent_log_errors_accessing_this_controller(false);
		mcdlr.init_agent_init_type(SensorDataRecord12::INIT_ENABLE_EVENTS);
		mcdlr.cap_chassis_device(false);
		mcdlr.cap_bridge(false);
		mcdlr.cap_ipmb_event_generator(true);
		mcdlr.cap_ipmb_event_receiver(true); // Possibly not required.  See also Get PICMG Properties code.
		mcdlr.cap_fru_inventory_device(true);
		mcdlr.cap_sel_device(false);
		mcdlr.cap_sdr_repository_device(true);
		mcdlr.cap_sensor_device(true);
		mcdlr.entity_id(0xA0);
		mcdlr.entity_instance(0x60);
		ADD_TO_REPO(mcdlr);
	}

	{
		SensorDataRecord02 hotswap;
		hotswap.initialize_blank("Hotswap");
		hotswap.sensor_owner_id(0); // Tag as "self". This will be auto-calculated in "Get SDR" commands.
		hotswap.sensor_owner_channel(0); // See above.
		hotswap.sensor_owner_lun(0); // See above.
		hotswap.sensor_number(1);
		hotswap.entity_id(0xA0);
		hotswap.entity_instance(0x60);
		hotswap.events_enabled_default(true);
		hotswap.scanning_enabled_default(true);
		hotswap.sensor_auto_rearm(true);
		hotswap.sensor_hysteresis_support(SensorDataRecordReadableSensor::ACCESS_READWRITE);
		hotswap.sensor_threshold_access_support(SensorDataRecordReadableSensor::ACCESS_READWRITE);
		hotswap.sensor_event_message_control_support(SensorDataRecordReadableSensor::EVTCTRL_GRANULAR);
		hotswap.sensor_type_code(0xf0); // Hotswap
		hotswap.event_type_reading_code(0x6f); // Sensor-specific discrete
		hotswap.assertion_lower_threshold_reading_mask(0x00ff); // M7:M0
		hotswap.deassertion_upper_threshold_reading_mask(0); // M7:M0
		hotswap.discrete_reading_setable_threshold_reading_mask(0x00ff); // M7:M0
		// I don't need to specify unit type codes for this sensor.
		ADD_TO_REPO(hotswap);
		if (!ipmc_sensors.get(hotswap.sensor_number()))
			ipmc_sensors.add(std::make_shared<HotswapSensor>(hotswap.record_key(), LOG["sensors"]["Hotswap"]));
	}

	{
		SensorDataRecord01 sensor;
		sensor.initialize_blank("Payload 3.3V");
		sensor.sensor_owner_id(0); // Tag as "self". This will be auto-calculated in "Get SDR" commands.
		sensor.sensor_owner_channel(0); // See above.
		sensor.sensor_owner_lun(0); // Generally zero
		sensor.sensor_number(2);
		sensor.entity_id(0x0); // TODO
		sensor.entity_instance(0x60); // TODO
		//sensor.sensor_setable(false); // Default, Unsupported
		//sensor.initialize_scanning_enabled(false); // Default (An Init Agent is not required.)
		//sensor.initialize_events_enabled(false); // Default (An Init Agent is not required.)
		//sensor.initialize_thresholds(false); // Default (An Init Agent is not required.)
		//sensor.initialize_hysteresis(false); // Default (An Init Agent is not required.)
		//sensor.initialize_sensor_type(false); // Default (An Init Agent is not required.)
		sensor.ignore_if_entity_absent(true);
		sensor.events_enabled_default(true);
		sensor.scanning_enabled_default(true);
		sensor.sensor_auto_rearm(true);
		sensor.sensor_hysteresis_support(SensorDataRecordReadableSensor::ACCESS_READWRITE);
		sensor.sensor_threshold_access_support(SensorDataRecordReadableSensor::ACCESS_READWRITE);
		sensor.sensor_event_message_control_support(SensorDataRecordReadableSensor::EVTCTRL_GRANULAR);
		sensor.sensor_type_code(0x02); // Voltage
		sensor.event_type_reading_code(SensorDataRecordReadableSensor::EVENT_TYPE_THRESHOLD_SENSOR);
		sensor.assertion_lower_threshold_reading_mask(0x7fff); // All events supported & LNR, LCR, LNC, UNC, UCR, UNR assertions enabled.
		sensor.deassertion_upper_threshold_reading_mask(0x7fff); // All events supported & LNR, LCR, LNC, UNC, UCR, UNR deassertions enabled.
		sensor.discrete_reading_setable_threshold_reading_mask(0x3fff); // All thresholds are configurable.
		sensor.units_numeric_format(SensorDataRecord01::UNITS_UNSIGNED);
		sensor.units_rate_unit(SensorDataRecordReadableSensor::RATE_UNIT_NONE);
		sensor.units_base_unit(4); // Volts
		sensor.units_modifier_unit(0); // unspecified
		sensor.units_modifier_unit_method(SensorDataRecordReadableSensor::MODIFIER_UNIT_NONE);
		sensor.linearization(SensorDataRecord01::LIN_LINEAR);
		// IPMI Specifies a linearization function of: y = L[(Mx + (B * 10^(Bexp) ) ) * 10^(Rexp) ]
		// Our settings produce a valid range of 2 (Volts) to 4.55 (Volts) with 0.01 Volts granularity.
		sensor.conversion_m(1);
		sensor.conversion_b(2);
		sensor.conversion_b_exp(2);
		sensor.conversion_r_exp(-2);
		sensor.sensor_direction(SensorDataRecordReadableSensor::DIR_INPUT);
		//sensor.normal_min_specified(false); // Default
		//sensor.normal_min_rawvalue(0); // Unspecified
		//sensor.normal_max_specified(false); // Default
		//sensor.normal_max_rawvalue(0); // Unspecified
		sensor.nominal_reading_specified(true);
		sensor.nominal_reading_rawvalue(130); // 3.3 Volts
		sensor.threshold_unr_rawvalue(147); // 3.47 Volts
		sensor.threshold_ucr_rawvalue(142); // 3.42 Volts
		sensor.threshold_unc_rawvalue(137); // 3.37 Volts
		sensor.threshold_lnc_rawvalue(123); // 3.23 Volts
		sensor.threshold_lcr_rawvalue(118); // 3.18 Volts
		sensor.threshold_lnr_rawvalue(113); // 3.13 Volts
		sensor.hysteresis_high(2); // +0.02 Volts
		sensor.hysteresis_low(2); // -0.02 Volts
		ADD_TO_REPO(sensor);
		if (!ipmc_sensors.get(sensor.sensor_number()))
			ipmc_sensors.add(std::make_shared<ThresholdSensor>(sensor.record_key(), LOG["sensors"]["Payload 3.3V"]));
	}

#undef ADD_TO_REPO

	UWTaskCreate("persist_sdr", TASK_PRIORITY_SERVICE, [reinit]() -> void {
		VariablePersistentAllocation sdr_persist(*persistent_storage, PersistentStorageAllocations::WISC_SDR_REPOSITORY);
		// If not reinitializing, merge in saved configuration, overwriting matching records.
		if (!reinit)
			device_sdr_repo.u8import(sdr_persist.get_data());

		// Store the newly initialized Device SDRs
		sdr_persist.set_data(device_sdr_repo.u8export());

		// I think these needta be imported to the main SDR repo too?
		sdr_repo.add(device_sdr_repo, 0);
	});
}

/**
 * Generate the appropriate headers (up to and excluding Record Format Version)
 * and add the PICMG multirecord to the provided FRU Data vector.
 *
 * @param fruarea The FRU Data area to be appended
 * @param mrdata The multirecord to be added
 * @param last_record true if the "end of list" flag should be set on this record, else false
 * @param record_format The record format version, if not default
 */
static void add_PICMG_multirecord (std::vector<uint8_t> &fruarea, std::vector<uint8_t> mrdata, bool last_record, uint8_t record_format=2) {
	static const std::vector<uint8_t> mrheader{
		0xC0, // "OEM", specified
		0x00, // [7] 1b=EOL (set later);  [3:0] record_format (set later)
		0, // Length (placeholder)
		0, // Record checksum (placeholder)
		0, // Header checksum (placeholder)
		0x5A, // Mfgr: PICMG, specified
		0x31, // Mfgr: PICMG, specified
		0x00, // Mfgr: PICMG, specified
	};
	mrdata.insert(mrdata.begin(), mrheader.begin(), mrheader.end());
	mrdata[1] = (last_record ? 0x80 : 0) | record_format;
	mrdata[2] = mrdata.size();
	mrdata[3] = ipmi_checksum(std::vector<uint8_t>(std::next(mrdata.begin(), 5), mrdata.end()));
	mrdata[4] = ipmi_checksum(std::vector<uint8_t>(mrdata.begin(), std::next(mrdata.begin(), 5)));
	fruarea.insert(fruarea.end(), mrdata.begin(), mrdata.end());
}

void init_fru_data(bool reinit) {
	std::vector<uint8_t> tlstring;

	std::vector<uint8_t> board_info;
	board_info.push_back(0x01); // Format Version
	board_info.push_back(0x00); // Length Placeholder
	board_info.push_back(25);   // Language Code (English)
	board_info.push_back(0x00); // Mfg Date/Time (Unspecified)
	board_info.push_back(0x00); // Mfg Date/Time (Unspecified)
	board_info.push_back(0x00); // Mfg Date/Time (Unspecified)
	tlstring = encode_ipmi_type_length_field("University of Wisconsin");
	board_info.insert(board_info.end(), tlstring.begin(), tlstring.end()); // Board Mfgr.
	tlstring = encode_ipmi_type_length_field("ZYNQ IPMC");
	board_info.insert(board_info.end(), tlstring.begin(), tlstring.end()); // Board Product Name
	tlstring = encode_ipmi_type_length_field(std::to_string(IPMC_SERIAL));
	board_info.insert(board_info.end(), tlstring.begin(), tlstring.end()); // Board Serial
	tlstring = encode_ipmi_type_length_field(std::string("IPMC Rev") + std::to_string(IPMC_HW_REVISION));
	board_info.insert(board_info.end(), tlstring.begin(), tlstring.end()); // Board Part Number
	tlstring = encode_ipmi_type_length_field(GIT_DESCRIBE);
	board_info.insert(board_info.end(), tlstring.begin(), tlstring.end()); // FRU File ID (in our case generating software)
	board_info.push_back(0xC1); // End of T/L Records.
	board_info.push_back(0); // Ensure at least one pad, to be used for checksum.
	while (board_info.size() % 8)
		board_info.push_back(0); // Pad.
	board_info[1] = board_info.size()/8; // Update length
	board_info.pop_back(); // Remove one pad for checksum.
	board_info.push_back(ipmi_checksum(board_info));


	std::vector<uint8_t> product_info;
	product_info.push_back(0x01); // Format Version
	product_info.push_back(0x00); // Length Placeholder
	product_info.push_back(25);   // Language Code (English)
	tlstring = encode_ipmi_type_length_field("University of Wisconsin");
	product_info.insert(product_info.end(), tlstring.begin(), tlstring.end()); // Mfgr Name
	tlstring = encode_ipmi_type_length_field("ZYNQ IPMC");
	product_info.insert(product_info.end(), tlstring.begin(), tlstring.end()); // Product Name
	tlstring = encode_ipmi_type_length_field(std::string("IPMC Rev") + std::to_string(IPMC_HW_REVISION));
	product_info.insert(product_info.end(), tlstring.begin(), tlstring.end()); // Product Part/Model Number
	tlstring = encode_ipmi_type_length_field(std::to_string(IPMC_HW_REVISION));
	product_info.insert(product_info.end(), tlstring.begin(), tlstring.end()); // Product Version
		tlstring = encode_ipmi_type_length_field(std::to_string(IPMC_SERIAL));
	product_info.insert(product_info.end(), tlstring.begin(), tlstring.end()); // Product Serial
	product_info.push_back(0xC0); // Asset Tag (NULL)
	tlstring = encode_ipmi_type_length_field(GIT_DESCRIBE);
	product_info.insert(product_info.end(), tlstring.begin(), tlstring.end()); // FRU File ID (in our case generating software)
	product_info.push_back(0xC1); // End of T/L Records.
	product_info.push_back(0); // Ensure at least one pad, to be used for checksum.
	while (product_info.size() % 8)
		product_info.push_back(0); // Pad.
	product_info[1] = product_info.size()/8; // Update length
	product_info.pop_back(); // Remove one pad for checksum.
	product_info.push_back(ipmi_checksum(product_info));


	fru_data.resize(8);
	fru_data[0] = 0x01; // Common Header Format Version
	fru_data[1] = 0x00; // Internal Use Area Offset (multiple of 8 bytes)
	fru_data[2] = 0x00; // Chassis Info Area Offset (multiple of 8 bytes)
	fru_data[3] = 0x01; // Board Area Offset (multiple of 8 bytes)
	fru_data[4] = 0x01 + board_info.size()/8; // Product Info Area Offset (multiple of 8 bytes)
	fru_data[5] = 0x01 + board_info.size()/8 + product_info.size()/8; // Multi-Record Area Offset (multiple of 8 bytes)
	fru_data[6] = 0x00; // PAD, write as 00h
	fru_data[7] = 0x00;
	fru_data[7] = ipmi_checksum(fru_data); // Checksum

	fru_data.insert(fru_data.end(), board_info.begin(), board_info.end());
	fru_data.insert(fru_data.end(), product_info.begin(), product_info.end());

	/* Carrier Activation and Current Management record
	 * ...not that we have any AMC modules.
	 *
	 * This is supposed to specify the maximum power we can provide to our AMCs,
	 * and be used for validating our AMC modules' power requirements.
	 */
	add_PICMG_multirecord(fru_data, std::vector<uint8_t>{0x17, 0, 0x3f /* ~75W for all AMCs (and self..?) */, 5}, false);

	/* Board Point-to-Point Connectivity Record
	 *
	 */
	add_PICMG_multirecord(fru_data, std::vector<uint8_t>{0x14, 0,
		0, // No OEM GUIDs defined here.
		// No OEM GUIDs defined here.

		/* Link Descriptor 1: 1G to Hub Slots (1 of 2)
		 * [31:24] = 0 (Single Channel Link (No Grouping))
		 * [23:20] = 0 (Link Type Extension (10/100/1000BASE-T (four-pair)))
		 * [19:12] = 1 (Link Type (From PICMG 3.0 Table 3-52))
		 * [11: 0] = Link Designator (from PICMG 3.0 Table 3-51)
		 *           [ 11] = 1 (Port 3 Excluded)
		 *           [ 10] = 1 (Port 2 Excluded)
		 *           [  9] = 1 (Port 1 Excluded)
		 *           [  8] = 1 (Port 0 Included)
		 *           [7:6] = 0 (Base Interface)
		 *           [5:0] = 1 (Channel 1)
		 */
		0x01, // [ 7: 0]
		0x11, // [15: 8]
		0x00, // [23:16]
		0x00, // [31:24]

		/* Link Descriptor 2: 1G to Hub Slots (2 of 2)
		 * [31:24] = 0 (Single Channel Link (No Grouping))
		 * [23:20] = 0 (Link Type Extension (10/100/1000BASE-T (four-pair)))
		 * [19:12] = 1 (Link Type (From PICMG 3.0 Table 3-52))
		 * [11: 0] = Link Designator (from PICMG 3.0 Table 3-51)
		 *           [ 11] = 1 (Port 3 Included)
		 *           [ 10] = 1 (Port 2 Included)
		 *           [  9] = 1 (Port 1 Included)
		 *           [  8] = 1 (Port 0 Included)
		 *           [7:6] = 0 (Base Interface)
		 *           [5:0] = 2 (Channel 2)
		 */
		0x02, // [ 7: 0]
		0x11, // [15: 8]
		0x00, // [23:16]
		0x00, // [31:24]
		}, true);

	UWTaskCreate("persist_fru", TASK_PRIORITY_SERVICE, [reinit]() -> void {
		safe_init_static_mutex(fru_data_mutex, false);
		MutexGuard<false> lock(fru_data_mutex, true);
		VariablePersistentAllocation fru_persist(*persistent_storage, PersistentStorageAllocations::WISC_FRU_DATA);

		// If not reinitializing, and there's an area to read, replace ours, else write.
		std::vector<uint8_t> persist_data = fru_persist.get_data();
		if (persist_data.size() && !reinit)
			fru_data = persist_data;

		// Store the newly initialized Device SDRs
		fru_persist.set_data(fru_data);
	});
}

// TODO: Will be moved (see #19)
static size_t flash_read(uint8_t *buf, size_t size) {
	size_t totalsize = isfqspi->GetTotalSize();
	size_t pagesize = isfqspi->GetPageSize();
	int pagecount = totalsize / pagesize;

	for (int i = 0; i < pagecount; i++) {
		size_t addr = i * pagesize;
		uint8_t* ptr = isfqspi->ReadPage(addr);
		memcpy(buf + addr, ptr, pagesize);
	}

	return totalsize;
}

// TODO: Will be moved (see #19)
static size_t flash_write(uint8_t *buf, size_t size) {
	// Validate the bin file before writing
	BootFileValidationReturn r = validateBootFile(buf, size);
	if (r != BFV_VALID) {
		// File is invalid!
		printf("Received bin file has errors: %s. Aborting firmware update.",
				getBootFileValidationErrorString(r));
		return 0;
	} else {
		printf("Bin file is valid, proceeding with update.");
	}

	// Write the buffer to flash
	const size_t baseaddr = 0x0;

	size_t rem = size % isfqspi->GetPageSize();
	size_t pages = size / isfqspi->GetPageSize() + (size? 1 : 0);

	for (size_t i = 0; i < pages; i++) {
		size_t addr = i * isfqspi->GetPageSize();
		if (addr % isfqspi->GetSectorSize() == 0) {
			// This is the first page of a new sector, so erase the sector
			printf("Erasing sector 0x%08x..", addr + baseaddr);
			if (!isfqspi->SectorErase(addr + baseaddr)) {
				// Failed to erase
				printf("Failed to erase 0x%08x. Write to flash failed.", addr + baseaddr);
				firmwareUpdateFailed = true;
				return addr;
			}
		}

		if ((i == (pages-1)) && (rem != 0)) {
			// Last page, avoid a memory leak
			uint8_t tmpbuf[isfqspi->GetPageSize()];
			memset(tmpbuf, 0xFFFFFFFF, isfqspi->GetPageSize());

			memcpy(tmpbuf, buf + addr, rem);

			if (!isfqspi->WritePage(addr + baseaddr, tmpbuf)) {
				// Failed to write page
				printf("Failed to write page 0x%08x. Write to flash failed.", addr + baseaddr);
				firmwareUpdateFailed = true;
				return addr;
			}
		} else {
			if (!isfqspi->WritePage(addr + baseaddr, buf + addr)) {
				// Failed to write page
				printf("Failed to write page 0x%08x. Write to flash failed.", addr + baseaddr);
				firmwareUpdateFailed = true;
				return addr;
			}
		}
	}

	// Verify
	for (int i = 0; i < pages; i++) {
		size_t addr = i * isfqspi->GetPageSize();
		uint8_t* ptr = isfqspi->ReadPage(addr + baseaddr);
		int ret = 0;
		if ((i == (pages-1)) && (rem != 0)) {
			// Last page
			ret = memcmp(ptr, buf + addr, rem);
		} else {
			ret = memcmp(ptr, buf + addr, isfqspi->GetPageSize());
		}
		if (ret != 0) {
			printf("Page 0x%08x is different. Verification failed.", addr + baseaddr);
			firmwareUpdateFailed = true;
			return addr;
		}
	}

	printf("Flash image updated and verified successfully.");
	firmwareUpdateFailed = false;
	return size;
}

void* operator new(std::size_t n) {
	return malloc(n);
}
void operator delete(void* p) throw() {
	free(p);
}

std::string generate_banner() {
	std::string bannerstr;
	bannerstr += "********************************************************************************\n";
	bannerstr += "\n";
	bannerstr += std::string("ZYNQ-IPMC - Open-source IPMC hardware and software framework\n");
	bannerstr += std::string("HW revision : ") + std::to_string(IPMC_HW_REVISION) + "\n"; // TODO
	bannerstr += std::string("SW revision : ") + GIT_DESCRIBE + "\n";
	if (IPMC_SERIAL != 0xffff & IPMC_SERIAL != 0)
		bannerstr += std::string("HW serial   : ") + std::to_string(IPMC_SERIAL) + "\n";
	else
		bannerstr += std::string("HW serial   : unset\n");
	bannerstr += std::string("Build date  : ") + COMPILE_DATE + "\n";
	bannerstr += std::string("Build host  : ") + COMPILE_HOST + "\n";
	bannerstr += std::string("Build conf  : ") + BUILD_CONFIGURATION + "\n";
	bannerstr += std::string("OS version  : FreeRTOS ") + tskKERNEL_VERSION_NUMBER + "\n";

	if (GIT_STATUS[0] != '\0')
		bannerstr += std::string("\n") + GIT_STATUS; // contains a trailing \n
	bannerstr += "\n";
	bannerstr += "********************************************************************************\n";
	return bannerstr;
}

/**
 * This handler copies log messages to the tracebuffer.
 */
static void tracebuffer_log_handler(LogTree &logtree, const std::string &message, enum LogTree::LogLevel level) {
	TRACE.log(logtree.path.data(), logtree.path.size(), level, message.data(), message.size());
}

#include "core_console_commands/date.h"
#include "core_console_commands/flash_info.h"
#include "core_console_commands/ps.h"
#include "core_console_commands/restart.h"
#include "core_console_commands/setauth.h"
#include "core_console_commands/set_serial.h"
#include "core_console_commands/throw.h"
#include "core_console_commands/upload.h"
#include "core_console_commands/uptime.h"
#include "core_console_commands/version.h"

static void register_core_console_commands(CommandParser &parser) {
	console_command_parser.register_command("uptime", std::make_shared<ConsoleCommand_uptime>());
	console_command_parser.register_command("date", std::make_shared<ConsoleCommand_date>());
	console_command_parser.register_command("version", std::make_shared<ConsoleCommand_version>());
	console_command_parser.register_command("ps", std::make_shared<ConsoleCommand_ps>());
	console_command_parser.register_command("restart", std::make_shared<ConsoleCommand_restart>());
	console_command_parser.register_command("flash_info", std::make_shared<ConsoleCommand_flash_info>());
	console_command_parser.register_command("setauth", std::make_shared<ConsoleCommand_setauth>());
	if (IPMC_SERIAL == 0 || IPMC_SERIAL == 0xFFFF) // The serial is settable only if unset.  This implements lock on write (+reboot).
		console_command_parser.register_command("set_serial", std::make_shared<ConsoleCommand_set_serial>());
	console_command_parser.register_command("upload", std::make_shared<ConsoleCommand_upload>());
	console_command_parser.register_command("throw", std::make_shared<ConsoleCommand_throw>());
	console_command_parser.register_command("trace", std::make_shared<ConsoleCommand_trace>());
}

static void console_log_handler(LogTree &logtree, const std::string &message, enum LogTree::LogLevel level) {
	std::string logmsg = ConsoleSvc_log_format(message, level);

	/* We write with 0 timeout, because we'd rather lose lines than hang on UART
	* output.  That's what the tracebuffer is for anyway.
	*/
	if (!console_service || IN_INTERRUPT() || IN_CRITICAL()) {
		// Still early startup.
		windows_newline(logmsg);
		uart_ps0->write((const u8*)logmsg.data(), logmsg.size(), 0);
	}
	else {
		// We have to use a short timeout here, rather than none, due to the mutex involved.
		// TODO: Maybe there's a better way?
		console_service->write(logmsg, 1);
	}
}

static void watchdog_ontrip() {
	LOG["watchdog"].log(std::string("\n")+ConsoleCommand_ps::get_ps_string(), LogTree::LOG_NOTICE);
}
