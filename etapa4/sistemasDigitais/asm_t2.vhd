library ieee ;
    use ieee.std_logic_1164.all ;
    use ieee.numeric_std.all ;

entity matrix_operation is
    port (
        a11 : in std_logic_vector(7 downto 0);
        a12 : in std_logic_vector(7 downto 0);
        a21 : in std_logic_vector(7 downto 0);
        a22 : in std_logic_vector(7 downto 0);
        b11 : in std_logic_vector(7 downto 0);
        b12 : in std_logic_vector(7 downto 0);
        b21 : in std_logic_vector(7 downto 0);
        b22 : in std_logic_vector(7 downto 0);
        c11 : in std_logic_vector(7 downto 0);
        c12 : in std_logic_vector(7 downto 0);
        c21 : in std_logic_vector(7 downto 0);
        c22 : in std_logic_vector(7 downto 0);
        d11 : in std_logic_vector(7 downto 0);
        d12 : in std_logic_vector(7 downto 0);
        d21 : in std_logic_vector(7 downto 0);
        d22 : in std_logic_vector(7 downto 0);

        s11 : out std_logic_vector(15 downto 0);
        s12 : out std_logic_vector(15 downto 0);
        s21 : out std_logic_vector(15 downto 0);
        s22 : out std_logic_vector(15 downto 0);

        reset : in std_logic;
        clock : in std_logic;

        start : in std_logic;
        done : out std_logic
    ) ;
end matrix_operation ; 

architecture arch of matrix_operation is
    type state_type is (start_s, running_s ,done_s);
        
    type matrix_8b is array (0 to 1, 0 to 1) of std_logic_vector (7 downto 0);
    type matrix_16b is array (0 to 1, 0 to 1) of std_logic_vector (15 downto 0);

    type zero_line_reg_t is array (0 to 15) of std_logic_vector (15 downto 0);
    type first_line_reg_t is array (0 to 15) of std_logic_vector (15 downto 0);
    type second_line_reg_t is array (0 to 7) of std_logic_vector (15 downto 0);
    type third_line_reg_t is array (0 to 3) of std_logic_vector (15 downto 0);

    signal zero_line_reg : zero_line_reg_t;
    signal first_line_reg : first_line_reg_t;
    signal second_line_reg : second_line_reg_t;
    signal third_line_reg : third_line_reg_t;

    signal state : state_type := start_s;
    signal counter : std_logic_vector(3 downto 0);
begin

    process (clock, reset, start)
    begin
        if reset = '1' then 
            
        elsif rising_edge(clock) then
            case state is
                when start_s =>
                    counter <= 3;
                    
                    zero_line_reg(0) <= a11;
                    zero_line_reg(1) <= a12;
                    zero_line_reg(2) <= a21;
                    zero_line_reg(3) <= a22;

                    zero_line_reg(0+4) <= b11;
                    zero_line_reg(1+4) <= b12;
                    zero_line_reg(2+4) <= b21;
                    zero_line_reg(3+4) <= b22;
                    
                    zero_line_reg(0+8) <= c11;
                    zero_line_reg(1+8) <= c12;
                    zero_line_reg(2+8) <= c21;
                    zero_line_reg(3+8) <= c22;

                    zero_line_reg(0+12) <= d11;
                    zero_line_reg(1+12) <= d12;
                    zero_line_reg(2+12) <= d21;
                    zero_line_reg(3+12) <= d22;

                    first_line_reg <= (others => (others => '0'));
                    second_line_reg <= (others => (others => '0'));

                when running_s =>
                    first_line_reg(0) <= std_logic_vector(unsigned(zero_line_reg(0)) * unsigned(zero_line_reg(0+4)));
                    first_line_reg(1) <= std_logic_vector(unsigned(zero_line_reg(1)) * unsigned(zero_line_reg(2+4)));
                    first_line_reg(2) <= std_logic_vector(unsigned(zero_line_reg(2)) * unsigned(zero_line_reg(1+4)));
                    first_line_reg(3) <= std_logic_vector(unsigned(zero_line_reg(3)) * unsigned(zero_line_reg(3+4)));

                    first_line_reg(0+4) <= std_logic_vector(unsigned(zero_line_reg(2)) * unsigned(zero_line_reg(0+4)));
                    first_line_reg(1+4) <= std_logic_vector(unsigned(zero_line_reg(0)) * unsigned(zero_line_reg(1+4)));
                    first_line_reg(2+4) <= std_logic_vector(unsigned(zero_line_reg(3)) * unsigned(zero_line_reg(2+4)));
                    first_line_reg(3+4) <= std_logic_vector(unsigned(zero_line_reg(1)) * unsigned(zero_line_reg(3+4)));

                    first_line_reg(0+8) <= std_logic_vector(unsigned(zero_line_reg(0+8)) * unsigned(zero_line_reg(0+12)));
                    first_line_reg(1+8) <= std_logic_vector(unsigned(zero_line_reg(1+8)) * unsigned(zero_line_reg(2+12)));
                    first_line_reg(2+8) <= std_logic_vector(unsigned(zero_line_reg(2+8)) * unsigned(zero_line_reg(1+12)));
                    first_line_reg(3+8) <= std_logic_vector(unsigned(zero_line_reg(3+8)) * unsigned(zero_line_reg(3+12)));

                    first_line_reg(0+12) <= std_logic_vector(unsigned(zero_line_reg(2+8)) * unsigned(zero_line_reg(0+12)));
                    first_line_reg(1+12) <= std_logic_vector(unsigned(zero_line_reg(0+8)) * unsigned(zero_line_reg(1+12)));
                    first_line_reg(2+12) <= std_logic_vector(unsigned(zero_line_reg(3+8)) * unsigned(zero_line_reg(2+12)));
                    first_line_reg(3+12) <= std_logic_vector(unsigned(zero_line_reg(1+8)) * unsigned(zero_line_reg(3+12)));

                    second_line_reg(0) <= std_logic_vector(unsigned(first_line_reg(0)) + unsigned(first_line_reg(0+4)));
                    second_line_reg(1) <= std_logic_vector(unsigned(first_line_reg(1)) + unsigned(first_line_reg(1+4)));
                    second_line_reg(2) <= std_logic_vector(unsigned(first_line_reg(2)) + unsigned(first_line_reg(2+4)));
                    second_line_reg(3) <= std_logic_vector(unsigned(first_line_reg(3)) + unsigned(first_line_reg(3+4)));
                    
                    second_line_reg(4) <= std_logic_vector(unsigned(first_line_reg(0+8)) + unsigned(first_line_reg(0+12)));
                    second_line_reg(5) <= std_logic_vector(unsigned(first_line_reg(1+8)) + unsigned(first_line_reg(1+12)));
                    second_line_reg(6) <= std_logic_vector(unsigned(first_line_reg(2+8)) + unsigned(first_line_reg(2+12)));
                    second_line_reg(7) <= std_logic_vector(unsigned(first_line_reg(3+8)) + unsigned(first_line_reg(3+12)));

                    third_line_reg(0) <= std_logic_vector(unsigned(second_line_reg(0)) + unsigned(second_line_reg(0+4)));
                    third_line_reg(1) <= std_logic_vector(unsigned(second_line_reg(1)) + unsigned(second_line_reg(1+4)));
                    third_line_reg(2) <= std_logic_vector(unsigned(second_line_reg(2)) + unsigned(second_line_reg(2+4)));
                    third_line_reg(3) <= std_logic_vector(unsigned(second_line_reg(3)) + unsigned(second_line_reg(3+4)));
                when done_s =>
            end case;
        else   
            zero_line_reg(0) <= zero_line_reg(0);
            zero_line_reg(1) <= zero_line_reg(1);
            zero_line_reg(2) <= zero_line_reg(2);
            zero_line_reg(3) <= zero_line_reg(3);

            zero_line_reg(0+4) <= zero_line_reg(0+4);
            zero_line_reg(1+4) <= zero_line_reg(1+4);
            zero_line_reg(2+4) <= zero_line_reg(2+4);
            zero_line_reg(3+4) <= zero_line_reg(3+4);
            
            zero_line_reg(0+8) <= zero_line_reg(0+8);
            zero_line_reg(1+8) <= zero_line_reg(1+8);
            zero_line_reg(2+8) <= zero_line_reg(2+8);
            zero_line_reg(3+8) <= zero_line_reg(3+8);

            zero_line_reg(0+12) <= zero_line_reg(0+12);
            zero_line_reg(1+12) <= zero_line_reg(1+12);
            zero_line_reg(2+12) <= zero_line_reg(2+12);
            zero_line_reg(3+12) <= zero_line_reg(3+12);

            first_line_reg <= first_line_reg;
            second_line_reg <= second_line_reg;
        end if;    
    end process;
        
end architecture ;