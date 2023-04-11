library ieee;
  use ieee.std_logic_1164.all;
  use ieee.numeric_std.all;

entity asm2_po is
  port (
    A : IN std_logic_vector(3 downto 0);
    B : IN std_logic_vector(3 downto 0);
    load : IN std_logic;
    sh : IN std_logic;
    ad : IN std_logic;
    
    m : OUT std_logic;
    k : OUT std_logic;
    
    S : OUT std_logic_vector(7 downto 0);
    
    clk : IN std_logic;
    rst : IN std_logic
  );
end entity;

architecture Behavioral of asm2_po is
  signal regA: std_logic_vector(7 downto 0);
  signal regB: std_logic_vector(3 downto 0);
  signal regS: std_logic_vector(7 downto 0);

begin
  process(clk, rst)
  begin
    if rst = '1' then
      regA <= (others => '0');
    elsif rising_edge(clk) then
      if load = '1' then
        regA(3 downto 0) <= A;
        regA(7 downto 4) <= (others => '0');
      elsif sh = '1' then
        regA(7 downto 1) <= regA(6 downto 0);
        regA(0) <= '0';
      else
        regA <= regA;
      end if;      
    end if;
  end process;

  process(clk, rst)
  begin
    if rst = '1' then
      regB <= (others => '0');
    elsif rising_edge(clk) then
      if load = '1' then
        regB <= B;
      elsif sh = '1' then
        regA(2 downto 0) <= regA(3 downto 1);
        regA(3) <= '0';
      else
        regB <= regB;
      end if;      
    end if;
  end process;

  process(clk, rst)
  begin
    if rst = '1' then
      regS <= (others => '0');
    elsif rising_edge(clk) then
      if ad = '1' then
        regS <= std_logic_vector(unsigned(regS) + unsigned(regA));
      else
        regS <= regS;
      end if;      
    end if;
  end process;

  process(regB)
  begin
    if regB = "0000" then
      k <= '1';
    else
      k <= '0';
    end if;
  end process;

  m <= regB(0);
  s <= regS;
end architecture;