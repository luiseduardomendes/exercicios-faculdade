library ieee ;
    use ieee.std_logic_1164.all ;
    use ieee.numeric_std.all ;

entity ASM2 is
  port (
    A : in std_logic_vector(3 downto 0);
    B : in std_logic_vector(3 downto 0);
    start: in std_logic;

    S : out std_logic_vector(7 downto 0);

    clk : in std_logic;
    rst : in std_logic
  ) ;
end ASM2 ; 

architecture arch of ASM2 is
  component asm2_po is
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
  end component;

  component asm2_pc is
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
  end component;

  signal load: std_logic;
  signal sh: std_logic;
  signal ad: std_logic;
  signal m: std_logic;
  signal k: std_logic;

begin
  asm2_po_inst: asm2_po
    port map (
      A    => A,
      B    => B,
      load => load,
      sh   => sh,
      ad   => ad,
      m    => m,
      k    => k,
      S    => S,
      clk  => clk,
      rst  => rst
    ); 
  asm2_pc_inst: asm2_pc
    port map (
      start => start,
      m     => m,
      k     => k,
      load  => load,
      sh    => sh,
      ad    => ad,
      clk   => clk,
      rst   => rst
    );

end architecture;