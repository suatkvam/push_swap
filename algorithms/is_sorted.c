#include "algorithms.h"

int	is_sorted(t_stack *stack_data, t_id_list *id_list_data)
{
	int i;
	i = 0;
	while (i < stack_data->top)
	{
		if (id_list_data->id[i] > id_list_data->id[i + 1])
			return (0);
		i++;
	}
	return (1);
}