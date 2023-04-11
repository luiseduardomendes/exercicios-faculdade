library ieee;
use ieee.std_logic_1164.ALL;
use ieee.numeric_std.ALL;

entity asm2_pc is
  port (
    start : in std_logic;
    m : in std_logic;
    k : in std_logic_vector(3 downto 0);

    load : out std_logic;
    sh : out std_logic;
    ad : out std_logic;

    clk : in std_logic;
    rst : in std_logic
  );
end entity;

architecture Behavioral of asm2_pc is
  type t_state is (s0, s1, s2, s3);
  signal state: t_state;

begin
  process(clk, rst, state)
  begin
    if rst = '1' then
      state <= s0;
      load <= '0';
      sh <= '0';
      ad <= '0';
    elsif rising_edge(clk) then
      load <= '0';
      sh <= '0';
      ad <= '0';
      case state is

        when s0 =>
          if start = '1' then
            load <= '1';
            state <= s1;  
          end if;

        when s1 =>
          if M = '1' then
            AD <= '1';
            state <= s2;
          else
            SH <= '1';
            if k = '1' then
              state <= s3;
            else
              state <= s1;
            end if;
          end if;

        when s2 =>
          SH <= '1';
          if k = '1' then
            state <= s3;
          else
            state <= s1;
          end if;

        when s3 =>
          state <= s0;
      end case;
    end if;
  end process;
end architecture;