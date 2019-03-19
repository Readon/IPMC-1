set_property PACKAGE_PIN P19 [get_ports DAC_SPI_io0_io]

############################################################
# Clock Period Constraints                                 #
############################################################

set_property IOSTANDARD LVCMOS33 [get_ports ADC_B_spi_clk]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_B_spi_miso]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_B_spi_mosi]
set_property IOSTANDARD LVCMOS33 [get_ports {ADC_B_spi_ncs[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_A_spi_clk]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_A_spi_miso]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_A_spi_mosi]
set_property IOSTANDARD LVCMOS33 [get_ports {ADC_A_spi_ncs[0]}]


set_input_delay -clock [get_clocks clk_fpga_0] -min -add_delay 15.000 [get_ports ADC_A_spi_miso]
set_input_delay -clock [get_clocks clk_fpga_0] -max -add_delay 15.000 [get_ports ADC_A_spi_miso]
set_input_delay -clock [get_clocks clk_fpga_0] -min -add_delay 15.000 [get_ports ADC_B_spi_miso]
set_input_delay -clock [get_clocks clk_fpga_0] -max -add_delay 15.000 [get_ports ADC_B_spi_miso]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports ADC_A_spi_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports ADC_A_spi_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports ADC_A_spi_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports ADC_A_spi_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports {ADC_A_spi_ncs[0]}]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports {ADC_A_spi_ncs[0]}]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports ADC_B_spi_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports ADC_B_spi_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports ADC_B_spi_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports ADC_B_spi_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports {ADC_B_spi_ncs[0]}]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports {ADC_B_spi_ncs[0]}]

set_property PACKAGE_PIN Y9 [get_ports ADC_B_spi_miso]
set_property PACKAGE_PIN Y8 [get_ports ADC_B_spi_mosi]
set_property PACKAGE_PIN Y6 [get_ports {ADC_B_spi_ncs[0]}]
set_property PACKAGE_PIN T9 [get_ports ADC_A_spi_miso]
set_property PACKAGE_PIN U10 [get_ports ADC_A_spi_mosi]
set_property PACKAGE_PIN V7 [get_ports {ADC_A_spi_ncs[0]}]
set_property PACKAGE_PIN Y7 [get_ports ADC_B_spi_clk]
set_property PACKAGE_PIN U7 [get_ports ADC_A_spi_clk]
set_property PACKAGE_PIN V5 [get_ports {PL_LEDS[0]}]
set_property PACKAGE_PIN V8 [get_ports {PL_LEDS[1]}]

set_property PACKAGE_PIN F16 [get_ports {ATCA_LEDS[0]}]
set_property PACKAGE_PIN F17 [get_ports {ATCA_LEDS[1]}]
set_property PACKAGE_PIN D18 [get_ports {ATCA_LEDS[2]}]
set_property PACKAGE_PIN D19 [get_ports {ATCA_LEDS[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PL_LEDS[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PL_LEDS[0]}]

set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[0]}]
set_property SLEW FAST [get_ports ADC_B_spi_clk]
set_property SLEW FAST [get_ports ADC_A_spi_clk]
set_property SLEW FAST [get_ports {ADC_A_spi_ncs[0]}]
set_property SLEW FAST [get_ports ADC_A_spi_mosi]
set_property SLEW FAST [get_ports ADC_B_spi_mosi]
set_property SLEW FAST [get_ports {ADC_B_spi_ncs[0]}]

set_property PACKAGE_PIN B20 [get_ports TCK]
set_property IOSTANDARD LVCMOS33 [get_ports TCK]
set_property SLEW FAST [get_ports TCK]
set_property PACKAGE_PIN E17 [get_ports TDI]
set_property IOSTANDARD LVCMOS33 [get_ports TDI]
set_property SLEW FAST [get_ports TDI]
set_property PACKAGE_PIN A20 [get_ports TDO]
set_property IOSTANDARD LVCMOS33 [get_ports TDO]
set_property PACKAGE_PIN B19 [get_ports TMS]
set_property IOSTANDARD LVCMOS33 [get_ports TMS]

set_property SLEW FAST [get_ports TMS]
set_property DRIVE 12 [get_ports TCK]

set_property IOSTANDARD LVCMOS33 [get_ports ESM_UART_rxd]
set_property IOSTANDARD LVCMOS33 [get_ports ESM_UART_txd]


set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_IN_tri_i[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_IN_tri_i[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_IN_tri_i[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_IN_tri_i[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_IN_tri_i[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_IN_tri_i[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_IN_tri_i[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_IN_tri_i[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ESM_RESET_tri_io[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ESM_RESET_tri_io[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_tri_io[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_tri_io[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_tri_io[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO_OUT_tri_io[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports PIM400_I2C_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports PIM400_I2C_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports {ESM_FLASH_SPI_ss_io[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports ESM_FLASH_SPI_io0_io]
set_property IOSTANDARD LVCMOS33 [get_ports ESM_FLASH_SPI_io1_io]
set_property IOSTANDARD LVCMOS33 [get_ports ESM_FLASH_SPI_sck_io]
set_property PACKAGE_PIN G18 [get_ports PIM400_I2C_scl_io]
set_property PACKAGE_PIN G19 [get_ports PIM400_I2C_sda_io]
set_property PACKAGE_PIN U14 [get_ports {ESM_RESET_tri_io[1]}]
set_property PACKAGE_PIN Y16 [get_ports {ESM_RESET_tri_io[0]}]
set_property PACKAGE_PIN V13 [get_ports ESM_UART_txd]
set_property PACKAGE_PIN W18 [get_ports ESM_UART_rxd]
set_property PACKAGE_PIN V11 [get_ports {GPIO_IN_tri_i[0]}]
set_property PACKAGE_PIN N17 [get_ports {GPIO_IN_tri_i[1]}]
set_property PACKAGE_PIN P18 [get_ports {GPIO_IN_tri_i[2]}]
set_property PACKAGE_PIN P15 [get_ports {GPIO_IN_tri_i[3]}]
set_property PACKAGE_PIN P16 [get_ports {GPIO_IN_tri_i[4]}]
set_property PACKAGE_PIN T19 [get_ports {GPIO_IN_tri_i[5]}]
set_property PACKAGE_PIN R19 [get_ports {GPIO_IN_tri_i[6]}]
set_property PACKAGE_PIN E18 [get_ports {GPIO_IN_tri_i[7]}]
set_property PACKAGE_PIN N20 [get_ports {GPIO_OUT_tri_io[0]}]
set_property PACKAGE_PIN Y17 [get_ports {GPIO_OUT_tri_io[1]}]
set_property PACKAGE_PIN W20 [get_ports {GPIO_OUT_tri_io[2]}]
set_property PACKAGE_PIN J14 [get_ports {GPIO_OUT_tri_io[3]}]
set_property PACKAGE_PIN V16 [get_ports ESM_FLASH_SPI_io0_io]
set_property PACKAGE_PIN Y18 [get_ports ESM_FLASH_SPI_io1_io]
set_property PACKAGE_PIN V17 [get_ports ESM_FLASH_SPI_sck_io]
set_property PACKAGE_PIN T17 [get_ports {ESM_FLASH_SPI_ss_io[0]}]

set_property PACKAGE_PIN U15 [get_ports {DAC_SPI_ss_io[0]}]
set_property PACKAGE_PIN N18 [get_ports DAC_SPI_io1_io]
set_property PACKAGE_PIN U18 [get_ports DAC_SPI_sck_io]
set_property IOSTANDARD LVCMOS33 [get_ports {DAC_SPI_ss_io[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports DAC_SPI_io0_io]
set_property IOSTANDARD LVCMOS33 [get_ports DAC_SPI_io1_io]
set_property IOSTANDARD LVCMOS33 [get_ports DAC_SPI_sck_io]

set_property IOSTANDARD LVCMOS33 [get_ports {ADC_APD_0_spi_ncs[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ADC_APD_0_spi_ncs[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ADC_APD_0_spi_ncs[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_APD_0_spi_clk]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_APD_0_spi_miso]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_APD_0_spi_mosi]
set_property SLEW FAST [get_ports {ADC_APD_0_spi_ncs[2]}]
set_property SLEW FAST [get_ports {ADC_APD_0_spi_ncs[1]}]
set_property SLEW FAST [get_ports {ADC_APD_0_spi_ncs[0]}]
set_property SLEW FAST [get_ports ADC_APD_0_spi_clk]
set_property PACKAGE_PIN T15 [get_ports {ADC_APD_0_spi_ncs[0]}]
set_property PACKAGE_PIN V12 [get_ports {ADC_APD_0_spi_ncs[1]}]
set_property PACKAGE_PIN W13 [get_ports {ADC_APD_0_spi_ncs[2]}]
set_property PACKAGE_PIN T12 [get_ports ADC_APD_0_spi_clk]
set_property PACKAGE_PIN U12 [get_ports ADC_APD_0_spi_miso]
set_property PACKAGE_PIN T14 [get_ports ADC_APD_0_spi_mosi]

set_input_delay -clock [get_clocks clk_fpga_0] -min -add_delay 15.000 [get_ports ADC_APD_0_spi_miso]
set_input_delay -clock [get_clocks clk_fpga_0] -max -add_delay 15.000 [get_ports ADC_APD_0_spi_miso]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports ADC_APD_0_spi_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports ADC_APD_0_spi_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports ADC_APD_0_spi_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports ADC_APD_0_spi_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 10.000 [get_ports {ADC_APD_0_spi_ncs[*]}]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 10.000 [get_ports {ADC_APD_0_spi_ncs[*]}]

set_property BITSTREAM.CONFIG.UNUSEDPIN PULLNONE [current_design]
set_property DRIVE 4 [get_ports {GPIO_OUT_tri_io[3]}]
set_property DRIVE 4 [get_ports {GPIO_OUT_tri_io[2]}]
set_property DRIVE 4 [get_ports {GPIO_OUT_tri_io[1]}]
set_property DRIVE 4 [get_ports {GPIO_OUT_tri_io[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[13]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[12]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[11]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[10]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[9]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[8]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PWREN[0]}]
set_property DRIVE 4 [get_ports {PWREN[13]}]
set_property DRIVE 4 [get_ports {PWREN[12]}]
set_property DRIVE 4 [get_ports {PWREN[11]}]
set_property DRIVE 4 [get_ports {PWREN[10]}]
set_property DRIVE 4 [get_ports {PWREN[9]}]
set_property DRIVE 4 [get_ports {PWREN[8]}]
set_property DRIVE 4 [get_ports {PWREN[7]}]
set_property DRIVE 4 [get_ports {PWREN[6]}]
set_property DRIVE 4 [get_ports {PWREN[5]}]
set_property DRIVE 4 [get_ports {PWREN[4]}]
set_property DRIVE 4 [get_ports {PWREN[3]}]
set_property DRIVE 4 [get_ports {PWREN[2]}]
set_property DRIVE 4 [get_ports {PWREN[1]}]
set_property DRIVE 4 [get_ports {PWREN[0]}]
set_property PACKAGE_PIN F20 [get_ports {PWREN[0]}]
set_property PACKAGE_PIN G15 [get_ports {PWREN[1]}]
set_property PACKAGE_PIN H16 [get_ports {PWREN[2]}]
set_property PACKAGE_PIN H18 [get_ports {PWREN[3]}]
set_property PACKAGE_PIN H20 [get_ports {PWREN[4]}]
set_property PACKAGE_PIN J15 [get_ports {PWREN[5]}]
set_property PACKAGE_PIN K19 [get_ports {PWREN[6]}]
set_property PACKAGE_PIN G14 [get_ports {PWREN[7]}]
set_property PACKAGE_PIN K16 [get_ports {PWREN[8]}]
set_property PACKAGE_PIN L19 [get_ports {PWREN[9]}]
set_property PACKAGE_PIN L17 [get_ports {PWREN[10]}]
set_property PACKAGE_PIN V10 [get_ports {PWREN[11]}]
set_property PACKAGE_PIN W9 [get_ports {PWREN[12]}]
set_property PACKAGE_PIN W8 [get_ports {PWREN[13]}]

set_property IOSTANDARD LVCMOS33 [get_ports HNDL_SW]
set_property PACKAGE_PIN G20 [get_ports HNDL_SW]

set_property OFFCHIP_TERM NONE [get_ports ELM_LINK_tri_io[5]]
set_property OFFCHIP_TERM NONE [get_ports ELM_LINK_tri_io[4]]
set_property IOSTANDARD LVCMOS33 [get_ports ELM_UART_rxd]
set_property IOSTANDARD LVCMOS33 [get_ports ELM_UART_txd]
set_property PACKAGE_PIN K18 [get_ports ELM_UART_rxd]
set_property PACKAGE_PIN K17 [get_ports ELM_UART_txd]
set_property IOSTANDARD LVCMOS33 [get_ports {ELM_BOOT_tri_io[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ELM_BOOT_tri_io[0]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ELM_LINK_tri_io[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ELM_LINK_tri_io[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ELM_LINK_tri_io[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ELM_LINK_tri_io[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ELM_LINK_tri_io[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ELM_LINK_tri_io[0]}]
set_property PACKAGE_PIN K14 [get_ports {ELM_LINK_tri_io[0]}]
set_property PACKAGE_PIN L20 [get_ports {ELM_LINK_tri_io[1]}]
set_property PACKAGE_PIN L16 [get_ports {ELM_LINK_tri_io[2]}]
set_property PACKAGE_PIN L14 [get_ports {ELM_LINK_tri_io[3]}]
set_property PACKAGE_PIN R17 [get_ports {ELM_BOOT_tri_io[0]}]
set_property PACKAGE_PIN R18 [get_ports {ELM_BOOT_tri_io[1]}]

set_property IOSTANDARD LVCMOS33 [get_ports LLUT_PRESENCE]
set_property PACKAGE_PIN V15 [get_ports LLUT_PRESENCE]
set_property PACKAGE_PIN P14 [get_ports RTM_HNDL_SW]
set_property IOSTANDARD LVCMOS33 [get_ports RTM_HNDL_SW]
set_property PACKAGE_PIN R14 [get_ports {ATCA_LEDS[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[4]}]

set_property IOSTANDARD LVCMOS33 [get_ports {XVCTARGET_tri_o[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {XVCTARGET_tri_o[0]}]
set_property DRIVE 12 [get_ports {XVCTARGET_tri_o[1]}]
set_property DRIVE 12 [get_ports {XVCTARGET_tri_o[0]}]
set_property PACKAGE_PIN J16 [get_ports {XVCTARGET_tri_o[0]}]
set_property PACKAGE_PIN J20 [get_ports {XVCTARGET_tri_o[1]}]

connect_debug_port u_ila_0/probe0 [get_nets [list {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[0]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[1]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[2]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[3]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[4]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[5]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[6]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[7]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[8]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[9]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[10]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[11]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[12]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[13]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[14]} {ipmc_bd_i/ad7689_s_0/U0/ad7689_spi_intf_inst/t_cnv_value[15]}]]
connect_debug_port u_ila_0/probe1 [get_nets [list {ipmc_bd_i/ad7689_s_0/U0/t_cnv_channel[0]} {ipmc_bd_i/ad7689_s_0/U0/t_cnv_channel[1]} {ipmc_bd_i/ad7689_s_0/U0/t_cnv_channel[2]} {ipmc_bd_i/ad7689_s_0/U0/t_cnv_channel[3]}]]
connect_debug_port u_ila_0/probe2 [get_nets [list {ipmc_bd_i/ad7689_s_0/U0/s_adc_override_en[0]} {ipmc_bd_i/ad7689_s_0/U0/s_adc_override_en[1]} {ipmc_bd_i/ad7689_s_0/U0/s_adc_override_en[2]} {ipmc_bd_i/ad7689_s_0/U0/s_adc_override_en[3]} {ipmc_bd_i/ad7689_s_0/U0/s_adc_override_en[4]} {ipmc_bd_i/ad7689_s_0/U0/s_adc_override_en[5]} {ipmc_bd_i/ad7689_s_0/U0/s_adc_override_en[6]} {ipmc_bd_i/ad7689_s_0/U0/s_adc_override_en[7]}]]
connect_debug_port u_ila_0/probe4 [get_nets [list ipmc_bd_i/ad7689_s_0/U0/t_cnv_done]]



set_property OFFCHIP_TERM NONE [get_ports ADC_APD_0_spi_clk]
set_property OFFCHIP_TERM NONE [get_ports ADC_APD_0_spi_mosi]
set_property OFFCHIP_TERM NONE [get_ports ADC_A_spi_clk]
set_property OFFCHIP_TERM NONE [get_ports ADC_A_spi_mosi]
set_property OFFCHIP_TERM NONE [get_ports ADC_B_spi_clk]
set_property OFFCHIP_TERM NONE [get_ports ADC_B_spi_mosi]
set_property OFFCHIP_TERM NONE [get_ports DAC_SPI_io0_io]
set_property OFFCHIP_TERM NONE [get_ports DAC_SPI_io1_io]
set_property OFFCHIP_TERM NONE [get_ports DAC_SPI_sck_io]
set_property OFFCHIP_TERM NONE [get_ports ELM_UART_txd]
set_property OFFCHIP_TERM NONE [get_ports ESM_FLASH_SPI_io0_io]
set_property OFFCHIP_TERM NONE [get_ports ESM_FLASH_SPI_io1_io]
set_property OFFCHIP_TERM NONE [get_ports ESM_FLASH_SPI_sck_io]
set_property OFFCHIP_TERM NONE [get_ports ESM_UART_txd]
set_property OFFCHIP_TERM NONE [get_ports PIM400_I2C_scl_io]
set_property OFFCHIP_TERM NONE [get_ports PIM400_I2C_sda_io]
set_property OFFCHIP_TERM NONE [get_ports TCK]
set_property OFFCHIP_TERM NONE [get_ports TDI]
set_property OFFCHIP_TERM NONE [get_ports TMS]
set_property OFFCHIP_TERM NONE [get_ports ADC_APD_0_spi_ncs[2]]
set_property OFFCHIP_TERM NONE [get_ports ADC_APD_0_spi_ncs[1]]
set_property OFFCHIP_TERM NONE [get_ports ADC_APD_0_spi_ncs[0]]
set_property OFFCHIP_TERM NONE [get_ports ADC_A_spi_ncs[0]]
set_property OFFCHIP_TERM NONE [get_ports ADC_B_spi_ncs[0]]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[4]]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[3]]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[2]]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[1]]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[0]]
set_property OFFCHIP_TERM NONE [get_ports DAC_SPI_ss_io[0]]
set_property OFFCHIP_TERM NONE [get_ports ELM_BOOT_tri_io[1]]
set_property OFFCHIP_TERM NONE [get_ports ELM_BOOT_tri_io[0]]
set_property OFFCHIP_TERM NONE [get_ports ELM_LINK_tri_io[3]]
set_property OFFCHIP_TERM NONE [get_ports ELM_LINK_tri_io[2]]
set_property OFFCHIP_TERM NONE [get_ports ELM_LINK_tri_io[1]]
set_property OFFCHIP_TERM NONE [get_ports ELM_LINK_tri_io[0]]
set_property OFFCHIP_TERM NONE [get_ports ESM_FLASH_SPI_ss_io[0]]
set_property OFFCHIP_TERM NONE [get_ports ESM_RESET_tri_io[1]]
set_property OFFCHIP_TERM NONE [get_ports ESM_RESET_tri_io[0]]
set_property OFFCHIP_TERM NONE [get_ports PL_LEDS[1]]
set_property OFFCHIP_TERM NONE [get_ports PL_LEDS[0]]
set_property OFFCHIP_TERM NONE [get_ports XVCTARGET_tri_o[1]]
set_property OFFCHIP_TERM NONE [get_ports XVCTARGET_tri_o[0]]
set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets clk]
