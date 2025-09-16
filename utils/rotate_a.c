#include "utils.h"

void	ra(t_stack *s_data_a)
{
	int i;
	int first_element;

	if (s_data_a->top < 1)
		return ;
	first_element = s_data_a->data[s_data_a->top];
	i = s_data_a->top;
	while (i > 0)
	{
		s_data_a->data[i] = s_data_a->data[i - 1];
		i--;
	}
	s_data_a->data[0] = first_element;
	write(1,"ra\n",3);
}
