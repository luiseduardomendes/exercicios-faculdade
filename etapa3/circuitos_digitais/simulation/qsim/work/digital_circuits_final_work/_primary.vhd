library verilog;
use verilog.vl_types.all;
entity digital_circuits_final_work is
    port(
        c_out           : out    vl_logic;
        add_sub         : in     vl_logic;
        a               : in     vl_logic_vector(7 downto 0);
        b               : in     vl_logic_vector(7 downto 0);
        s               : out    vl_logic_vector(7 downto 0)
    );
end digital_circuits_final_work;
