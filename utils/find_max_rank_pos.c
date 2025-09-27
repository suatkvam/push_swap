#include "utils.h"

/*
** find_max_rank_pos
** ------------------
** id_list->id dizisinde (0=bottom..top=top) en büyük rank'ın (id)
** indeksini döndürür. Boş ise -1 döner.
*/
int find_max_rank_pos(t_stack *stack, t_id_list *ids)
{
    int i;
    int max_id;
    int max_pos;

    if (!stack || stack->top < 0)
        return (-1);
    max_id = ids->id[0];
    max_pos = 0;
    i = 1;
    while (i <= stack->top)
    {
        if (ids->id[i] > max_id)
        {
            max_id = ids->id[i];
            max_pos = i;
        }
        i++;
    }
    return (max_pos);
}
