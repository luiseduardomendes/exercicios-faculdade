library ieee ;
  use ieee.std_logic_1164.all ;
  use ieee.numeric_std.all ;

entity ASM2_TB is
end ASM2_TB ; 

architecture arch of ASM2_TB is
  signal A : std_logic_vector(3 downto 0) := (others => '0');
  signal B : std_logic_vector(3 downto 0) := (others => '0');
  signal start: std_logic := '0';
  signal S : std_logic_vector(7 downto 0);
  signal clk : std_logic;
  signal rst : std_logic := '0';

  constant clk_period : time := 10 ns;

  component ASM2 is
    port (
    A : in std_logic_vector(3 downto 0);
    B : in std_logic_vector(3 downto 0);
    start: in std_logic;
    S : out std_logic_vector(7 downto 0);
    clk : in std_logic;
    rst : in std_logic
    );
  end component;

begin
  asm2_inst: entity work.ASM2
    port map (
      A     => A,
      B     => B,
      start => start,
      S     => S,
      clk   => clk,
      rst   => rst
    );

  clk_process :process
  begin
    clk <= '0';
    wait for clk_period/2;
    clk <= '1';
    wait for clk_period/2;
  end process;

  stim_proc: process
  begin		
    -- hold reset state for 100 ns.
    wait for 100 ns;	
    rst <= '1';
       
    wait for clk_period;
    rst <= '0';

    A <= "1001";
    B <= "0110";
    start <= '1';
    wait for clk_period * 2;
    start <= '0';
    wait;
  end process;
end architecture;