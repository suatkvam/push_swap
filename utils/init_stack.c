#include "utils.h"

void	init_stack(t_stack *s_data, int capacity)
{
	s_data->data = (int *)ft_calloc(capacity - 1, sizeof(int));
	if (!s_data->data)
		exit_error();
	s_data->top = -1;
	s_data->capacity = capacity;
}
