#include "utils.h"
void ra(t_stack *s_data_a)
{
    int fist_element;

     if (s_data_a->top < 1)
        return;
    fist_element = s_data_a->data[s_data_a->top];
    while (s_data_a->top > 0)
    {
        s_data_a->data[s_data_a->top] = s_data_a->data[s_data_a->top - 1];
        s_data_a->top--;
    }
    s_data_a->data[0] = fist_element;
}