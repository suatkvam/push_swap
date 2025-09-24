#include "utils.h"

void	rb(t_stack *stack_b, t_id_list *id_list)
{
	int i, first, first_id, first_val;
	if (stack_b->top < 1)
		return ;

	first = stack_b->data[stack_b->top];
	first_id = id_list->id[stack_b->top];
	first_val = id_list->data_value[stack_b->top];

	i = stack_b->top;
	while (i > 0)
	{
		stack_b->data[i] = stack_b->data[i - 1];
		id_list->id[i] = id_list->id[i - 1];
		id_list->data_value[i] = id_list->data_value[i - 1];
		i--;
	}

	stack_b->data[0] = first;
	id_list->id[0] = first_id;
	id_list->data_value[0] = first_val;

	write(1, "rb\n", 3);
}