#include "utils.h"

void	push(t_stack *stack, t_id_list *id_list, int value, int id,
		int data_value)
{
	stack->data[++stack->top] = value;
	id_list->id[stack->top] = id;
	id_list->data_value[stack->top] = data_value;
}
