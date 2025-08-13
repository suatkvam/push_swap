#include "utils.h"

void	rrb(t_stack *s_data_b)
{
	int i;
	int last_element;

	if (s_data_b->top < 1)
		return ;
	last_element = s_data_b->data[0];
	i = 0;
	while (i < s_data_b->top)
	{
		s_data_b->data[i] = s_data_b->data[i + 1];
		i++;
	}
	s_data_b->data[s_data_b->top] = last_element;
}
