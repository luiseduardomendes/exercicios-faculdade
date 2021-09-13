#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#define MAX_LETTERS 27
#define TAM_PHRASE 101

int main() {
    setlocale(LC_CTYPE, "");
    int i = 0, j = 0;
    char phrase[TAM_PHRASE], encoded_phrase[TAM_PHRASE];
    char original[MAX_LETTERS], encoded[MAX_LETTERS];

    printf("Insira os valores para uma tabela de correspondência\n");
    
    printf("Insira todas as letras que deseja que sejam alteradas: \n");
    fgets(original, MAX_LETTERS, stdin);
    
    __fpurge(stdin);

    printf("Insira por qual letra, respectivamente, cada uma delas deve ser trocada: \n");
    fgets(encoded, MAX_LETTERS, stdin);
    
    printf("Insira uma frase de até 100 caracteres: \n");
    fgets(phrase, TAM_PHRASE, stdin);

    while (phrase[i] != '\0'){
        if (phrase[i] > 'a' && phrase[i] < 'z'){
            while (phrase[i] != original[j] && j < MAX_LETTERS) {
                j ++;
            }
            if (phrase[i] == original[j]) {
                encoded_phrase[i] = encoded[j];
            }
            else {
                encoded_phrase[i] = phrase[i];
            }
            
            j = 0;
        }
        else {
            encoded_phrase[i] = phrase[i];
        }
        i ++;
    }
    printf("%d", i);
    encoded_phrase[i] = '\0';

    printf("\nA frase digitada codificada: %s\n\n", encoded_phrase);

    return 0;
}
