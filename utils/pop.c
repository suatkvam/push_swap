#include "utils.h"

void	pop(t_stack *stack, t_id_list *id_list, int *value, int *id,
		int *data_value)
{
	*value = stack->data[stack->top];
	*id = id_list->id[stack->top];
	*data_value = id_list->data_value[stack->top];
	stack->top--;
}
