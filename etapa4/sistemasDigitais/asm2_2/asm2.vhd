library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;

entity asm2_pc is
  port (
    A : IN std_logic_vector(3 downto 0);
    B : IN std_logic_vector(3 downto 0);
    start : in std_logic;
    S : out std_logic_vector(7 downto 0);
    clk : in std_logic;
    rst : in std_logic
  );
end entity;

architecture Behavioral of asm2_pc is
  type t_state is (s0, s1, s2, s3);
  signal state: t_state;
  signal regA: std_logic_vector(7 downto 0);
  signal regB: std_logic_vector(7 downto 0);
  signal regS: std_logic_vector(7 downto 0);

begin
  process(clk, rst, state)
  begin
    if rst = '1' then
      state <= s0;
      regS <= (others => '0');
    elsif rising_edge(clk) then
      case state is
        when s0 =>
          if start = '1' then
            regA(3 downto 0) <= A;
            regA(7 downto 4) <= (others => '0');
            regB <= B;
            state <= s1;  
            regS <= (others => '0');
          end if;

        when s1 =>
          if regB(0) = '0' then
            regS <= std_logic_vector(unsigned(regS) + unsigned(regA));
            state <= s2;
          else
            regA(7 downto 1) <= regA(6 downto 0);
            regA(0) <= '0';
            regB(2 downto 0) <= regB(3 downto 1);
            regB(3) <= '0';
            if regB = "0000" then
              state <= s3;
            else
              state <= s1;
            end if;
          end if;

        when s2 =>
          regA(7 downto 1) <= regA(6 downto 0);
          regA(0) <= '0';
          regB(2 downto 0) <= regB(3 downto 1);
          regB(3) <= '0';
          if regB = "0000" then
            state <= s3;
          else
            state <= s1;
          end if;

        when s3 =>
          state <= s0;
      end case;
    else 
      regA <= regA;
      regB <= regB;
      regS <= regS;
      state <= state;
    end if;
  end process;
  S <= regS;
end architecture;