#include "utils.h"

void free_stack(t_stack *s_data)
{
    free(s_data->data);
    s_data->data = NULL;
}