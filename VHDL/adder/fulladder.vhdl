entity full_adder is
	port(
		a, b, cin	: in Bit;
		sum, cout	: out Bit);
end full_adder;
 
architecture structural of full_adder is
component half_adder
	port(
		a, b		: in Bit;
		sum, carry	: out Bit);
end component;

SIGNAL s1, s2, s3 : Bit;
begin
	u1: half_adder port map (a=>b, b=>cin, carry=>s1, sum=>s2);
	u2: half_adder port map (a=>a, b=>s2, carry=>s3, sum=>sum);
	cout <= s1 OR s3;
end structural;
