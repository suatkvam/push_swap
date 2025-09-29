#include "utils.h"


static void	quiet_sa(t_stack *s_data_a, t_id_list *id_list)
{
	int temp;
	int temp_id;
	int temp_id_val;

	if (s_data_a->top < 1)
		return ;
	temp = s_data_a->data[s_data_a->top];
	s_data_a->data[s_data_a->top] = s_data_a->data[s_data_a->top - 1];
	s_data_a->data[s_data_a->top - 1] = temp;
	temp_id = id_list->id[s_data_a->top];
	id_list->id[s_data_a->top] = id_list->id[s_data_a->top - 1];
	id_list->id[s_data_a->top - 1] = temp_id;
	temp_id_val = id_list->data_value[s_data_a->top];
	id_list->data_value[s_data_a->top] = id_list->data_value[s_data_a->top
		- 1];
	id_list->data_value[s_data_a->top - 1] = temp_id_val;
}

void	quiet_sb(t_stack *s_data_b, t_id_list *id_list)
{
	int temp;
	int temp_id;
	int temp_id_val;

	if (s_data_b->top < 1)
		return ;
	temp = s_data_b->data[s_data_b->top];
	s_data_b->data[s_data_b->top] = s_data_b->data[s_data_b->top - 1];
	s_data_b->data[s_data_b->top - 1] = temp;
	temp_id = id_list->id[s_data_b->top];
	id_list->id[s_data_b->top] = id_list->id[s_data_b->top - 1];
	id_list->id[s_data_b->top - 1] = temp_id;
	temp_id_val = id_list->data_value[s_data_b->top];
	id_list->data_value[s_data_b->top] = id_list->data_value[s_data_b->top
		- 1];
	id_list->data_value[s_data_b->top - 1] = temp_id_val;
}
void	ss(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	quiet_sa(stack_a, id_list_a);
	quiet_sb(stack_b, id_list_b);
	write(1, "ss\n", 3);
}
