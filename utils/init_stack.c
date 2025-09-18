#include "utils.h"

void	init_stack(t_stack *s_data, int capacity)
{
	s_data->data = (int *)ft_calloc(capacity, sizeof(int));
	s_data->id = (int *)ft_calloc(capacity,sizeof(int));
	if (!s_data->data || !s_data->id)
		exit_error();
	s_data->top = -1;
	s_data->capacity = capacity;
}
