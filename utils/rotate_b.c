#include "utils.h"

void	rb(t_stack *s_data_b)
{
	int i;
	int first_element;

	if (s_data_b->top < 1)
		return ;
	first_element = s_data_b->data[s_data_b->top];
	i = s_data_b->top;
	while (i > 0)
	{
		s_data_b->data[i] = s_data_b->data[i - 1];
		i--;
	}
	s_data_b->data[0] = first_element;
	write(1,"rb\n",3);
}
