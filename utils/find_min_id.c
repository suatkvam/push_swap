#include "utils.h"

// Return the smallest rank (id) present in stack a
int	find_min_id(t_stack *a, t_id_list *ida)
{
    int i;
    int min_id;

    if (!a || a->top < 0)
        return -1;
    min_id = ida->id[0];
    i = 1;
    while (i <= a->top)
    {
        if (ida->id[i] < min_id)
            min_id = ida->id[i];
        i++;
    }
    return min_id;
}

// Return the index (0..top, where 0 is bottom and top is top) of the smallest rank (id)
int	find_min_id_pos(t_stack *a, t_id_list *ida)
{
    int i;
    int min_id;
    int min_pos;

    if (!a || a->top < 0)
        return -1;
    min_id = ida->id[0];
    min_pos = 0;
    i = 1;
    while (i <= a->top)
    {
        if (ida->id[i] < min_id)
        {
            min_id = ida->id[i];
            min_pos = i;
        }
        i++;
    }
    return min_pos;
}
