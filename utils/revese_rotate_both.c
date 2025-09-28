
#include "utils.h"


static void	silent_rra(t_stack *s_data_a, t_id_list *id_list)
{
	int i;
	int last_element;
	int last_id;
	int last_value;

	if (s_data_a->top < 1)
		return ;
	last_element = s_data_a->data[0];
	last_id = id_list->id[0];
	last_value = id_list->data_value[0];
	i = 0;
	while (i < s_data_a->top)
	{
		s_data_a->data[i] = s_data_a->data[i + 1];
		id_list->id[i] = id_list->id[i + 1];
		id_list->data_value[i] = id_list->data_value[i + 1];
		i++;
	}
	s_data_a->data[s_data_a->top] = last_element;
	id_list->id[s_data_a->top] = last_id;
	id_list->data_value[s_data_a->top] = last_value;
}
static void	silent_rrb(t_stack *stack_b, t_id_list *id_list)
{
	int i;
	int last;
	int last_id;
	int last_val;

	if (stack_b->top < 1)
		return ;

	last = stack_b->data[0];
	last_id = id_list->id[0];
	last_val = id_list->data_value[0];

	i = 0;
	while (i < stack_b->top)
	{
		stack_b->data[i] = stack_b->data[i + 1];
		id_list->id[i] = id_list->id[i + 1];
		id_list->data_value[i] = id_list->data_value[i + 1];
		i++;
	}

	stack_b->data[stack_b->top] = last;
	id_list->id[stack_b->top] = last_id;
	id_list->data_value[stack_b->top] = last_val;
}

void	rrr(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	silent_rra(stack_a, id_list_a);
	silent_rrb(stack_b, id_list_b);
	write(1, "rrr\n", 4);
}
