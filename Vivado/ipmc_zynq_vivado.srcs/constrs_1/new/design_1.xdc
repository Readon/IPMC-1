
############################################################
# Clock Period Constraints                                 #
############################################################




# False path constraints to async inputs coming directly to synchronizer


set_property IOSTANDARD LVCMOS33 [get_ports {pwr_status[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_status[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_status[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_status[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_status[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_status[0]}]


#PGOOD_2V5ETH, GPIO47
set_property PACKAGE_PIN G18 [get_ports {pwr_status[0]}]

#PGOOD_1V0ETH, GPIO48
set_property PACKAGE_PIN G19 [get_ports {pwr_status[1]}]

#PGOOD_3V3PYLD, GPIO21
set_property PACKAGE_PIN M20 [get_ports {pwr_status[2]}]

#PGOOD_5V0PYLD, GPIO23
set_property PACKAGE_PIN L15 [get_ports {pwr_status[3]}]

#PGOOD_1V2PHY, GPIO8
set_property PACKAGE_PIN N17 [get_ports {pwr_status[4]}]

#ELM_PFAIL, GPIO3
set_property PACKAGE_PIN V11 [get_ports {pwr_status[5]}]




set_property IOSTANDARD LVCMOS33 [get_ports {pwr_en[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_en[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_en[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_en[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_en[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_en[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {pwr_en[0]}]

#ELM_PWR_EN, GPIO2
set_property PACKAGE_PIN V10 [get_ports {pwr_en[6]}]

#PWREN_1V2PHY, GPIO10
set_property PACKAGE_PIN P15 [get_ports {pwr_en[5]}]

#PWREN_5V0PYLD, GPIO14
set_property PACKAGE_PIN N15 [get_ports {pwr_en[4]}]

#PWREN_3V3PYLD, GPIO15
set_property PACKAGE_PIN N16 [get_ports {pwr_en[3]}]

#PWREN_1V0ETH, GPIO13
set_property PACKAGE_PIN R19 [get_ports {pwr_en[2]}]

#PWREN_2V5ETH, GPIO12
set_property PACKAGE_PIN T19 [get_ports {pwr_en[1]}]

#PYLD_12V_EN
set_property PACKAGE_PIN F20 [get_ports {pwr_en[0]}]


set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[31]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[30]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[29]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[28]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[27]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[26]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[25]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[24]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[23]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[22]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[21]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[20]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[19]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[18]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[17]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[16]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[15]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[14]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[13]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[12]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[11]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[10]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[9]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[8]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[7]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[6]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[5]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[4]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {GPIO[0]}]

set_property PACKAGE_PIN W6 [get_ports {GPIO[0]}]
set_property PACKAGE_PIN V6 [get_ports {GPIO[1]}]

# remapped from GPIO_32
set_property PACKAGE_PIN K18 [get_ports {GPIO[2]}]

# remapped from GPIO_41
set_property PACKAGE_PIN H18 [get_ports {GPIO[3]}]

set_property PACKAGE_PIN Y13 [get_ports {GPIO[4]}]

# remapped from GPIO_33
set_property PACKAGE_PIN G14 [get_ports {GPIO[13]}]
set_property PACKAGE_PIN R16 [get_ports {GPIO[5]}]
set_property PACKAGE_PIN R17 [get_ports {GPIO[6]}]
set_property PACKAGE_PIN R18 [get_ports {GPIO[7]}]

# remapped from GPIO_38
set_property PACKAGE_PIN J20 [get_ports {GPIO[8]}]
set_property PACKAGE_PIN P18 [get_ports {GPIO[9]}]

# remapped from GPIO_34
set_property PACKAGE_PIN J19 [get_ports {GPIO[10]}]
set_property PACKAGE_PIN P16 [get_ports {GPIO[11]}]

# remapped from GPIO_35
set_property PACKAGE_PIN K19 [get_ports {GPIO[12]}]

# remapped from GPIO_36
set_property PACKAGE_PIN J16 [get_ports {GPIO[14]}]

# remapped from GPIO_37
set_property PACKAGE_PIN J15 [get_ports {GPIO[15]}]

set_property PACKAGE_PIN M14 [get_ports {GPIO[16]}]
set_property PACKAGE_PIN M15 [get_ports {GPIO[17]}]
set_property PACKAGE_PIN M17 [get_ports {GPIO[18]}]
set_property PACKAGE_PIN M18 [get_ports {GPIO[19]}]
set_property PACKAGE_PIN M19 [get_ports {GPIO[20]}]

# remapped from GPIO_39
set_property PACKAGE_PIN H20 [get_ports {GPIO[21]}]

set_property PACKAGE_PIN L14 [get_ports {GPIO[22]}]

# remapped from GPIO_40
set_property PACKAGE_PIN J18 [get_ports {GPIO[23]}]
set_property PACKAGE_PIN L16 [get_ports {GPIO[24]}]
set_property PACKAGE_PIN L17 [get_ports {GPIO[25]}]
set_property PACKAGE_PIN L20 [get_ports {GPIO[26]}]
set_property PACKAGE_PIN L19 [get_ports {GPIO[27]}]
set_property PACKAGE_PIN K14 [get_ports {GPIO[28]}]
set_property PACKAGE_PIN J14 [get_ports {GPIO[29]}]
set_property PACKAGE_PIN K17 [get_ports {GPIO[30]}]
set_property PACKAGE_PIN K16 [get_ports {GPIO[31]}]
#set_property PACKAGE_PIN K18 [get_ports {GPIO[32]}]
#set_property PACKAGE_PIN G14 [get_ports {GPIO[33]}]
#set_property PACKAGE_PIN J19 [get_ports {GPIO[34]}]
#set_property PACKAGE_PIN K19 [get_ports {GPIO[35]}]
#set_property PACKAGE_PIN J16 [get_ports {GPIO[36]}]
#set_property PACKAGE_PIN J15 [get_ports {GPIO[37]}]
#set_property PACKAGE_PIN J20 [get_ports {GPIO[38]}]
#set_property PACKAGE_PIN H20 [get_ports {GPIO[39]}]
#set_property PACKAGE_PIN J18 [get_ports {GPIO[40]}]
#set_property PACKAGE_PIN H18 [get_ports {GPIO[41]}]
#set_property PACKAGE_PIN H17 [get_ports {GPIO[42]}]
#set_property PACKAGE_PIN H16 [get_ports {GPIO[43]}]
#set_property PACKAGE_PIN H15 [get_ports {GPIO[44]}]
#set_property PACKAGE_PIN G15 [get_ports {GPIO[45]}]
#set_property PACKAGE_PIN G17 [get_ports {GPIO[46]}]
#set_property PACKAGE_PIN G18 [get_ports {GPIO[47]}]
#set_property PACKAGE_PIN G19 [get_ports {GPIO[48]}]

set_property IOSTANDARD LVCMOS33 [get_ports ADC_B_clk]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_B_miso]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_B_mosi]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_B_ncs0]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_A_clk]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_A_miso]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_A_mosi]
set_property IOSTANDARD LVCMOS33 [get_ports ADC_A_ncs0]


set_input_delay -clock [get_clocks clk_fpga_0] -min -add_delay 5.000 [get_ports ADC_A_miso]
set_input_delay -clock [get_clocks clk_fpga_0] -max -add_delay 15.000 [get_ports ADC_A_miso]
set_input_delay -clock [get_clocks clk_fpga_0] -min -add_delay 5.000 [get_ports ADC_B_miso]
set_input_delay -clock [get_clocks clk_fpga_0] -max -add_delay 15.000 [get_ports ADC_B_miso]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 5.000 [get_ports ADC_A_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 5.000 [get_ports ADC_A_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 5.000 [get_ports ADC_A_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 5.000 [get_ports ADC_A_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 5.000 [get_ports ADC_A_ncs0]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 5.000 [get_ports ADC_A_ncs0]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 5.000 [get_ports ADC_B_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 5.000 [get_ports ADC_B_clk]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 5.000 [get_ports ADC_B_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 5.000 [get_ports ADC_B_mosi]
set_output_delay -clock [get_clocks clk_fpga_0] -min -add_delay 5.000 [get_ports ADC_B_ncs0]
set_output_delay -clock [get_clocks clk_fpga_0] -max -add_delay 5.000 [get_ports ADC_B_ncs0]

set_property IOSTANDARD LVCMOS33 [get_ports I2C_0_scl]

set_property IOSTANDARD LVCMOS33 [get_ports I2C_0_sda]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_0_mp_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_0_mp_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_0_mp_pg_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_0_pwr_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_0_pwr_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_0_pwr_pg_n]

set_property IOSTANDARD LVCMOS33 [get_ports I2C_1_scl]
set_property IOSTANDARD LVCMOS33 [get_ports I2C_1_sda]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_1_mp_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_1_mp_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_1_mp_pg_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_1_pwr_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_1_pwr_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_1_pwr_pg_n]

set_property PACKAGE_PIN Y18 [get_ports I2C_3_sda]
set_property PACKAGE_PIN T17 [get_ports I2C_3_scl]
set_property IOSTANDARD LVCMOS33 [get_ports I2C_3_scl]
set_property IOSTANDARD LVCMOS33 [get_ports I2C_3_sda]
set_property PACKAGE_PIN U9 [get_ports I2C_0_sda]
set_property PACKAGE_PIN U8 [get_ports I2C_0_scl]
set_property PACKAGE_PIN P19 [get_ports I2C_4_scl]
set_property PACKAGE_PIN N18 [get_ports I2C_4_sda]
set_property IOSTANDARD LVCMOS33 [get_ports I2C_4_scl]
set_property IOSTANDARD LVCMOS33 [get_ports I2C_4_sda]
set_property PACKAGE_PIN T11 [get_ports I2C_1_scl]
set_property PACKAGE_PIN T12 [get_ports I2C_1_sda]
set_property PACKAGE_PIN T16 [get_ports I2C_2_scl]
set_property PACKAGE_PIN U17 [get_ports I2C_2_sda]
set_property IOSTANDARD LVCMOS33 [get_ports I2C_2_scl]
set_property IOSTANDARD LVCMOS33 [get_ports I2C_2_sda]
set_property PACKAGE_PIN W15 [get_ports MC_2_enable_n]
set_property PACKAGE_PIN R14 [get_ports MC_2_ps1_n]
set_property PACKAGE_PIN P14 [get_ports MC_1_ps1_n]
set_property PACKAGE_PIN T10 [get_ports MC_1_enable_n]
set_property PACKAGE_PIN U5 [get_ports MC_0_ps1_n]
set_property PACKAGE_PIN T5 [get_ports MC_0_enable_n]
set_property PACKAGE_PIN U15 [get_ports MC_4_ps1_n]
set_property PACKAGE_PIN U18 [get_ports MC_4_enable_n]
set_property PACKAGE_PIN V16 [get_ports MC_3_enable_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_3_enable_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_3_ps1_n]
set_property PACKAGE_PIN W18 [get_ports MC_3_ps1_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_2_enable_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_2_ps1_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_1_enable_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_1_ps1_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_0_enable_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_0_ps1_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_4_enable_n]
set_property IOSTANDARD LVCMOS33 [get_ports MC_4_ps1_n]
set_property PACKAGE_PIN Y9 [get_ports ADC_B_miso]
set_property PACKAGE_PIN Y8 [get_ports ADC_B_mosi]
set_property PACKAGE_PIN Y6 [get_ports ADC_B_ncs0]
set_property PACKAGE_PIN T9 [get_ports ADC_A_miso]
set_property PACKAGE_PIN U10 [get_ports ADC_A_mosi]
set_property PACKAGE_PIN V7 [get_ports ADC_A_ncs0]
set_property PACKAGE_PIN Y7 [get_ports ADC_B_clk]
set_property PACKAGE_PIN U7 [get_ports ADC_A_clk]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_2_mp_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_2_mp_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_2_mp_pg_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_2_pwr_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_2_pwr_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_2_pwr_pg_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_4_mp_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_4_mp_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_4_mp_pg_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_4_pwr_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_4_pwr_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_4_pwr_pg_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_3_mp_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_3_mp_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_3_mp_pg_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_3_pwr_ena_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_3_pwr_flt_n]
set_property IOSTANDARD LVCMOS33 [get_ports TPS2358_3_pwr_pg_n]
set_property PACKAGE_PIN Y14 [get_ports TPS2358_2_mp_ena_n]
set_property PACKAGE_PIN V15 [get_ports TPS2358_2_mp_flt_n]
set_property PACKAGE_PIN U14 [get_ports TPS2358_2_mp_pg_n]
set_property PACKAGE_PIN W14 [get_ports TPS2358_2_pwr_ena_n]
set_property PACKAGE_PIN Y17 [get_ports TPS2358_2_pwr_flt_n]
set_property PACKAGE_PIN Y16 [get_ports TPS2358_2_pwr_pg_n]
set_property PACKAGE_PIN T14 [get_ports TPS2358_1_mp_ena_n]
set_property PACKAGE_PIN W13 [get_ports TPS2358_1_mp_flt_n]
set_property PACKAGE_PIN T15 [get_ports TPS2358_1_mp_pg_n]
set_property PACKAGE_PIN U12 [get_ports TPS2358_1_pwr_ena_n]
set_property PACKAGE_PIN V13 [get_ports TPS2358_1_pwr_flt_n]
set_property PACKAGE_PIN V12 [get_ports TPS2358_1_pwr_pg_n]
set_property PACKAGE_PIN W8 [get_ports TPS2358_0_mp_ena_n]
set_property PACKAGE_PIN Y11 [get_ports TPS2358_0_mp_flt_n]
set_property PACKAGE_PIN W10 [get_ports TPS2358_0_mp_pg_n]
set_property PACKAGE_PIN W9 [get_ports TPS2358_0_pwr_ena_n]
set_property PACKAGE_PIN Y12 [get_ports TPS2358_0_pwr_flt_n]
set_property PACKAGE_PIN W11 [get_ports TPS2358_0_pwr_pg_n]
set_property PACKAGE_PIN N20 [get_ports TPS2358_4_mp_ena_n]
set_property PACKAGE_PIN U20 [get_ports TPS2358_4_mp_flt_n]
set_property PACKAGE_PIN P20 [get_ports TPS2358_4_mp_pg_n]
set_property PACKAGE_PIN U19 [get_ports TPS2358_4_pwr_ena_n]
set_property PACKAGE_PIN T20 [get_ports TPS2358_4_pwr_flt_n]
set_property PACKAGE_PIN V20 [get_ports TPS2358_4_pwr_pg_n]
set_property PACKAGE_PIN W16 [get_ports TPS2358_3_mp_ena_n]
set_property PACKAGE_PIN V18 [get_ports TPS2358_3_mp_flt_n]
set_property PACKAGE_PIN W19 [get_ports TPS2358_3_mp_pg_n]
set_property PACKAGE_PIN V17 [get_ports TPS2358_3_pwr_ena_n]
set_property PACKAGE_PIN W20 [get_ports TPS2358_3_pwr_flt_n]
set_property PACKAGE_PIN Y19 [get_ports TPS2358_3_pwr_pg_n]
set_property PACKAGE_PIN C20 [get_ports JTAG_trst]
set_property PACKAGE_PIN B20 [get_ports JTAG_tck]
set_property PACKAGE_PIN B19 [get_ports JTAG_tms]
set_property PACKAGE_PIN A20 [get_ports JTAG_tdo]
set_property PACKAGE_PIN E17 [get_ports JTAG_tdi]
set_property PACKAGE_PIN V5 [get_ports {PL_LEDS[0]}]
set_property PACKAGE_PIN V8 [get_ports {PL_LEDS[1]}]

set_property PACKAGE_PIN F16 [get_ports {ATCA_LEDS[0]}]
set_property PACKAGE_PIN F17 [get_ports {ATCA_LEDS[1]}]
set_property PACKAGE_PIN D18 [get_ports {ATCA_LEDS[2]}]
set_property PACKAGE_PIN D19 [get_ports {ATCA_LEDS[3]}]

set_property PACKAGE_PIN F19 [get_ports PG_A]
set_property PACKAGE_PIN D20 [get_ports PG_B]
set_property PACKAGE_PIN E18 [get_ports ALARM_A]
set_property PACKAGE_PIN E19 [get_ports ALARM_B]
set_property PACKAGE_PIN G20 [get_ports HNDL_SW]

set_property IOSTANDARD LVCMOS33 [get_ports JTAG_tck]
set_property IOSTANDARD LVCMOS33 [get_ports JTAG_tdi]
set_property IOSTANDARD LVCMOS33 [get_ports JTAG_tdo]
set_property IOSTANDARD LVCMOS33 [get_ports JTAG_tms]
set_property IOSTANDARD LVCMOS33 [get_ports JTAG_trst]

set_property IOSTANDARD LVCMOS33 [get_ports {PL_LEDS[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {PL_LEDS[0]}]

set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[3]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[2]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[1]}]
set_property IOSTANDARD LVCMOS33 [get_ports {ATCA_LEDS[0]}]
set_property SLEW FAST [get_ports ADC_B_clk]
set_property SLEW FAST [get_ports ADC_A_clk]
set_property SLEW FAST [get_ports ADC_A_ncs0]
set_property SLEW FAST [get_ports ADC_A_mosi]
set_property SLEW FAST [get_ports ADC_B_mosi]
set_property SLEW FAST [get_ports ADC_B_ncs0]

#set_property OFFCHIP_TERM NONE [get_ports GPIO[32]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[33]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[34]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[35]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[36]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[37]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[38]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[39]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[40]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[41]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[42]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[43]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[44]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[45]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[46]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[47]]
#set_property OFFCHIP_TERM NONE [get_ports GPIO[48]]
set_property IOSTANDARD LVCMOS33 [get_ports ALARM_A]
set_property IOSTANDARD LVCMOS33 [get_ports ALARM_B]
set_property IOSTANDARD LVCMOS33 [get_ports HNDL_SW]
set_property IOSTANDARD LVCMOS33 [get_ports PG_A]
set_property IOSTANDARD LVCMOS33 [get_ports PG_B]

set_property OFFCHIP_TERM NONE [get_ports I2C_0_scl]
set_property OFFCHIP_TERM NONE [get_ports I2C_0_sda]
set_property OFFCHIP_TERM NONE [get_ports I2C_1_scl]
set_property OFFCHIP_TERM NONE [get_ports I2C_1_sda]
set_property OFFCHIP_TERM NONE [get_ports I2C_2_scl]
set_property OFFCHIP_TERM NONE [get_ports I2C_2_sda]
set_property OFFCHIP_TERM NONE [get_ports I2C_3_scl]
set_property OFFCHIP_TERM NONE [get_ports I2C_3_sda]
set_property OFFCHIP_TERM NONE [get_ports I2C_4_scl]
set_property OFFCHIP_TERM NONE [get_ports I2C_4_sda]
set_property OFFCHIP_TERM NONE [get_ports MC_0_enable_n]
set_property OFFCHIP_TERM NONE [get_ports MC_1_enable_n]
set_property OFFCHIP_TERM NONE [get_ports MC_2_enable_n]
set_property OFFCHIP_TERM NONE [get_ports MC_3_enable_n]
set_property OFFCHIP_TERM NONE [get_ports MC_4_enable_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_0_mp_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_0_pwr_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_1_mp_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_1_pwr_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_2_mp_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_2_pwr_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_3_mp_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_3_pwr_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_4_mp_ena_n]
set_property OFFCHIP_TERM NONE [get_ports TPS2358_4_pwr_ena_n]
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
set_property OFFCHIP_TERM NONE [get_ports GPIO[0]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[10]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[11]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[12]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[13]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[14]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[15]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[16]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[17]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[18]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[19]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[1]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[20]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[21]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[22]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[23]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[24]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[25]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[26]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[27]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[28]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[29]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[2]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[30]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[31]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[3]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[4]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[5]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[6]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[7]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[8]]
set_property OFFCHIP_TERM NONE [get_ports GPIO[9]]

set_property OFFCHIP_TERM NONE [get_ports eeprom_i2c_0_scl_io]
set_property OFFCHIP_TERM NONE [get_ports eeprom_i2c_0_sda_io]
set_property OFFCHIP_TERM NONE [get_ports pim400_i2c_scl_io]
set_property OFFCHIP_TERM NONE [get_ports pim400_i2c_sda_io]
set_property PACKAGE_PIN H15 [get_ports pim400_i2c_scl_io]
set_property PACKAGE_PIN H17 [get_ports pim400_i2c_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports pim400_i2c_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports pim400_i2c_sda_io]
set_property PACKAGE_PIN J20 [get_ports eeprom_i2c_0_sda_io]
set_property PACKAGE_PIN J18 [get_ports eeprom_i2c_0_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports eeprom_i2c_0_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports eeprom_i2c_0_sda_io]

set_property OFFCHIP_TERM NONE [get_ports ADC_A_clk]
set_property OFFCHIP_TERM NONE [get_ports ADC_A_mosi]
set_property OFFCHIP_TERM NONE [get_ports ADC_A_ncs0]
set_property OFFCHIP_TERM NONE [get_ports ADC_B_clk]
set_property OFFCHIP_TERM NONE [get_ports ADC_B_mosi]
set_property OFFCHIP_TERM NONE [get_ports ADC_B_ncs0]
set_property OFFCHIP_TERM NONE [get_ports EEPROM_I2C_0_scl_io]
set_property OFFCHIP_TERM NONE [get_ports EEPROM_I2C_0_sda_io]
set_property OFFCHIP_TERM NONE [get_ports PIM400_I2C_scl_io]
set_property OFFCHIP_TERM NONE [get_ports PIM400_I2C_sda_io]
set_property OFFCHIP_TERM NONE [get_ports TCK]
set_property OFFCHIP_TERM NONE [get_ports TDI]
set_property OFFCHIP_TERM NONE [get_ports TMS]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[3]]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[2]]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[1]]
set_property OFFCHIP_TERM NONE [get_ports ATCA_LEDS[0]]
set_property OFFCHIP_TERM NONE [get_ports PL_LEDS[1]]
set_property OFFCHIP_TERM NONE [get_ports PL_LEDS[0]]
set_property OFFCHIP_TERM NONE [get_ports pwr_en[6]]
set_property OFFCHIP_TERM NONE [get_ports pwr_en[5]]
set_property OFFCHIP_TERM NONE [get_ports pwr_en[4]]
set_property OFFCHIP_TERM NONE [get_ports pwr_en[3]]
set_property OFFCHIP_TERM NONE [get_ports pwr_en[2]]
set_property OFFCHIP_TERM NONE [get_ports pwr_en[1]]
set_property OFFCHIP_TERM NONE [get_ports pwr_en[0]]
set_property PACKAGE_PIN H15 [get_ports PIM400_I2C_scl_io]
set_property PACKAGE_PIN H17 [get_ports PIM400_I2C_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports PIM400_I2C_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports PIM400_I2C_sda_io]
set_property PACKAGE_PIN J18 [get_ports EEPROM_I2C_0_scl_io]
set_property PACKAGE_PIN J20 [get_ports EEPROM_I2C_0_sda_io]
set_property IOSTANDARD LVCMOS33 [get_ports EEPROM_I2C_0_scl_io]
set_property IOSTANDARD LVCMOS33 [get_ports EEPROM_I2C_0_sda_io]
set_property C_CLK_INPUT_FREQ_HZ 300000000 [get_debug_cores dbg_hub]
set_property C_ENABLE_CLK_DIVIDER false [get_debug_cores dbg_hub]
set_property C_USER_SCAN_CHAIN 1 [get_debug_cores dbg_hub]
connect_debug_port dbg_hub/clk [get_nets clk]
