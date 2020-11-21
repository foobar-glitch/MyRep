entity half_adder is
	port(
		a, b		: in Bit;
		sum, carry	: out Bit);
end half_adder;

architecture behavioural of half_adder is
begin
	carry <= a AND b;
	sum <= a XOR b;
end behavioural;
 
