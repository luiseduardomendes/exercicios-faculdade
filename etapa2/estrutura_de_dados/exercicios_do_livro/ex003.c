#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char name[100];
    char address[100];
    int phone;
} Person;

Person createNewPerson();
void removePersonByPosition(Person people[], int position, int *numPeople);
void removePersonByName(Person people[], char *name, int *numPeople);

int main(){
    Person person[100];
    int numPeople = 0;

    do {
        person[numPeople] = createNewPerson();
        numPeople ++;
    } while(person[numPeople - 1].phone != 0);

    int position;

    do{
        for (int i = 0; i < numPeople; i ++){
            printf("Nome: %s\n", person[i].name);
            printf("Endereco: %s\n", person[i].address);
            printf("Telefone: %d\n\n", person[i].phone);
        }
        printf("Insira a posicao de uma pessoa a ser removida: ");
        scanf("%d", &position);
        fflush(stdin);
        if (position != -1)
            removePersonByPosition(person, position, &numPeople);
    } while (position != -1);
    
    char personDeleted[100];

    do{
        for (int i = 0; i < numPeople; i ++){
            printf("Nome: %s\n", person[i].name);
            printf("Endereco: %s\n", person[i].address);
            printf("Telefone: %d\n\n", person[i].phone);
        }
        printf("Insira o nome de uma pessoa a ser removida: ");
        fgets(personDeleted, 100, stdin);
        fflush(stdin);
        if (strcmp(personDeleted, "") != 0)
            removePersonByName(person, personDeleted, &numPeople);
    } while (strcmp(personDeleted, "") != 0);
    
    return 0;
}

Person createNewPerson(){
    Person p;

    
    
    printf("Insira o nome: ");
    fgets(p.name, 100, stdin);
 
    printf("Insira o endereco: ");
    fgets(p.address, 100, stdin);
    
    printf("Insira o numero de telefone: ");
    scanf("%d", &p.phone);
    int c;

    while ( (c = getchar()) != '\n' && c != EOF ) { }

    return p;
}

void removePersonByPosition(Person people[], int position, int *numPeople){
    for(int i = position; i < *numPeople - 1; i ++)
        people[i] = people [i+1];
}

void removePersonByName(Person people[], char *name, int *numPeople){
    for(int i = 0; i < *numPeople - 1; i ++)
        if (strcmp(people[i].name, name) == 0) {
            for (int j = i; j < *numPeople; j ++){
                people[j] = people [j + 1];
            }
        }
}