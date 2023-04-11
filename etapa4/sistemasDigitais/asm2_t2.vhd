library ieee ;
    use ieee.std_logic_1164.all ;
    use ieee.numeric_std.all ;

entity matrix_op is
  port (
    boundary : in std_logic_vector(15 downto 0);
    start : in std_logic;
    done : out std_logic;

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


    clk : in std_logic;
    rst : in std_logic
  ) ;
end matrix_op ; 

architecture arch of matrix_op is
    type matrix_8 is array (1 to 2, 1 to 2) of std_logic_vector(7 downto 0);
    type matrix_16 is array (1 to 2, 1 to 2) of std_logic_vector(15 downto 0);
    type first_reg is array (1 to 2) of matrix_16;
    type state_t is (off_s, start_s, on_s, done_s);

    signal A, B, C, D : matrix_8;
    signal S3, S4, s5 : matrix_16;
    signal S1, S2 : first_reg;

    signal counter : std_logic_vector(3 downto 0);

    signal state : state_t;
begin
    process(clk, rst)
    begin
        if rst = '1' then
        elsif rising_edge(clk) then
            case state is
                when off_s =>
                    done <= '0';
                    if start = '1' then 
                        state <= start_s;
                    end if;
                when start_s =>
                    counter <= "0100";

                    A <= (1 => (1 => a11, 2 => a12), 2 => (1 => a21, 2 => a22));
                    B <= (1 => (1 => b11, 2 => b12), 2 => (1 => b21, 2 => b22));
                    C <= (1 => (1 => c11, 2 => c12), 2 => (1 => c21, 2 => c22));
                    D <= (1 => (1 => d11, 2 => d12), 2 => (1 => d21, 2 => d22));

                    S1 <= (others=>(others=>(others=>(others => '0'))));
                    S2 <= (others=>(others=>(others=>(others => '0'))));
                    S3 <= (others=>(others=>(others => '0')));
                    S4 <= (others=>(others=>(others => '0')));
                    S5 <= (others=>(others=>(others => '0')));

                    state <= on_s;

                when on_s =>
                    counter <= std_logic_vector(unsigned(counter) - 1);

                    for i in 1 to 2 loop
                        for j in 1 to 2 loop
                            for k in 1 to 2 loop
                                S1(k)(i, j) <= std_logic_vector(unsigned(A(i, k)) * unsigned(B(k, j)));
                                S2(k)(i, j) <= std_logic_vector(unsigned(C(i, k)) * unsigned(D(k, j)));
                            end loop;
                        end loop;
                    end loop;

                    for i in 1 to 2 loop
                        for j in 1 to 2 loop
                            S3(i, j) <= std_logic_vector(unsigned(S1(1)(i, j)) * unsigned(S1(2)(i, j)));
                            S4(i, j) <= std_logic_vector(unsigned(S2(1)(i, j)) * unsigned(S2(2)(i, j)));
                        end loop;
                    end loop;

                    for i in 1 to 2 loop
                        for j in 1 to 2 loop
                            S5(i, j) <= std_logic_vector(unsigned(S3(i, j)) * unsigned(S4(i, j)));
                        end loop;
                    end loop;

                    for i in 1 to 2 loop
                        for j in 1 to 2 loop
                            if unsigned(S5(i, j)) > unsigned(boundary) then
                                S5(i, j) <= S5(i, j);
                            else
                                S5(i, j) <= (others => '0');
                            end if;
                        end loop;
                    end loop;
					if counter = "0000" then
						state <= done_s;
					end if;
                when done_s =>
                    done <= '1';
                    s11 <= S5(1, 1);
                    s12 <= S5(1, 2);
                    s21 <= S5(2, 1);
                    s22 <= S5(2, 2);
            end case;
		else			
			S1 <= S1;
			S2 <= S2;
			S3 <= S3;
			S4 <= S4;
			S5 <= S5;
        end if;
    end process;

end architecture ;