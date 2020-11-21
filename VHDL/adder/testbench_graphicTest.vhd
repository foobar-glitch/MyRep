library ieee;
use ieee.std_logic_1164.all;

ENTITY testbench_4bit_adder IS
END testbench_4bit_adder;


ARCHITECTURE behavior of testbench_4bit_adder is
SIGNAL input_x, input_y, output_z : bit_vector(3 downto 0);
SIGNAL output_c : bit;

BEGIN
 --Instantiate the Unit Under Test (UUT)
 UUT : entity work.four_bit_adder PORT MAP (
 x => input_x,
 y => input_y,
 z => output_z,
 c_out => output_c
 );

 
 input_x <= "0101", "0011" after 30 ns, "0001" after 50 ns;
 input_y <= "0011", "1001" after 20 ns, "0110" after 40 ns;
 END behavior;
