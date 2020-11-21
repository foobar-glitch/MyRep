LIBRARY ieee;
USE ieee.std_logic_1164.ALL;

ENTITY four_bit_adder is
	PORT(
		x : in bit_vector(3 downto 0); -- for x bits
		y : in bit_vector(3 downto 0);
		z : out bit_vector(3 downto 0);
		c_out : out bit -- carry bit
	);
END four_bit_adder;

ARCHITECTURE structural of four_bit_adder is
COMPONENT full_adder
	PORT(
		a ,b, cin: in bit;
		sum, cout: out bit);
END COMPONENT;
Signal c : bit_vector(3 downto 0);

BEGIN
	c(0)<='0';
	u1: full_adder port map (a=>x(0), b=>y(0), cin=>c(0), sum=>z(0), cout=>c(1));
	u2: full_adder port map (a=>x(1), b=>y(1), cin=>c(1), sum=>z(1), cout=>c(2));
	u3: full_adder port map (a=>x(2), b=>y(2), cin=>c(2), sum=>z(2), cout=>c(3));
	u4: full_adder port map (a=>x(3), b=>y(3), cin=>c(3), sum=>z(3), cout=>c_out);
End structural;

	
	
