-- counts to 110
entity counter is
	port(
		clk, rst	: in bit;
		count		: out bit_vector(2 downto 0)
	);
end counter;

architecture mealy_beh of counter is
	type statetype is (s0, s1, s2, s3, s4, s5);
	signal currentstate, nextstate: Statetype;
	
begin
	StateReg: process (clk, rst)
	begin
		if (rst = '1') then
			currentstate <= s0;
		elsif (clk = '1' and clk'event) then
			currentstate <= nextstate;
		end if;
	end process;
	
	-- input into process
	CombLogic: Process (currentstate)
	begin
		nextstate <= s0;
		case currentstate is
			when s0 =>
				nextstate <= s1;
				count <= "000";
			when s1 =>
				nextstate <= s2;
				count <= "001";
			when s2 =>
				nextstate <= s3;
				count <= "010";
			when s3 =>
				nextstate <= s4;
				count <= "011";
			when s4 =>
				nextstate <= s5;
				count <= "100";
			when s5 =>
				nextstate <=s0;
				count <= "101";
			end case;
		end process;
	end mealy_beh;

