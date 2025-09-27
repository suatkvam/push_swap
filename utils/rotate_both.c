/*
** rr: A ve B'yi aynı anda rotate eder; içte sessizce uygular, stdout'a "rr" basar.
*/
#include "utils.h"

void rr(t_stack *a, t_stack *b, t_id_list *ida, t_id_list *idb)
{
    int i;
    int first, first_id, first_val;

    // rotate a (silent)
    if (a->top >= 1)
    {
        first = a->data[a->top];
        first_id = ida->id[a->top];
        first_val = ida->data_value[a->top];
        i = a->top;
        while (i > 0)
        {
            a->data[i] = a->data[i - 1];
            ida->id[i] = ida->id[i - 1];
            ida->data_value[i] = ida->data_value[i - 1];
            i--;
        }
        a->data[0] = first;
        ida->id[0] = first_id;
        ida->data_value[0] = first_val;
    }

    // rotate b (silent)
    if (b->top >= 1)
    {
        first = b->data[b->top];
        first_id = idb->id[b->top];
        first_val = idb->data_value[b->top];
        i = b->top;
        while (i > 0)
        {
            b->data[i] = b->data[i - 1];
            idb->id[i] = idb->id[i - 1];
            idb->data_value[i] = idb->data_value[i - 1];
            i--;
        }
        b->data[0] = first;
        idb->id[0] = first_id;
        idb->data_value[0] = first_val;
    }

    write(1, "rr\n", 3);
}
