-- This file is part of the ZYNQ-IPMC Framework.
--
-- The ZYNQ-IPMC Framework is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.
--
-- The ZYNQ-IPMC Framework is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with the ZYNQ-IPMC Framework.  If not, see <https://www.gnu.org/licenses/>.

library IEEE;
use IEEE.STD_LOGIC_1164.ALL;

-- Uncomment the following library declaration if using
-- arithmetic functions with Signed or Unsigned values
use IEEE.NUMERIC_STD.ALL;

-- Uncomment the following library declaration if instantiating
-- any Xilinx leaf cells in this code.
--library UNISIM;
--use UNISIM.VComponents.all;

entity varcounter is
    Generic (
        WIDTH : integer := 28;
        NOLIMIT : boolean := false
    );
    Port (
        CLK : in STD_LOGIC;
        RST : in STD_LOGIC;
        EN : in STD_LOGIC;
        LIM : in STD_LOGIC_VECTOR (WIDTH-1 downto 0);
        VAL : out STD_LOGIC_VECTOR (WIDTH-1 downto 0);
        MAX : out STD_LOGIC
    );
end varcounter;

architecture Behavioral of varcounter is
    signal varcounter : std_logic_vector (WIDTH-1 downto 0) := (others => '0');
    constant CNTMAX : std_logic_vector (WIDTH-1 downto 0) := (others => '1');
begin
    process (CLK) begin
        if (CLK'event and CLK = '1') then
            MAX <= '0';
        
            if (RST = '1') then
                varcounter <= (others => '0');
            else
                if (EN = '1') then
                    if (NOLIMIT = true) then
                        varcounter <= std_logic_vector(unsigned(varcounter) + 1);
                        if (varcounter = CNTMAX) then
                            MAX <= '1';
                        end if;
                    else
                        if (varcounter = LIM) then
                            varcounter <= (others => '0');
                            MAX <= '1';
                        else
                            varcounter <= std_logic_vector(unsigned(varcounter) + 1);
                        end if;
                    end if;
                end if;
            end if;
        end if;
    end process;
    
    VAL <= varcounter;

end Behavioral;
