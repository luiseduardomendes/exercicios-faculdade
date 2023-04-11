library ieee ;
    use ieee.std_logic_1164.all ;
    use ieee.numeric_std.all ;

entity asm2_t2_tb is
end asm2_t2_tb ; 

architecture arch of asm2_t2_tb is
    component matrix_op is
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
      end component ; 
      
    signal boundary : std_logic_vector(15 downto 0);
    signal start : std_logic;
    signal done : std_logic;
    signal a11 : std_logic_vector(7 downto 0);
    signal a12 : std_logic_vector(7 downto 0);
    signal a21 : std_logic_vector(7 downto 0);
    signal a22 : std_logic_vector(7 downto 0);
    signal b11 : std_logic_vector(7 downto 0);
    signal b12 : std_logic_vector(7 downto 0);
    signal b21 : std_logic_vector(7 downto 0);
    signal b22 : std_logic_vector(7 downto 0);
    signal c11 : std_logic_vector(7 downto 0);
    signal c12 : std_logic_vector(7 downto 0);
    signal c21 : std_logic_vector(7 downto 0);
    signal c22 : std_logic_vector(7 downto 0);
    signal d11 : std_logic_vector(7 downto 0);
    signal d12 : std_logic_vector(7 downto 0);
    signal d21 : std_logic_vector(7 downto 0);
    signal d22 : std_logic_vector(7 downto 0);
    signal s11 : std_logic_vector(15 downto 0);
    signal s12 : std_logic_vector(15 downto 0);
    signal s21 : std_logic_vector(15 downto 0);
    signal s22 : std_logic_vector(15 downto 0);
    signal clk : std_logic;
    signal rst : std_logic;
    constant clk_period: time := 10 ns;
begin
    matrix_op_inst: entity work.matrix_op
      port map (
        boundary => boundary,
        start    => start,
        done     => done,
        a11      => a11,
        a12      => a12,
        a21      => a21,
        a22      => a22,
        b11      => b11,
        b12      => b12,
        b21      => b21,
        b22      => b22,
        c11      => c11,
        c12      => c12,
        c21      => c21,
        c22      => c22,
        d11      => d11,
        d12      => d12,
        d21      => d21,
        d22      => d22,
        s11      => s11,
        s12      => s12,
        s21      => s21,
        s22      => s22,
        clk      => clk,
        rst      => rst
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
        boundary <= std_logic_vector(50);

        a11 <= std_logic_vector(1);
        a12 <= std_logic_vector(4);
        a21 <= std_logic_vector(6);
        a22 <= std_logic_vector(3);
        b11 <= std_logic_vector(2);
        b12 <= std_logic_vector(3);
        b21 <= std_logic_vector(7);
        b22 <= std_logic_vector(2);
        c11 <= std_logic_vector(1);
        c12 <= std_logic_vector(5);
        c21 <= std_logic_vector(3);
        c22 <= std_logic_vector(5);
        d11 <= std_logic_vector(6);
        d12 <= std_logic_vector(3);
        d21 <= std_logic_vector(7);
        d22 <= std_logic_vector(4);
        start <= '1';
        
        
        wait;
      end process;
end architecture ;