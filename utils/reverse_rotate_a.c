#include "utils.h"

void	rra(t_stack *s_data_a)
{
	int	i;
	int	last_element;

	if (s_data_a->top < 1)
		return ;
	last_element = s_data_a->data[0];
	i = 0;
	while (i < s_data_a->top)
	{
		s_data_a->data[i] = s_data_a->data[i + 1];
		i++;
	}
	s_data_a->data[s_data_a->top] = last_element;
	write(1,"rra\n",4);

}

