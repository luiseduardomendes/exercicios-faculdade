#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Date
{
    int day;
    int month;
    int year;
} Date;

Date createDate(char* text);

int main(){
    Date date;
    char *textInput;

    fgets(textInput, 100, stdin);
    createDate(textInput);

    return 0;
}

Date createDate(char* text){
    Date d;
    d.day = atoi(strtok(text, "/ ."));
    d.month = atoi(strtok(NULL, "/ ."));
    d.year = atoi(strtok(NULL, "/ ."));

    printf("%d/%d/%d", d.day, d.month, d.year);
    return d;

}
