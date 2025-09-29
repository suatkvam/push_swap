#include "utils.h"


static void	quiet_ra(t_stack *stack_data_a, t_id_list *id_list)
{
	int i, first, first_id, first_val;
	if (stack_data_a->top < 1)
		return ;

	first = stack_data_a->data[stack_data_a->top];
	first_id = id_list->id[stack_data_a->top];
	first_val = id_list->data_value[stack_data_a->top];

	i = stack_data_a->top;
	while (i > 0)
	{
		stack_data_a->data[i] = stack_data_a->data[i - 1];
		id_list->id[i] = id_list->id[i - 1];
		id_list->data_value[i] = id_list->data_value[i - 1];
		i--;
	}

	stack_data_a->data[0] = first;
	id_list->id[0] = first_id;
	id_list->data_value[0] = first_val;
}

static void	quiet_rb(t_stack *stack_data_b, t_id_list *id_list)
{
	int i, first, first_id, first_val;
	if (stack_data_b->top < 1)
		return ;

	first = stack_data_b->data[stack_data_b->top];
	first_id = id_list->id[stack_data_b->top];
	first_val = id_list->data_value[stack_data_b->top];

	i = stack_data_b->top;
	while (i > 0)
	{
		stack_data_b->data[i] = stack_data_b->data[i - 1];
		id_list->id[i] = id_list->id[i - 1];
		id_list->data_value[i] = id_list->data_value[i - 1];
		i--;
	}

	stack_data_b->data[0] = first;
	id_list->id[0] = first_id;
	id_list->data_value[0] = first_val;
}
void	rr(t_stack *stack_data_a, t_stack *stack_data_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	quiet_ra(stack_data_a, id_list_a);
	quiet_rb(stack_data_b, id_list_b);

	write(1, "rr\n", 3);
}
