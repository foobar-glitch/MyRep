ghdl -a halfadder.vhdl
ghdl -a fulladder.vhdl
ghdl -a fullAdder_testbench.vhdl
ghdl -r Testbench_full_adder

ghdl -a testbench_graphicTest.vhdl
ghdl -r testbench_4bit_adder --wave=new.ghw
