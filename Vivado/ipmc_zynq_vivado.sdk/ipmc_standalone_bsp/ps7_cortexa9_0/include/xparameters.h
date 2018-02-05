#ifndef XPARAMETERS_H   /* prevent circular inclusions */
#define XPARAMETERS_H   /* by using protection macros */

/* Definition for CPU ID */
#define XPAR_CPU_ID 0

/* Definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_PS7_CORTEXA9_0_CPU_CLK_FREQ_HZ 666666687


/******************************************************************/

/* Canonical definitions for peripheral PS7_CORTEXA9_0 */
#define XPAR_CPU_CORTEXA9_0_CPU_CLK_FREQ_HZ 666666687


/******************************************************************/

#include "xparameters_ps.h"

#define STDIN_BASEADDRESS 0xE0000000
#define STDOUT_BASEADDRESS 0xE0000000

/******************************************************************/


/* Definitions for peripheral PS7_DDR_0 */
#define XPAR_PS7_DDR_0_S_AXI_BASEADDR 0x00100000
#define XPAR_PS7_DDR_0_S_AXI_HIGHADDR 0x0FFFFFFF


/******************************************************************/

/* Definitions for driver DEVCFG */
#define XPAR_XDCFG_NUM_INSTANCES 1

/* Definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_PS7_DEV_CFG_0_DEVICE_ID 0
#define XPAR_PS7_DEV_CFG_0_BASEADDR 0xF8007000
#define XPAR_PS7_DEV_CFG_0_HIGHADDR 0xF80070FF


/******************************************************************/

/* Canonical definitions for peripheral PS7_DEV_CFG_0 */
#define XPAR_XDCFG_0_DEVICE_ID XPAR_PS7_DEV_CFG_0_DEVICE_ID
#define XPAR_XDCFG_0_BASEADDR 0xF8007000
#define XPAR_XDCFG_0_HIGHADDR 0xF80070FF


/******************************************************************/

/* Definitions for driver DMAPS */
#define XPAR_XDMAPS_NUM_INSTANCES 2

/* Definitions for peripheral PS7_DMA_NS */
#define XPAR_PS7_DMA_NS_DEVICE_ID 0
#define XPAR_PS7_DMA_NS_BASEADDR 0xF8004000
#define XPAR_PS7_DMA_NS_HIGHADDR 0xF8004FFF


/* Definitions for peripheral PS7_DMA_S */
#define XPAR_PS7_DMA_S_DEVICE_ID 1
#define XPAR_PS7_DMA_S_BASEADDR 0xF8003000
#define XPAR_PS7_DMA_S_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_DMA_NS */
#define XPAR_XDMAPS_0_DEVICE_ID XPAR_PS7_DMA_NS_DEVICE_ID
#define XPAR_XDMAPS_0_BASEADDR 0xF8004000
#define XPAR_XDMAPS_0_HIGHADDR 0xF8004FFF

/* Canonical definitions for peripheral PS7_DMA_S */
#define XPAR_XDMAPS_1_DEVICE_ID XPAR_PS7_DMA_S_DEVICE_ID
#define XPAR_XDMAPS_1_BASEADDR 0xF8003000
#define XPAR_XDMAPS_1_HIGHADDR 0xF8003FFF


/******************************************************************/

/* Definitions for driver EMACPS */
#define XPAR_XEMACPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_PS7_ETHERNET_0_DEVICE_ID 0
#define XPAR_PS7_ETHERNET_0_BASEADDR 0xE000B000
#define XPAR_PS7_ETHERNET_0_HIGHADDR 0xE000BFFF
#define XPAR_PS7_ETHERNET_0_ENET_CLK_FREQ_HZ 125000000
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_1000MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_1000MBPS_DIV1 1
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_100MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_100MBPS_DIV1 5
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_10MBPS_DIV0 8
#define XPAR_PS7_ETHERNET_0_ENET_SLCR_10MBPS_DIV1 50


/******************************************************************/

/* Canonical definitions for peripheral PS7_ETHERNET_0 */
#define XPAR_XEMACPS_0_DEVICE_ID XPAR_PS7_ETHERNET_0_DEVICE_ID
#define XPAR_XEMACPS_0_BASEADDR 0xE000B000
#define XPAR_XEMACPS_0_HIGHADDR 0xE000BFFF
#define XPAR_XEMACPS_0_ENET_CLK_FREQ_HZ 125000000
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_1000Mbps_DIV1 1
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_100Mbps_DIV1 5
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV0 8
#define XPAR_XEMACPS_0_ENET_SLCR_10Mbps_DIV1 50


/******************************************************************/


/* Definitions for peripheral AMCS_AMC0_TPS2358_0 */
#define XPAR_AMCS_AMC0_TPS2358_0_S00_AXI_BASEADDR 0x43C20000
#define XPAR_AMCS_AMC0_TPS2358_0_S00_AXI_HIGHADDR 0x43C2FFFF


/* Definitions for peripheral AMCS_AMC1_TPS2358_0 */
#define XPAR_AMCS_AMC1_TPS2358_0_S00_AXI_BASEADDR 0x43C30000
#define XPAR_AMCS_AMC1_TPS2358_0_S00_AXI_HIGHADDR 0x43C3FFFF


/* Definitions for peripheral AMCS_AMC2_TPS2358_0 */
#define XPAR_AMCS_AMC2_TPS2358_0_S00_AXI_BASEADDR 0x43C40000
#define XPAR_AMCS_AMC2_TPS2358_0_S00_AXI_HIGHADDR 0x43C4FFFF


/* Definitions for peripheral AMCS_AMC3_TPS2358_0 */
#define XPAR_AMCS_AMC3_TPS2358_0_S00_AXI_BASEADDR 0x43C50000
#define XPAR_AMCS_AMC3_TPS2358_0_S00_AXI_HIGHADDR 0x43C5FFFF


/* Definitions for peripheral AMCS_AMC4_TPS2358_0 */
#define XPAR_AMCS_AMC4_TPS2358_0_S00_AXI_BASEADDR 0x43C60000
#define XPAR_AMCS_AMC4_TPS2358_0_S00_AXI_HIGHADDR 0x43C6FFFF


/* Definitions for peripheral AD7689_0 */
#define XPAR_AD7689_0_S_AXI_BASEADDR 0x43C00000
#define XPAR_AD7689_0_S_AXI_HIGHADDR 0x43C0FFFF


/* Definitions for peripheral AD7689_1 */
#define XPAR_AD7689_1_S_AXI_BASEADDR 0x43C10000
#define XPAR_AD7689_1_S_AXI_HIGHADDR 0x43C1FFFF


/* Definitions for peripheral PS7_AFI_0 */
#define XPAR_PS7_AFI_0_S_AXI_BASEADDR 0xF8008000
#define XPAR_PS7_AFI_0_S_AXI_HIGHADDR 0xF8008FFF


/* Definitions for peripheral PS7_AFI_1 */
#define XPAR_PS7_AFI_1_S_AXI_BASEADDR 0xF8009000
#define XPAR_PS7_AFI_1_S_AXI_HIGHADDR 0xF8009FFF


/* Definitions for peripheral PS7_AFI_2 */
#define XPAR_PS7_AFI_2_S_AXI_BASEADDR 0xF800A000
#define XPAR_PS7_AFI_2_S_AXI_HIGHADDR 0xF800AFFF


/* Definitions for peripheral PS7_AFI_3 */
#define XPAR_PS7_AFI_3_S_AXI_BASEADDR 0xF800B000
#define XPAR_PS7_AFI_3_S_AXI_HIGHADDR 0xF800BFFF


/* Definitions for peripheral PS7_DDRC_0 */
#define XPAR_PS7_DDRC_0_S_AXI_BASEADDR 0xF8006000
#define XPAR_PS7_DDRC_0_S_AXI_HIGHADDR 0xF8006FFF


/* Definitions for peripheral PS7_GLOBALTIMER_0 */
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_BASEADDR 0xF8F00200
#define XPAR_PS7_GLOBALTIMER_0_S_AXI_HIGHADDR 0xF8F002FF


/* Definitions for peripheral PS7_GPV_0 */
#define XPAR_PS7_GPV_0_S_AXI_BASEADDR 0xF8900000
#define XPAR_PS7_GPV_0_S_AXI_HIGHADDR 0xF89FFFFF


/* Definitions for peripheral PS7_INTC_DIST_0 */
#define XPAR_PS7_INTC_DIST_0_S_AXI_BASEADDR 0xF8F01000
#define XPAR_PS7_INTC_DIST_0_S_AXI_HIGHADDR 0xF8F01FFF


/* Definitions for peripheral PS7_IOP_BUS_CONFIG_0 */
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_BASEADDR 0xE0200000
#define XPAR_PS7_IOP_BUS_CONFIG_0_S_AXI_HIGHADDR 0xE0200FFF


/* Definitions for peripheral PS7_L2CACHEC_0 */
#define XPAR_PS7_L2CACHEC_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_L2CACHEC_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_OCMC_0 */
#define XPAR_PS7_OCMC_0_S_AXI_BASEADDR 0xF800C000
#define XPAR_PS7_OCMC_0_S_AXI_HIGHADDR 0xF800CFFF


/* Definitions for peripheral PS7_PL310_0 */
#define XPAR_PS7_PL310_0_S_AXI_BASEADDR 0xF8F02000
#define XPAR_PS7_PL310_0_S_AXI_HIGHADDR 0xF8F02FFF


/* Definitions for peripheral PS7_PMU_0 */
#define XPAR_PS7_PMU_0_S_AXI_BASEADDR 0xF8891000
#define XPAR_PS7_PMU_0_S_AXI_HIGHADDR 0xF8891FFF
#define XPAR_PS7_PMU_0_PMU1_S_AXI_BASEADDR 0xF8893000
#define XPAR_PS7_PMU_0_PMU1_S_AXI_HIGHADDR 0xF8893FFF


/* Definitions for peripheral PS7_QSPI_LINEAR_0 */
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_BASEADDR 0xFC000000
#define XPAR_PS7_QSPI_LINEAR_0_S_AXI_HIGHADDR 0xFCFFFFFF


/* Definitions for peripheral PS7_RAM_0 */
#define XPAR_PS7_RAM_0_S_AXI_BASEADDR 0x00000000
#define XPAR_PS7_RAM_0_S_AXI_HIGHADDR 0x0003FFFF


/* Definitions for peripheral PS7_RAM_1 */
#define XPAR_PS7_RAM_1_S_AXI_BASEADDR 0xFFFC0000
#define XPAR_PS7_RAM_1_S_AXI_HIGHADDR 0xFFFFFFFF


/* Definitions for peripheral PS7_SCUC_0 */
#define XPAR_PS7_SCUC_0_S_AXI_BASEADDR 0xF8F00000
#define XPAR_PS7_SCUC_0_S_AXI_HIGHADDR 0xF8F000FC


/* Definitions for peripheral PS7_SLCR_0 */
#define XPAR_PS7_SLCR_0_S_AXI_BASEADDR 0xF8000000
#define XPAR_PS7_SLCR_0_S_AXI_HIGHADDR 0xF8000FFF


/* Definitions for peripheral XVC_0 */
#define XPAR_XVC_0_S_AXI_BASEADDR 0x43C70000
#define XPAR_XVC_0_S_AXI_HIGHADDR 0x43C7FFFF


/* Definitions for peripheral XADC_WIZ_0 */
#define XPAR_XADC_WIZ_0_BASEADDR 0x43CB0000
#define XPAR_XADC_WIZ_0_HIGHADDR 0x43CBFFFF


/******************************************************************/

/* Definitions for driver GPIO */
#define XPAR_XGPIO_NUM_INSTANCES 2

/* Definitions for peripheral GPIO_AXI_GPIO_0 */
#define XPAR_GPIO_AXI_GPIO_0_BASEADDR 0x41200000
#define XPAR_GPIO_AXI_GPIO_0_HIGHADDR 0x4120FFFF
#define XPAR_GPIO_AXI_GPIO_0_DEVICE_ID 0
#define XPAR_GPIO_AXI_GPIO_0_INTERRUPT_PRESENT 0
#define XPAR_GPIO_AXI_GPIO_0_IS_DUAL 1


/* Definitions for peripheral MANAGEMENT_AXI_GPIO_0 */
#define XPAR_MANAGEMENT_AXI_GPIO_0_BASEADDR 0x41210000
#define XPAR_MANAGEMENT_AXI_GPIO_0_HIGHADDR 0x4121FFFF
#define XPAR_MANAGEMENT_AXI_GPIO_0_DEVICE_ID 1
#define XPAR_MANAGEMENT_AXI_GPIO_0_INTERRUPT_PRESENT 0
#define XPAR_MANAGEMENT_AXI_GPIO_0_IS_DUAL 1


/******************************************************************/

/* Canonical definitions for peripheral GPIO_AXI_GPIO_0 */
#define XPAR_GPIO_0_BASEADDR 0x41200000
#define XPAR_GPIO_0_HIGHADDR 0x4120FFFF
#define XPAR_GPIO_0_DEVICE_ID XPAR_GPIO_AXI_GPIO_0_DEVICE_ID
#define XPAR_GPIO_0_INTERRUPT_PRESENT 0
#define XPAR_GPIO_0_IS_DUAL 1

/* Canonical definitions for peripheral MANAGEMENT_AXI_GPIO_0 */
#define XPAR_GPIO_1_BASEADDR 0x41210000
#define XPAR_GPIO_1_HIGHADDR 0x4121FFFF
#define XPAR_GPIO_1_DEVICE_ID XPAR_MANAGEMENT_AXI_GPIO_0_DEVICE_ID
#define XPAR_GPIO_1_INTERRUPT_PRESENT 0
#define XPAR_GPIO_1_IS_DUAL 1


/******************************************************************/

/* Definitions for driver GPIOPS */
#define XPAR_XGPIOPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_GPIO_0 */
#define XPAR_PS7_GPIO_0_DEVICE_ID 0
#define XPAR_PS7_GPIO_0_BASEADDR 0xE000A000
#define XPAR_PS7_GPIO_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Canonical definitions for peripheral PS7_GPIO_0 */
#define XPAR_XGPIOPS_0_DEVICE_ID XPAR_PS7_GPIO_0_DEVICE_ID
#define XPAR_XGPIOPS_0_BASEADDR 0xE000A000
#define XPAR_XGPIOPS_0_HIGHADDR 0xE000AFFF


/******************************************************************/

/* Definitions for driver IIC */
#define XPAR_XIIC_NUM_INSTANCES 5

/* Definitions for peripheral AMCS_AMC0_AXI_IIC_0 */
#define XPAR_AMCS_AMC0_AXI_IIC_0_DEVICE_ID 0
#define XPAR_AMCS_AMC0_AXI_IIC_0_BASEADDR 0x41600000
#define XPAR_AMCS_AMC0_AXI_IIC_0_HIGHADDR 0x4160FFFF
#define XPAR_AMCS_AMC0_AXI_IIC_0_TEN_BIT_ADR 0
#define XPAR_AMCS_AMC0_AXI_IIC_0_GPO_WIDTH 1


/* Definitions for peripheral AMCS_AMC1_AXI_IIC_0 */
#define XPAR_AMCS_AMC1_AXI_IIC_0_DEVICE_ID 1
#define XPAR_AMCS_AMC1_AXI_IIC_0_BASEADDR 0x41610000
#define XPAR_AMCS_AMC1_AXI_IIC_0_HIGHADDR 0x4161FFFF
#define XPAR_AMCS_AMC1_AXI_IIC_0_TEN_BIT_ADR 0
#define XPAR_AMCS_AMC1_AXI_IIC_0_GPO_WIDTH 1


/* Definitions for peripheral AMCS_AMC2_AXI_IIC_0 */
#define XPAR_AMCS_AMC2_AXI_IIC_0_DEVICE_ID 2
#define XPAR_AMCS_AMC2_AXI_IIC_0_BASEADDR 0x41620000
#define XPAR_AMCS_AMC2_AXI_IIC_0_HIGHADDR 0x4162FFFF
#define XPAR_AMCS_AMC2_AXI_IIC_0_TEN_BIT_ADR 0
#define XPAR_AMCS_AMC2_AXI_IIC_0_GPO_WIDTH 1


/* Definitions for peripheral AMCS_AMC3_AXI_IIC_0 */
#define XPAR_AMCS_AMC3_AXI_IIC_0_DEVICE_ID 3
#define XPAR_AMCS_AMC3_AXI_IIC_0_BASEADDR 0x41630000
#define XPAR_AMCS_AMC3_AXI_IIC_0_HIGHADDR 0x4163FFFF
#define XPAR_AMCS_AMC3_AXI_IIC_0_TEN_BIT_ADR 0
#define XPAR_AMCS_AMC3_AXI_IIC_0_GPO_WIDTH 1


/* Definitions for peripheral AMCS_AMC4_AXI_IIC_0 */
#define XPAR_AMCS_AMC4_AXI_IIC_0_DEVICE_ID 4
#define XPAR_AMCS_AMC4_AXI_IIC_0_BASEADDR 0x41640000
#define XPAR_AMCS_AMC4_AXI_IIC_0_HIGHADDR 0x4164FFFF
#define XPAR_AMCS_AMC4_AXI_IIC_0_TEN_BIT_ADR 0
#define XPAR_AMCS_AMC4_AXI_IIC_0_GPO_WIDTH 1


/******************************************************************/

/* Canonical definitions for peripheral AMCS_AMC0_AXI_IIC_0 */
#define XPAR_IIC_0_DEVICE_ID XPAR_AMCS_AMC0_AXI_IIC_0_DEVICE_ID
#define XPAR_IIC_0_BASEADDR 0x41600000
#define XPAR_IIC_0_HIGHADDR 0x4160FFFF
#define XPAR_IIC_0_TEN_BIT_ADR 0
#define XPAR_IIC_0_GPO_WIDTH 1

/* Canonical definitions for peripheral AMCS_AMC1_AXI_IIC_0 */
#define XPAR_IIC_1_DEVICE_ID XPAR_AMCS_AMC1_AXI_IIC_0_DEVICE_ID
#define XPAR_IIC_1_BASEADDR 0x41610000
#define XPAR_IIC_1_HIGHADDR 0x4161FFFF
#define XPAR_IIC_1_TEN_BIT_ADR 0
#define XPAR_IIC_1_GPO_WIDTH 1

/* Canonical definitions for peripheral AMCS_AMC2_AXI_IIC_0 */
#define XPAR_IIC_2_DEVICE_ID XPAR_AMCS_AMC2_AXI_IIC_0_DEVICE_ID
#define XPAR_IIC_2_BASEADDR 0x41620000
#define XPAR_IIC_2_HIGHADDR 0x4162FFFF
#define XPAR_IIC_2_TEN_BIT_ADR 0
#define XPAR_IIC_2_GPO_WIDTH 1

/* Canonical definitions for peripheral AMCS_AMC3_AXI_IIC_0 */
#define XPAR_IIC_3_DEVICE_ID XPAR_AMCS_AMC3_AXI_IIC_0_DEVICE_ID
#define XPAR_IIC_3_BASEADDR 0x41630000
#define XPAR_IIC_3_HIGHADDR 0x4163FFFF
#define XPAR_IIC_3_TEN_BIT_ADR 0
#define XPAR_IIC_3_GPO_WIDTH 1

/* Canonical definitions for peripheral AMCS_AMC4_AXI_IIC_0 */
#define XPAR_IIC_4_DEVICE_ID XPAR_AMCS_AMC4_AXI_IIC_0_DEVICE_ID
#define XPAR_IIC_4_BASEADDR 0x41640000
#define XPAR_IIC_4_HIGHADDR 0x4164FFFF
#define XPAR_IIC_4_TEN_BIT_ADR 0
#define XPAR_IIC_4_GPO_WIDTH 1


/******************************************************************/

/* Definitions for driver IICPS */
#define XPAR_XIICPS_NUM_INSTANCES 2

/* Definitions for peripheral PS7_I2C_0 */
#define XPAR_PS7_I2C_0_DEVICE_ID 0
#define XPAR_PS7_I2C_0_BASEADDR 0xE0004000
#define XPAR_PS7_I2C_0_HIGHADDR 0xE0004FFF
#define XPAR_PS7_I2C_0_I2C_CLK_FREQ_HZ 111111115


/* Definitions for peripheral PS7_I2C_1 */
#define XPAR_PS7_I2C_1_DEVICE_ID 1
#define XPAR_PS7_I2C_1_BASEADDR 0xE0005000
#define XPAR_PS7_I2C_1_HIGHADDR 0xE0005FFF
#define XPAR_PS7_I2C_1_I2C_CLK_FREQ_HZ 111111115


/******************************************************************/

/* Canonical definitions for peripheral PS7_I2C_0 */
#define XPAR_XIICPS_0_DEVICE_ID XPAR_PS7_I2C_0_DEVICE_ID
#define XPAR_XIICPS_0_BASEADDR 0xE0004000
#define XPAR_XIICPS_0_HIGHADDR 0xE0004FFF
#define XPAR_XIICPS_0_I2C_CLK_FREQ_HZ 111111115

/* Canonical definitions for peripheral PS7_I2C_1 */
#define XPAR_XIICPS_1_DEVICE_ID XPAR_PS7_I2C_1_DEVICE_ID
#define XPAR_XIICPS_1_BASEADDR 0xE0005000
#define XPAR_XIICPS_1_HIGHADDR 0xE0005FFF
#define XPAR_XIICPS_1_I2C_CLK_FREQ_HZ 111111115


/******************************************************************/

#define XPAR_INTC_MAX_NUM_INTR_INPUTS 27
#define XPAR_XINTC_HAS_IPR 1
#define XPAR_XINTC_HAS_SIE 1
#define XPAR_XINTC_HAS_CIE 1
#define XPAR_XINTC_HAS_IVR 1
/* Definitions for driver INTC */
#define XPAR_XINTC_NUM_INSTANCES 1

/* Definitions for peripheral AXI_INTC_0 */
#define XPAR_AXI_INTC_0_DEVICE_ID 0
#define XPAR_AXI_INTC_0_BASEADDR 0x41800000
#define XPAR_AXI_INTC_0_HIGHADDR 0x4180FFFF
#define XPAR_AXI_INTC_0_KIND_OF_INTR 0xFFFFFFFF
#define XPAR_AXI_INTC_0_HAS_FAST 0
#define XPAR_AXI_INTC_0_IVAR_RESET_VALUE 0x00000010
#define XPAR_AXI_INTC_0_NUM_INTR_INPUTS 27


/******************************************************************/

#define XPAR_INTC_SINGLE_BASEADDR 0x41800000
#define XPAR_INTC_SINGLE_HIGHADDR 0x4180FFFF
#define XPAR_INTC_SINGLE_DEVICE_ID XPAR_AXI_INTC_0_DEVICE_ID
#define XPAR_AXI_INTC_0_TYPE 0
#define XPAR_AD7689_0_IRQ_MASK 0X000001
#define XPAR_AXI_INTC_0_AD7689_0_IRQ_INTR 0
#define XPAR_AD7689_1_IRQ_MASK 0X000002
#define XPAR_AXI_INTC_0_AD7689_1_IRQ_INTR 1
#define XPAR_AMCS_AMC0_AXI_IIC_0_IIC2INTC_IRPT_MASK 0X000004
#define XPAR_AXI_INTC_0_AMCS_AMC0_AXI_IIC_0_IIC2INTC_IRPT_INTR 2
#define XPAR_AMCS_AMC0_TPS2358_0_MC_DETECT_IRQ_MASK 0X000008
#define XPAR_AXI_INTC_0_AMCS_AMC0_TPS2358_0_MC_DETECT_IRQ_INTR 3
#define XPAR_AMCS_AMC0_TPS2358_0_TPS2358_FAULT_IRQ_0_MASK 0X000010
#define XPAR_AXI_INTC_0_AMCS_AMC0_TPS2358_0_TPS2358_FAULT_IRQ_0_INTR 4
#define XPAR_AMCS_AMC0_TPS2358_0_TPS2358_FAULT_IRQ_1_MASK 0X000020
#define XPAR_AXI_INTC_0_AMCS_AMC0_TPS2358_0_TPS2358_FAULT_IRQ_1_INTR 5
#define XPAR_AMCS_AMC1_AXI_IIC_0_IIC2INTC_IRPT_MASK 0X000040
#define XPAR_AXI_INTC_0_AMCS_AMC1_AXI_IIC_0_IIC2INTC_IRPT_INTR 6
#define XPAR_AMCS_AMC1_TPS2358_0_MC_DETECT_IRQ_MASK 0X000080
#define XPAR_AXI_INTC_0_AMCS_AMC1_TPS2358_0_MC_DETECT_IRQ_INTR 7
#define XPAR_AMCS_AMC1_TPS2358_0_TPS2358_FAULT_IRQ_0_MASK 0X000100
#define XPAR_AXI_INTC_0_AMCS_AMC1_TPS2358_0_TPS2358_FAULT_IRQ_0_INTR 8
#define XPAR_AMCS_AMC1_TPS2358_0_TPS2358_FAULT_IRQ_1_MASK 0X000200
#define XPAR_AXI_INTC_0_AMCS_AMC1_TPS2358_0_TPS2358_FAULT_IRQ_1_INTR 9
#define XPAR_AMCS_AMC2_AXI_IIC_0_IIC2INTC_IRPT_MASK 0X000400
#define XPAR_AXI_INTC_0_AMCS_AMC2_AXI_IIC_0_IIC2INTC_IRPT_INTR 10
#define XPAR_AMCS_AMC2_TPS2358_0_MC_DETECT_IRQ_MASK 0X000800
#define XPAR_AXI_INTC_0_AMCS_AMC2_TPS2358_0_MC_DETECT_IRQ_INTR 11
#define XPAR_AMCS_AMC2_TPS2358_0_TPS2358_FAULT_IRQ_0_MASK 0X001000
#define XPAR_AXI_INTC_0_AMCS_AMC2_TPS2358_0_TPS2358_FAULT_IRQ_0_INTR 12
#define XPAR_AMCS_AMC2_TPS2358_0_TPS2358_FAULT_IRQ_1_MASK 0X002000
#define XPAR_AXI_INTC_0_AMCS_AMC2_TPS2358_0_TPS2358_FAULT_IRQ_1_INTR 13
#define XPAR_AMCS_AMC3_AXI_IIC_0_IIC2INTC_IRPT_MASK 0X004000
#define XPAR_AXI_INTC_0_AMCS_AMC3_AXI_IIC_0_IIC2INTC_IRPT_INTR 14
#define XPAR_AMCS_AMC3_TPS2358_0_MC_DETECT_IRQ_MASK 0X008000
#define XPAR_AXI_INTC_0_AMCS_AMC3_TPS2358_0_MC_DETECT_IRQ_INTR 15
#define XPAR_AMCS_AMC3_TPS2358_0_TPS2358_FAULT_IRQ_0_MASK 0X010000
#define XPAR_AXI_INTC_0_AMCS_AMC3_TPS2358_0_TPS2358_FAULT_IRQ_0_INTR 16
#define XPAR_AMCS_AMC3_TPS2358_0_TPS2358_FAULT_IRQ_1_MASK 0X020000
#define XPAR_AXI_INTC_0_AMCS_AMC3_TPS2358_0_TPS2358_FAULT_IRQ_1_INTR 17
#define XPAR_AMCS_AMC4_AXI_IIC_0_IIC2INTC_IRPT_MASK 0X040000
#define XPAR_AXI_INTC_0_AMCS_AMC4_AXI_IIC_0_IIC2INTC_IRPT_INTR 18
#define XPAR_AMCS_AMC4_TPS2358_0_MC_DETECT_IRQ_MASK 0X080000
#define XPAR_AXI_INTC_0_AMCS_AMC4_TPS2358_0_MC_DETECT_IRQ_INTR 19
#define XPAR_AMCS_AMC4_TPS2358_0_TPS2358_FAULT_IRQ_0_MASK 0X100000
#define XPAR_AXI_INTC_0_AMCS_AMC4_TPS2358_0_TPS2358_FAULT_IRQ_0_INTR 20
#define XPAR_AMCS_AMC4_TPS2358_0_TPS2358_FAULT_IRQ_1_MASK 0X200000
#define XPAR_AXI_INTC_0_AMCS_AMC4_TPS2358_0_TPS2358_FAULT_IRQ_1_INTR 21
#define XPAR_MANAGEMENT_DEBOUNCER_0_SIG_OUT_MASK 0X400000
#define XPAR_AXI_INTC_0_MANAGEMENT_DEBOUNCER_0_SIG_OUT_INTR 22
#define XPAR_MANAGEMENT_DEBOUNCER_2_SIG_OUT_MASK 0X800000
#define XPAR_AXI_INTC_0_MANAGEMENT_DEBOUNCER_2_SIG_OUT_INTR 23
#define XPAR_MANAGEMENT_DEBOUNCER_3_SIG_OUT_MASK 0X1000000
#define XPAR_AXI_INTC_0_MANAGEMENT_DEBOUNCER_3_SIG_OUT_INTR 24
#define XPAR_MANAGEMENT_DEBOUNCER_1_SIG_OUT_MASK 0X2000000
#define XPAR_AXI_INTC_0_MANAGEMENT_DEBOUNCER_1_SIG_OUT_INTR 25
#define XPAR_MANAGEMENT_DEBOUNCER_4_SIG_OUT_MASK 0X4000000
#define XPAR_AXI_INTC_0_MANAGEMENT_DEBOUNCER_4_SIG_OUT_INTR 26

/******************************************************************/

/* Canonical definitions for peripheral AXI_INTC_0 */
#define XPAR_INTC_0_DEVICE_ID XPAR_AXI_INTC_0_DEVICE_ID
#define XPAR_INTC_0_BASEADDR 0x41800000
#define XPAR_INTC_0_HIGHADDR 0x4180FFFF
#define XPAR_INTC_0_KIND_OF_INTR 0xFFFFFFFF
#define XPAR_INTC_0_HAS_FAST 0
#define XPAR_INTC_0_IVAR_RESET_VALUE 0x00000010
#define XPAR_INTC_0_NUM_INTR_INPUTS 27
#define XPAR_INTC_0_INTC_TYPE 0

#define XPAR_INTC_0_IIC_0_VEC_ID XPAR_AXI_INTC_0_AMCS_AMC0_AXI_IIC_0_IIC2INTC_IRPT_INTR
#define XPAR_INTC_0_IIC_1_VEC_ID XPAR_AXI_INTC_0_AMCS_AMC1_AXI_IIC_0_IIC2INTC_IRPT_INTR
#define XPAR_INTC_0_IIC_2_VEC_ID XPAR_AXI_INTC_0_AMCS_AMC2_AXI_IIC_0_IIC2INTC_IRPT_INTR
#define XPAR_INTC_0_IIC_3_VEC_ID XPAR_AXI_INTC_0_AMCS_AMC3_AXI_IIC_0_IIC2INTC_IRPT_INTR
#define XPAR_INTC_0_IIC_4_VEC_ID XPAR_AXI_INTC_0_AMCS_AMC4_AXI_IIC_0_IIC2INTC_IRPT_INTR

/******************************************************************/

/* Definitions for driver LED_CONTROLLER */
#define XPAR_LED_CONTROLLER_NUM_INSTANCES 2

/* Definitions for peripheral LED_CONTROLLER_0 */
#define XPAR_LED_CONTROLLER_0_DEVICE_ID 0
#define XPAR_LED_CONTROLLER_0_S_AXI_BASEADDR 0x43C80000
#define XPAR_LED_CONTROLLER_0_S_AXI_HIGHADDR 0x43C8FFFF
#define XPAR_LED_CONTROLLER_0_LED_INTERFACES 2


/* Definitions for peripheral LED_CONTROLLER_1 */
#define XPAR_LED_CONTROLLER_1_DEVICE_ID 1
#define XPAR_LED_CONTROLLER_1_S_AXI_BASEADDR 0x43C90000
#define XPAR_LED_CONTROLLER_1_S_AXI_HIGHADDR 0x43C9FFFF
#define XPAR_LED_CONTROLLER_1_LED_INTERFACES 4


/******************************************************************/


/******************************************************************/

/* Definitions for driver QSPIPS */
#define XPAR_XQSPIPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_QSPI_0 */
#define XPAR_PS7_QSPI_0_DEVICE_ID 0
#define XPAR_PS7_QSPI_0_BASEADDR 0xE000D000
#define XPAR_PS7_QSPI_0_HIGHADDR 0xE000DFFF
#define XPAR_PS7_QSPI_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_PS7_QSPI_0_QSPI_MODE 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_QSPI_0 */
#define XPAR_XQSPIPS_0_DEVICE_ID XPAR_PS7_QSPI_0_DEVICE_ID
#define XPAR_XQSPIPS_0_BASEADDR 0xE000D000
#define XPAR_XQSPIPS_0_HIGHADDR 0xE000DFFF
#define XPAR_XQSPIPS_0_QSPI_CLK_FREQ_HZ 200000000
#define XPAR_XQSPIPS_0_QSPI_MODE 0


/******************************************************************/

/* Definitions for Fabric interrupts connected to ps7_scugic_0 */
#define XPAR_FABRIC_AXI_INTC_0_IRQ_INTR 61U

/******************************************************************/

/* Canonical definitions for Fabric interrupts connected to ps7_scugic_0 */

/******************************************************************/

/* Definitions for driver SCUGIC */
#define XPAR_XSCUGIC_NUM_INSTANCES 1U

/* Definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_PS7_SCUGIC_0_DEVICE_ID 0U
#define XPAR_PS7_SCUGIC_0_BASEADDR 0xF8F00100U
#define XPAR_PS7_SCUGIC_0_HIGHADDR 0xF8F001FFU
#define XPAR_PS7_SCUGIC_0_DIST_BASEADDR 0xF8F01000U


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUGIC_0 */
#define XPAR_SCUGIC_0_DEVICE_ID 0U
#define XPAR_SCUGIC_0_CPU_BASEADDR 0xF8F00100U
#define XPAR_SCUGIC_0_CPU_HIGHADDR 0xF8F001FFU
#define XPAR_SCUGIC_0_DIST_BASEADDR 0xF8F01000U


/******************************************************************/

/* Definitions for driver SCUTIMER */
#define XPAR_XSCUTIMER_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_PS7_SCUTIMER_0_DEVICE_ID 0
#define XPAR_PS7_SCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_PS7_SCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUTIMER_0 */
#define XPAR_XSCUTIMER_0_DEVICE_ID XPAR_PS7_SCUTIMER_0_DEVICE_ID
#define XPAR_XSCUTIMER_0_BASEADDR 0xF8F00600
#define XPAR_XSCUTIMER_0_HIGHADDR 0xF8F0061F


/******************************************************************/

/* Definitions for driver SCUWDT */
#define XPAR_XSCUWDT_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_PS7_SCUWDT_0_DEVICE_ID 0
#define XPAR_PS7_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_PS7_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Canonical definitions for peripheral PS7_SCUWDT_0 */
#define XPAR_SCUWDT_0_DEVICE_ID XPAR_PS7_SCUWDT_0_DEVICE_ID
#define XPAR_SCUWDT_0_BASEADDR 0xF8F00620
#define XPAR_SCUWDT_0_HIGHADDR 0xF8F006FF


/******************************************************************/

/* Definitions for driver SPIPS */
#define XPAR_XSPIPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_SPI_0 */
#define XPAR_PS7_SPI_0_DEVICE_ID 0
#define XPAR_PS7_SPI_0_BASEADDR 0xE0006000
#define XPAR_PS7_SPI_0_HIGHADDR 0xE0006FFF
#define XPAR_PS7_SPI_0_SPI_CLK_FREQ_HZ 166666672


/******************************************************************/

/* Canonical definitions for peripheral PS7_SPI_0 */
#define XPAR_XSPIPS_0_DEVICE_ID XPAR_PS7_SPI_0_DEVICE_ID
#define XPAR_XSPIPS_0_BASEADDR 0xE0006000
#define XPAR_XSPIPS_0_HIGHADDR 0xE0006FFF
#define XPAR_XSPIPS_0_SPI_CLK_FREQ_HZ 166666672


/******************************************************************/

/* Definitions for driver UARTPS */
#define XPAR_XUARTPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_UART_0 */
#define XPAR_PS7_UART_0_DEVICE_ID 0
#define XPAR_PS7_UART_0_BASEADDR 0xE0000000
#define XPAR_PS7_UART_0_HIGHADDR 0xE0000FFF
#define XPAR_PS7_UART_0_UART_CLK_FREQ_HZ 100000000
#define XPAR_PS7_UART_0_HAS_MODEM 0


/******************************************************************/

/* Canonical definitions for peripheral PS7_UART_0 */
#define XPAR_XUARTPS_0_DEVICE_ID XPAR_PS7_UART_0_DEVICE_ID
#define XPAR_XUARTPS_0_BASEADDR 0xE0000000
#define XPAR_XUARTPS_0_HIGHADDR 0xE0000FFF
#define XPAR_XUARTPS_0_UART_CLK_FREQ_HZ 100000000
#define XPAR_XUARTPS_0_HAS_MODEM 0


/******************************************************************/

/* Definitions for driver WDTPS */
#define XPAR_XWDTPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_WDT_0 */
#define XPAR_PS7_WDT_0_DEVICE_ID 0
#define XPAR_PS7_WDT_0_BASEADDR 0xF8005000
#define XPAR_PS7_WDT_0_HIGHADDR 0xF8005FFF
#define XPAR_PS7_WDT_0_WDT_CLK_FREQ_HZ 111111115


/******************************************************************/

/* Canonical definitions for peripheral PS7_WDT_0 */
#define XPAR_XWDTPS_0_DEVICE_ID XPAR_PS7_WDT_0_DEVICE_ID
#define XPAR_XWDTPS_0_BASEADDR 0xF8005000
#define XPAR_XWDTPS_0_HIGHADDR 0xF8005FFF
#define XPAR_XWDTPS_0_WDT_CLK_FREQ_HZ 111111115


/******************************************************************/

/* Definitions for driver XADCPS */
#define XPAR_XADCPS_NUM_INSTANCES 1

/* Definitions for peripheral PS7_XADC_0 */
#define XPAR_PS7_XADC_0_DEVICE_ID 0
#define XPAR_PS7_XADC_0_BASEADDR 0xF8007100
#define XPAR_PS7_XADC_0_HIGHADDR 0xF8007120


/******************************************************************/

/* Canonical definitions for peripheral PS7_XADC_0 */
#define XPAR_XADCPS_0_DEVICE_ID XPAR_PS7_XADC_0_DEVICE_ID
#define XPAR_XADCPS_0_BASEADDR 0xF8007100
#define XPAR_XADCPS_0_HIGHADDR 0xF8007120


/******************************************************************/

#endif  /* end of protection macro */