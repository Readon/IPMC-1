----------------------------------------------------------------------------------
-- Company: 
-- Engineer: 
-- 
-- Create Date: 04/20/2017 04:25:28 PM
-- Design Name: 
-- Module Name: debouncer - Behavioral
-- Project Name: 
-- Target Devices: 
-- Tool Versions: 
-- Description: 
-- 
-- Dependencies: 
-- 
-- Revision:
-- Revision 0.01 - File Created
-- Additional Comments:
-- 
----------------------------------------------------------------------------------


library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity debouncer is
    Generic (
        COUNTER_SIZE : integer := 16;
        RESET_VALUE : std_logic := '0'
    );
    Port ( ARESETN_IN : in STD_LOGIC;
           CLK_IN : in STD_LOGIC;
           SIG_IN : in STD_LOGIC;
           SIG_OUT : out STD_LOGIC);
end debouncer;

architecture Behavioral of debouncer is
    signal r_counter : unsigned (COUNTER_SIZE-1 downto 0);
    constant C_COUNTER_MAX : unsigned (COUNTER_SIZE-1 downto 0) := (others => '1');
begin
    process (ARESETN_IN, CLK_IN) begin
        if (ARESETN_IN = '0') then
            SIG_OUT <= RESET_VALUE;
        elsif (CLK_IN'event and CLK_IN = '1') then
            SIG_OUT <= RESET_VALUE;
            
            if (SIG_IN = RESET_VALUE) then
                r_counter <= (others => '0');
            else
                if (r_counter = C_COUNTER_MAX) then
                    SIG_OUT <= not RESET_VALUE;
                else
                    r_counter <= r_counter + 1;
                end if;
            end if;
        end if;
    end process;

end Behavioral;
