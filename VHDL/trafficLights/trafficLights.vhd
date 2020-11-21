entity traffic_lights is 
	port(
		clk, rst,tra : in bit; 					 -- tra:= traffic
		lights		 : out bit_vector(2 downto 0) -- lights(0):=red, lights(1):=yellow, lights(2):= green
	);
end traffic_lights;

architecture behavior of traffic_lights is
	type statetype is (s0, s1, s2, s3);
	signal currentstate, nextstate : statetype;

begin
	StateReg: process(clk, rst, tra)
	begin
		if(rst = '1') then
			nextstate<=s0;
		elsif (clk = '0' and clk'event) then
			case currentstate is
				when s0=>
					-- once no traffic change to yellow
					if (tra = '0') then
						nextstate <= s1;
					else
						nextstate <= s0;
					end if;
				when s1=>
					nextstate <= s2;
				when s2=>
					-- when no traffic light stays green
					if (tra = '0') then
						nextstate <= s2;
					else
						nextstate <= s3;
					end if;
				when s3=>
					nextstate <= s0;
				-- define as default state
				when others=>
					nextstate <= s0;
			end case;
		end if;
		currentstate<=nextstate;
	end process;
	
process (currentstate)
  begin
    case currentstate is
      when s0 =>
        lights <= "100"; --red
      when s1 =>
        lights <= "010"; --yellow
      when s2 =>
        lights <= "001"; -- green
      when s3 =>
        lights <= "011"; -- red yellow
    end case;
  end process;
	

end behavior;
