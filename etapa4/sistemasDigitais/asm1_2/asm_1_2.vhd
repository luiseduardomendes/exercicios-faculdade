library ieee ;
    use ieee.std_logic_1164.all ;
    use ieee.numeric_std.all ;

entity asm1_2 is
  generic (
    w : natural := 8
  );
  port (
    A : in std_logic_vector(w-1 downto 0);
    B : out std_logic_vector(w-1 downto 0);
    start : in std_logic;
    clk : in std_logic;
    rst : in std_logic
  ) ;
end asm1_2 ; 

architecture arch of asm1_2 is
    signal regA : std_logic_vector(w-1 downto 0);
    signal regB : std_logic_vector(w-1 downto 0);
    type t_state is (s1, s2, s3);
    signal state : t_state;

begin
    process(rst, clk, state)
    begin
        if rst = '1' then
            state <= s1;
        elsif rising_edge(clk) then
            case state is
                when s1 =>
                    regB <= (others => '0');
                    if start = '1' then
                        state <= s2;
                    else
                        regA <= A;
                    end if;
                when s2 =>
                    regA(w-2 downto 0) <= regA(w-1 downto 1);
                    regA(w-1) <= '0';
                    if regA = (regA'range => '0') then
                        state <= s3;
                    elsif regA(0) = '0' then
                        regB <= std_logic_vector(unsigned(regB) + 1);
                    end if;
                when s3 =>
                    if start = '0' then
                        state <= s1;
                    end if;
            end case;
        end if;
    end process;
    B <= regB;
end architecture ;