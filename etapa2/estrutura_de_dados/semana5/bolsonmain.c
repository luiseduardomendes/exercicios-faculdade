#include "doubly_linked_list.h"

t_info_node encontraMeio(t_node* fila)
{
    t_node* ptAux1 = fila, *ptAux2;

    for(ptAux2 = fila; ptAux2->next != NULL; ptAux2 = ptAux2->next);

    while((ptAux1 != ptAux2) && (ptAux1->next != ptAux2))
    {
        ptAux1 = ptAux1->next;
        ptAux2 = ptAux2->prev;
    }

    return ptAux1->info;
}
