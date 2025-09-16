#include "utils.h"

void	sb(t_stack *s_data_b)
{
	int	temp;

	if (s_data_b->top < 1)
		return ;
	temp = s_data_b->data[s_data_b->top];
	s_data_b->data[s_data_b->top] = s_data_b->data[s_data_b->top - 1];
	s_data_b->data[s_data_b->top - 1] = temp;
	write(1,"sb\n",3);
}
