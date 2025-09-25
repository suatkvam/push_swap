#include "utils.h"

void	ss(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	int temp;
	int temp_id;
	int temp_val;

	if (stack_a->top >= 1)
	{
		temp = stack_a->data[stack_a->top];
		stack_a->data[stack_a->top] = stack_a->data[stack_a->top - 1];
		stack_a->data[stack_a->top - 1] = temp;
		temp_id = id_list_a->id[stack_a->top];
		id_list_a->id[stack_a->top] = id_list_a->id[stack_a->top - 1];
		id_list_a->id[stack_a->top - 1] = temp_id;
		temp_val = id_list_a->data_value[stack_a->top];
		id_list_a->data_value[stack_a->top] = id_list_a->data_value[stack_a->top - 1];
		id_list_a->data_value[stack_a->top - 1] = temp_val;
	}
	if (stack_b->top >= 1)
	{
		temp = stack_b->data[stack_b->top];
		stack_b->data[stack_b->top] = stack_b->data[stack_b->top - 1];
		stack_b->data[stack_b->top - 1] = temp;
		temp_id = id_list_b->id[stack_b->top];
		id_list_b->id[stack_b->top] = id_list_b->id[stack_b->top - 1];
		id_list_b->id[stack_b->top - 1] = temp_id;
		temp_val = id_list_b->data_value[stack_b->top];
		id_list_b->data_value[stack_b->top] = id_list_b->data_value[stack_b->top - 1];
		id_list_b->data_value[stack_b->top - 1] = temp_val;
	}
	write(1, "ss\n", 3);
}
