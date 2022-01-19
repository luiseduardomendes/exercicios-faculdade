#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "DateManipulation.h"

int main(){
    Date date1, date2, date, bufferDate;
    int year = 2022;
    char text [100];

    printf("Insira um ano que deseja saber quando ocorrera a pascoa: ");
    fgets(text, 10, stdin);
    year = atoi(text);
    //scanf("%d", &year);
    //fflush(stdin);    

    bufferDate = easterDay(year);
    displayDateStdin(bufferDate);

    printf("Insira uma data: ");
    do{
        fgets(text, 100, stdin);
        fflush(stdin);
        date1 = createDateByText(text);
        if (!isDateValid(date1))
            printf("data inserida invalida, tente novamente:\n");
    } while (!isDateValid(date1));

    printf("Insira outra data: ");
    do{
        scanf("%d %d %d", &bufferDate.day, &bufferDate.month, &bufferDate.year);
        date2 = createDate(bufferDate.day, bufferDate.month, bufferDate.year);
        if (!isDateValid(date2))
            printf("data inserida invalida, tente novamente:\n");
    } while (!isDateValid(date2));

    printf("Datas inseridas: \n");
    displayDateStdin(date1);
    displayDateStdin(date2);
    printf("\n");

    printf("O periodo entre as duas datas eh de %d dias\n\n", daysBetween(date1, date2));

    return 0;
}
