#include "utils.h"

int	find_position_of_max(t_stack *stack)
{
	int max_value;
	int max_position_index;
	int i;

	if (stack->top == -1)
		return (-1);

	max_value = stack->data[0];
	max_position_index = 0;

	i = 1;
	while (i <= stack->top)
	{
		if (stack->data[i] > max_value)
		{
			max_value = stack->data[i];
			max_position_index = i;
		}
		i++;
	}
	return (max_position_index);
}