#include"utils.h"

void pa(t_stack *s_data_b, t_stack *s_data_a)
{
    if(s_data_b->top < 0)
        return ;
    push(s_data_a, pop(s_data_b));
}
