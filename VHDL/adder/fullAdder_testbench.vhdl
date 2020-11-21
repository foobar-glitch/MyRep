LIBRARY ieee;
USE ieee.std_logic_1164.ALL;
 
ENTITY Testbench_full_adder IS
END Testbench_full_adder;
 
ARCHITECTURE behavior OF Testbench_full_adder IS
 
 -- Component Declaration for the Unit Under Test (UUT)
 
 COMPONENT full_adder
 PORT(
 a : IN bit;
 b : IN bit;
 cin : IN bit;
 sum : OUT bit;
 cout : OUT bit
 );
 END COMPONENT;
 
signal input  : bit_vector(2 downto 0);
signal output : bit_vector(1 downto 0);
 
 
BEGIN
 
 --Instantiate the Unit Under Test (UUT)
 uut: full_adder PORT MAP (
 a => input(0),
 b => input(1),
 cin => input(2),
 sum => output(0),
 cout => output(1)
 );
 
 -- Stimulus process
 stim_proc: process
 BEGIN
 -- hold reset state for 100 ns.
	input <= "000"; wait for 10 ns; assert output = "00" report "0+0+0 failed";
    input <= "001"; wait for 10 ns; assert output = "01" report "0+0+1 failed";
    input <= "010"; wait for 10 ns; assert output = "01" report "0+1+0 failed";
    input <= "100"; wait for 10 ns; assert output = "01" report "1+0+0 failed";
    input <= "011"; wait for 10 ns; assert output = "10" report "0+1+1 failed";
    input <= "110"; wait for 10 ns; assert output = "10" report "1+1+0 failed";
    input <= "111"; wait for 10 ns; assert output = "11" report "1+1+1 failed";
    report "Full adder testbench finished";wait;
 END PROCESS;
END;
