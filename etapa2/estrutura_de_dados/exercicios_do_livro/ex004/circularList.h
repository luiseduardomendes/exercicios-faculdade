/* 
 * Author: Luis Eduardo Pereira Mendes
 * Contact: luis.pmendes13@gmail.com
 * Cartao UFRGS: 00333936
*/

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_SIZE_LIST 10
#define NULL_VALUE_ID -1
#define NOT_INITIALIZED_LIST -1
enum {TRAINEE, POLITICAL};

typedef struct {
    int size;
    int indexBeg;
    int indexEnd;
}t_descriptor;

typedef struct {
    char name[10];
    int identifier;
    int role;
}t_data;

void createList(t_data *t_dataList, t_descriptor *descript);
/*
 * Cria uma lista vazia, definindo as variaveis com valores vazios
 * ou flags de indicação de espaço inutilizado, a fim de facilitar
 * os algoritmos. Inicializa o descritor com índices de início e 
 * fim iguais a -1 (ou usando #define NOT_INITIALIZED_LIST -1), além
 * de definir o tamanho como zero.
*/

bool insertElement(t_data *t_dataList, t_descriptor *descript, int position, t_data element);
/*
 * insere um elemento numa posição relativa ao primeiro elemento. Por 
 * exemplo, caso seja inserido a posição 5 e o primeiro elemento esta
 * na posicao 7 do vetor, então o novo elemento será inserido na posicao 
 * 7 + 5 = 12. Antes de realizar a inserção, a lista sera transladada
 * para a direita, ou seja, cada elemento tera um acrescimo de um em sua
 * posicao atual. Caso o indice de inicio da lista esteja em uma posicao
 * posterior ao indice de final da lista, ou que o indice de final da lista
 * se encontre na ultima posicao possivel do vetor, isso significa que 
 * havera um deslocamento que ira necessitar de um tratamento especial.
 * Caso contrario, basta fazer um deslocamento simples com um laco de 
 * repeticao.
 * Caso a lista esteja vazia ou nao inicializada, entao o elemento inserido
 * sera colocado na posicao 0 do vetor, apos a chamada da funcao que cria
 * a lista, caso ela nao esteja inicializada, caso esteja, basta definir
 * os valores do inicio e fim da lista no descritor.
 * O retorno da funcao consiste em uma flag de erro, ou seja, a funcao
 * retorna falso caso a posicao inserida e invalida.
 */

bool appendElement(t_data *t_dataList, t_descriptor descript, t_data element);
/*
 * adiciona um elemento ao final da lista, ou seja, na posicao igual ao  
 * indice de fim acrescentado em um. Caso essa posicao seja igual ao fim
 * do vetor e a lista nao estiver cheia, entao o elemento sera inserido 
 * na posicao 0.
 */

bool removeElement(t_data *t_dataList, t_descriptor *descript, int position);
/*
 * remove o elemento na posicao relativa indicada, ou seja, remove o elemento
 * que se encontra na posicao p a partir do indice de inicio da lista. Após 
 * realizar a remocao, toda a lista e deslocada para a esquerda. Caso o indice
 * de inicio de lista seja maior do que o indice de final de lista, entao  
 * sera necessario realizar um tratamento especial para o deslocamento.
 * Caso a posicao indicada seja maior do que o valor maximo que uma posicao da
 * lista pode assumir ou seja menor que 0, entao a funcao retornara uma flag
 * indicando erro.
 */

t_data consultElementByPos(t_data *t_dataList, t_descriptor *descript, int position);
/*
 * Consulta um elemento a partir de sua posicao. Caso a posicao indicada seja
 * maior que o tamanho atual da lista, ira retornar um elemento vazio com um
 * identificador de valor nulo (#define NULL_VALUE_ID -1). Caso o valor inserido
 * seja menor que zero, a funcao ira devolver o elemento na posicao indicada 
 * pelo indice de fim da lista menos o modulo da posicao inserida. Por exemplo,
 * a chamada da funcao com o parametro -5, com uma lista de tamanho 10 (que vai
 * de 0 ate 9), ira retornar o valor da posicao (9 - 5)
*/

int consultElementById(t_data *t_dataList, t_descriptor *descript, int numberId);
/*
 * Consulta um elemento a partir de seu identificador. Caso o elemento indicado 
 * nao seja encontrado, ira retornar um elemento vazio com um identificador de 
 * valor nulo (#define NULL_VALUE_ID -1)
*/

void setRandElementBegin(t_data *t_dataList, t_descriptor *descript);
/*
 * Define a posicao de um elemento aleatorio que pertenca aos valores de posicoes
 * nao nulas do descritor como elemento inicial da lista. Além disso, tambem 
 * define o ultimo elemento nao nulo a partir de sua posicao inicial (considerando
 * a circularidade da lista) como o ultimo elemento da lista. Por fim, a funcao
 * ajusta os espacos vazios da lista para facilitar sua manipulacao. Ou seja,
 * supondo que temos um vetor (0, 0, 0, 0, 1, 1, 1, 1) em que 0 sao posicoes 
 * invalidas e 1 sao posicoes validas para a lista, se selecionarmos aleatoriamente
 * o penultimo elemento da lista como primeiro elemento, entao teremos um espaco
 * vazio entre o segundo e o terceiro elemento da lista, entao a funcao ira fazer
 * deslocamentos para a esquerda ate que nao sobrem elementos nulos nesse intervalo,
 * ou seja, a funcao ficara com este aspecto ao fim da execucao, com os numeros 
 * indicando seus indices para a lista (2, 3, -1, -1, -1, -1, 0, 1)
*/

int simultaneouslyRemove(t_data *t_dataList, t_descriptor *descript);
/*
 * Remove simultaneamente dois elementos, um com um valor aleatorio k1 que e contado
 * a partir do inicio da lista e um valor aleatorio k2 que sera contado a partir do
 * final da lista, ou seja, possui valor negativo para ser usado na funcao 
 * consultElementByID(). Caso dois elementos diferentes sejam selecionados, o campo
 * role dos elementos recebem um valor definido na enumeracao igual a TRAINEE, caso
 * os dois elementos sejam o mesmo, entao ele recebe o valor POLITICAL.
*/


/* funcoes auxiliares */
bool isElementsTheSame(t_data t_dataList, t_descriptor descript, int pos1, int pos2);
/*
 * retorna valor verdadeiro se as duas posicoes indicadas se referem ao mesmo elemento.
 * e util ja que a lista pode ser indexada na ordem normal, indicando uma posicao 
 * positiva, ou na ordem reversa, com um valor de posicao menor que zero
*/

bool isPositionValid(t_data *t_dataList, t_descriptor descript, int position);
/*
 * verifica se a posicao indicada e valida, ou seja, se o elemento contido nela nao 
 * apresenta o identificador NULL_VALUE_ID == -1
 */

bool isListNotFull(t_descriptor descript);
 /*
 * verifica se o tamanho da lista e menor do que o tamanho total do vetor, utilizada
 * para facilitar a compreensao do codigo
 */

bool isListEmpty(t_descriptor descript); 
/*
 * verifica se o tamanho da lista e igual a zero, utilizada para melhor compreensao do
 * codigo
 */

bool isListInitialized(t_descriptor descript); 
/*
 * verifica se a lista foi inicializada a partir do identificador de lista nao 
 * inicializada no campo de tamanho do descritor
*/

bool shiftListRight(t_data *t_dataList, t_descriptor *descript, int fromWhere);
/*
 * desloca a lista para a direita, retornando erro em caso de lista invalida.
 * desloca a partir de uma posicao inicial deterinada pela chamada da funcao ate
 * alcancar o indice de inicio de lista. Caso o elemento que esta sendo deslocado seja
 * aquele na posicao inicial do vetor, entao o indice utilizado na estrutura de 
 * repeticao recebera valor MAX_SIZE_LIST e o proximo deslocamento ira ocorrer entre o
 * primeiro e o ultimo elementos do vetor (lista[MAX_SIZE_LIST - 1] = lista[0]) e entao 
 * ira prosseguir ate encontrar o indice de inicio de lista
*/

bool shiftListLeft(t_data *t_dataList, t_descriptor *descript, int fromWhere);
/*
 * desloca a lista para a esquerda, retornando erro em caso de lista invalida.
 * desloca a partir de uma posicao inicial deterinada pela chamada da funcao ate
 * alcancar o indice de final de lista. Caso o elemento que esta sendo deslocado seja
 * aquele na posicao final do vetor, entao o indice utilizado na estrutura de repeticao 
 * recebera valor 0 e o proximo deslocamento ira ocorrer entre o primeiro e o ultimo 
 * elementos do vetor (lista[0] = lista[MAX_SIZE_LIST - 1]), e entao ira prosseguir ate 
 * encontrar o indice de final de lista
*/

void displayList(t_data *t_dataList, t_descriptor descriptor);
/*
 * exibe no console os identificadores dos elementos em ordem, desconsiderando a
 * circularidade da lista
*/

void generateRandomList(t_data *t_dataList, t_descriptor *descript);
/*
 * Cria uma lista com valores aleatorios a partir de um descritor definido pelo 
 * parametro da funcao, portanto, caso o usuario insira um descritor com valores de
 * indice inicial e final respectivamente como  4 e 10, entao a lista comecara a partir
 * de 10 e ira ate o fim do vetor, depois ira de 0 ate 4, enquanto incrementa a partir
 * de 0 o campo tamanho da lista
*/
int generateRandomElement(t_descriptor descript);
/*
 * escolhe um elemento aleatorio que seja valido na lista e retorna seu indice relativo
 * a posicao inicial da lista
*/