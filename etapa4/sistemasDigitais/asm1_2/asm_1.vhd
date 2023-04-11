library IEEE;
use IEEE.STD_LOGIC_1164.ALL;
use IEEE.NUMERIC_STD.ALL;

entity asm_1 is
	generic (
		w : natural := 8
  	);
    Port ( A : in  STD_LOGIC_VECTOR (w-1 downto 0);
           B : out  STD_LOGIC_VECTOR (w-1 downto 0);
           start : in  STD_LOGIC;
		   clk : in  STD_LOGIC;
           rst : in  STD_LOGIC);
end asm_1;

architecture Behavioral of asm_1 is
type t_state is (s1, s2, s3);
signal state : t_state;
signal lda, shr, inc : std_logic;
signal rega, regb : std_logic_vector(w-1 downto 0);
begin
	
	process(rst, clk)
	begin
		if rst = '1' then
			regA <= (others => '0');
		elsif rising_edge(clk) then
			if lda = '1' then
				regA <= A;
			elsif shr = '1' then
				regA(w-2 downto 0) <= regA(w-1 downto 1);
				regA(w-1) <= '0';
			end if;
		else
			regA <= regA;
		end if;
	end process;
	
	process(rst, clk)
	begin
		if rst = '1' then
			regB <= (others => '0');
		elsif rising_edge(clk) then
			if inc = '1' then
				regB <= std_logic_vector(unsigned(regB) + 1);
			end if;
		else
			regB <= regB;
		end if;
	end process;
	
	process(clk, rst, state)
	begin
		lda <= '0';
		shr <= '0';
		inc <= '0';

		if rst = '1' then
            state <= s1;
        elsif rising_edge(clk) then
            case state is
                when s1 =>
                    regB <= (others => '0');
                    if start = '1' then
                        state <= s2;
                    else
                        lda <= '1';
                    end if;
                when s2 =>
                    shr <= '1';
                    if regA = (regA'range => '0') then
                        state <= s3;
                    elsif regA(0) = '0' then
                        inc <= '1';
                    end if;
                when s3 =>
                    if start = '0' then
                        state <= s1;
                    end if;
            end case;
        end if;
    end process;
	B <= regB;
				

end Behavioral;

