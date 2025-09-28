
#include "utils.h"

void	ra(t_stack *stack_a, t_id_list *id_list)
{
	int i, first, first_id, first_val;
	if (stack_a->top < 1)
		return ;

	first = stack_a->data[stack_a->top];
	first_id = id_list->id[stack_a->top];
	first_val = id_list->data_value[stack_a->top];

	i = stack_a->top;
	while (i > 0)
	{
		stack_a->data[i] = stack_a->data[i - 1];
		id_list->id[i] = id_list->id[i - 1];
		id_list->data_value[i] = id_list->data_value[i - 1];
		i--;
	}

	stack_a->data[0] = first;
	id_list->id[0] = first_id;
	id_list->data_value[0] = first_val;

	write(1, "ra\n", 3);
}