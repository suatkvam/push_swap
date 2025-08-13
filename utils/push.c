#include "utils.h"

void	push(t_stack *s_data, int value)
{
	if (s_data->top >= s_data->capacity - 1)
		exit_error();
	s_data->data[++(s_data->top)] = value;
}
