#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#include <ctype.h>
#include "red_black_tree.h"

void ToLower(char *p) {
    while(*p) {
        *p = tolower(*p);
        p ++;
    }
}

#define SIZELINE 1024
#define SIZEWORD 64 

int main(int argc, char **argv){

    setlocale(LC_ALL, "pt_BR");

    rbt_node *root, *node = NULL;
    FILE* file, *input, *output;
    char line[SIZELINE], sep[] = {" ,.&*%\?!;/-'@\"$#=><()][}{:\n\t"};
    char *str, *syn, dict_name[] = {"dict_10k.txt"};
    clock_t start, end;
    root = rbt_init();

    if (argc != 3)
        return -1;

    if (!(file = fopen(dict_name, "r")))
        return -1;

    while (fgets(line, SIZELINE, file)) {
        str = strtok (line, sep); //considera qquer caractere n�o alfab�tico como separador
        syn = strtok (NULL, sep);
        root = rbt_insert(root, str, syn);
    }
    // rbt_print_inorder_left(root);
    
    if (!(input = fopen (argv[1], "r"))) {
        printf ("Erro ao abrir o arquivo %s",argv[1]);
        return 1;
    }
    

    output = fopen (argv[2], "w");

    start = clock(); //inicia a contagem do tempo


    //percorre todo o arquivo lendo linha por linha
    while (fgets(line,SIZELINE,input)) {
        str = strtok (line, sep); //considera qquer caractere n�o alfab�tico como separador
        while (str != NULL) {
            ToLower(str);
            if (node = rbt_search(root, str)){
                printf("%s - %s", node->word, node->synonym);
                fprintf(output,"%s ", node->synonym); 
            }
            else
                fprintf(output,"%s ", str); 
            str = strtok (NULL, sep);
        }
    }

    printf("\nArquivo %s gerado com sucesso.\n",argv[2]);

    end = clock(); // finaliza contagem do tempo
    float miliseconds = (float)(end - start) / CLOCKS_PER_SEC * 1000; //calcula o tempo decorrido
    printf("Tempo: %.5f ms\n",miliseconds);
    
    fclose (input); //fecha os arquivos
    fclose (output);
    return 0;
}
    