# Prova 1

## Questões antigas:

---
1. Qual a frequência nomianl de operação, em MHz, de uma memória DDR-SDRAM com a especificação PC2700? 
* 166
---
1. Se um determinado processador possui uma memória cache de nível 2 de 512 Kbytes de tamanho, com tamanho de linha (line size) de 64 bytes e com operação "8-way set associative", isto significa que: (assinale todas as afirmativas corretas)

 - [x] O tamanho de bloco utilizado tanto na cache quanto na memória principal é de 64 bytes.

 correto pois é informado na questão que o tamanho de linha, ou seja, de bloco, é de 64 bytes.
 - [ ] A cache utiliza mapeamento direto com blocos de 512 bytes (8-way x 64 bytes)
  
  falso pois "8-way associative set" se refere a uma memória de grupo associativo
 - [x] A cache utiliza mapeamento grupo-associativo, sendo cada grupo formado por 8 blocos
 
  Verdadeiro pois 8-way associative se refere ao número de grupos em que a memória é subdivida
 - [ ] A cache utiliza mapeamento grupo-associativo, onde cada grupo ocupa 64Kbytes (512Kbytes/8) na cache.

falso pois cada grupo ocupa 64 bytes. 
 - [ ] A cache utiliza mapeamento associativo para no máximo 8 regiões de memória, cada uma de 64 Kbytes (512 Kbytes/8)

falso pois ela utiliza mapeamento grupo-associativo.

---

3. Um barramento hipotético, projetado para operar com frequencias entre 200 e 250 MHz, possui uma largura de dados de 64 bits, e permite a realização de 2 transferências de dados por ciclo de relógio. Qual a taxa de transferência máxima (teórica) que pode ser obtida com esse barramento, em Mbytes/s?

$T =$ taxa de transferência

$f =$ frequência $= 250 \cdot 10^6$ MHz

$\lambda =$ largura de dados $= 64$ bits $= 8$ bytes

 $T = 2 \cdot f \cdot \lambda$

 $T = 2 \cdot 250 \cdot 10^6 \cdot 8$

$T = 4000$ Mbytes/s
