
#include "utils.h"

void	sb(t_stack *s_data_b, t_id_list *id_list)
{
	int	temp;
	int	temp_id;
	int	temp_id_val;

	if (s_data_b->top < 1)
		return ;
	temp = s_data_b->data[s_data_b->top];
	s_data_b->data[s_data_b->top] = s_data_b->data[s_data_b->top - 1];
	s_data_b->data[s_data_b->top - 1] = temp;
	temp_id = id_list->id[s_data_b->top];
	id_list->id[s_data_b->top] = id_list->id[s_data_b->top - 1];
	id_list->id[s_data_b->top - 1] = temp_id;
	temp_id_val = id_list->data_value[s_data_b->top];
	id_list->data_value[s_data_b->top] = id_list->data_value[s_data_b->top - 1];
	id_list->data_value[s_data_b->top - 1] = temp_id_val;
	write(1, "sb\n", 3);
}
