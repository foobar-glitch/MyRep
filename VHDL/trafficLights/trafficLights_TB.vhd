entity tralights_tb is
end tralights_tb;

architecture behavior of tralights_tb is

signal input_clk, input_rst, input_traffic : bit;

begin
	uut : entity work.traffic_lights port map(
		clk => input_clk,
		rst => input_rst,
		tra => input_traffic
	);
	
	stim_proc: process
	begin
		input_clk <= '0';
		input_rst <= '0';
		input_traffic <= '1', '0' after 20 ns, '1' after 60 ns;
		
		for i in 1 to 20 loop
			wait for 5 ns; input_clk <= not input_clk;
		end loop;
		
		wait;
	end process;
	
end behavior;
