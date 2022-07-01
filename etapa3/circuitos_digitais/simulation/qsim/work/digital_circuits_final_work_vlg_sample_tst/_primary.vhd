library verilog;
use verilog.vl_types.all;
entity digital_circuits_final_work_vlg_sample_tst is
    port(
        a               : in     vl_logic_vector(7 downto 0);
        add_sub         : in     vl_logic;
        b               : in     vl_logic_vector(7 downto 0);
        sampler_tx      : out    vl_logic
    );
end digital_circuits_final_work_vlg_sample_tst;
