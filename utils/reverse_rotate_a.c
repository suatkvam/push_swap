#include "utils.h"

void	rra(t_stack *s_data_a, t_id_list *id_list)
{
	int	i;
	int	last_element;
	int	last_id;
	int	last_value;

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
	write(1, "rra\n", 4);
}
