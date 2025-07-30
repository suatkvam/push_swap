#include "utils.h"
void rb(t_stack *s_data_b)
{
    int fist_element;

     if (s_data_b->top < 1)
        return;
    fist_element = s_data_b->data[s_data_b->top];
    while (s_data_b->top > 0)
    {
        s_data_b->data[s_data_b->top] = s_data_b->data[s_data_b->top - 1];
        s_data_b->top--;
    }
    s_data_b->data[0] = fist_element;
}
