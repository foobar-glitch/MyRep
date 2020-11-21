library IEEE;
use IEEE.numeric_std.all;

ENTITY testbench_4bit_adder IS
END testbench_4bit_adder;


ARCHITECTURE behavior of testbench_4bit_adder is

COMPONENT four_bit_adder
PORT(
	x : in bit_vector(3 downto 0);
	y : in bit_vector(3 downto 0);
	z : out bit_vector(3 downto 0);
	c_out : out bit -- carry bit
);
END COMPONENT;


---- changes bit_vector into String
function to_string (a: bit_vector) return string is
variable b : string (1 to a'length) := (others => NUL);
variable stri : integer := 1; 
begin
    for i in a'range loop
        b(stri) := bit'image(a((i)))(2);
    stri := stri+1;
    end loop;
return b;
end function;
--- prints the calculation of the inputs
function printValues (i_x, i_y, sum : bit_vector) return string is
begin
return to_string(i_x)&" + " & to_string(i_y) & " = " & to_string(sum);
end function;

-----


SIGNAL input_x, input_y, output_z : bit_vector(3 downto 0);
SIGNAL output_c : bit;

BEGIN
 --Instantiate the Unit Under Test (UUT)
 uut: four_bit_adder PORT MAP (
 x => input_x,
 y => input_y,
 z => output_z,
 c_out => output_c
 );


 -- Stimulus process
 stim_proc: process
 BEGIN
 
 -- hold reset state for 100 ns.
 input_x<="0101"; input_y<="0011"; wait for 10 ns; assert output_z = "1000" report "Wrong calculation";
 report "Calculated: "& printValues(input_x, input_y, output_z);
 input_x<="1111"; input_y<="1111"; wait for 10 ns;
 report "Calculated: "& printValues(input_x, input_y, output_z);
 assert output_c = '0' report "Overflow Summ too big";
 
 report "Full adder testbench finished";wait;
 END PROCESS;
 END;
