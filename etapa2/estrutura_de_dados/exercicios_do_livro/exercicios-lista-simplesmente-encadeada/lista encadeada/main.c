#include "linkedList.h"

int main(){

    t_list lista;

    lista = list_randomList(20, 0, 5);
    list_print(lista);
    //list_removeElement(&lista, 10);
    //list_print(lista);
    list_removeRepeated(&lista);
    list_print(lista);
    return 0;
}
