#include "utils.h"

int	find_insertion_point(t_stack *stack_a, int value)
{
	int	i;
	int	position;

	i = stack_a->top;
	position = 0;
	// Use id[] instead of data[]
	while (i >= 0)
	{
		if (stack_a->id[i] < value)
		{
			position = stack_a->top - i;
			break ;
		}
		i--;
	}
	return (position);
}

void	rotate_to_min(t_stack *stack_a)
{
	int	min_pos;

	min_pos = find_min_position(stack_a);
	if (min_pos <= stack_a->top / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a);
	}
	else
	{
		min_pos = stack_a->top + 1 - min_pos;
		while (min_pos-- > 0)
			rra(stack_a);
	}
}

// Find position of minimum element in stack
int	find_min_position(t_stack *stack_a)
{
	int	min_pos;
	int	i;

	int min_val = stack_a->id[stack_a->top]; // Use id[] instead of data[]
	min_pos = 0;
	for (i = stack_a->top; i >= 0; i--)
	{
		if (stack_a->id[i] < min_val) // Use id[] instead of data[]
		{
			min_val = stack_a->id[i];
			min_pos = stack_a->top - i;
		}
	}
	return (min_pos);
}
