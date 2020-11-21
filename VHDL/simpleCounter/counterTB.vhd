entity counter_tb is
end counter_tb;

architecture behavior of counter_tb is

component counter
port(
	clk, rst	: in bit;
	count		: out bit_vector(2 downto 0)
);
end component;

signal input_clk, input_rst : bit;

begin
	uut: entity work.counter port map (
		clk => input_clk,
		rst => input_rst
	);
	

	
	stim_proc: process
	
	begin
		input_rst <= '0'; 
		input_clk <= '0';wait for 10 ns;
		
		for i in 1 to 20 loop
			input_clk <= not input_clk;wait for 10 ns;
		end loop;
		wait; -- ends process
	end process;
	
END behavior;
