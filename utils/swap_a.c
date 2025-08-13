#include "utils.h"

void	sa(t_stack *s_data_a)
{
	int	temp;

	if (s_data_a->top < 1)
		return ;
	temp = s_data_a->data[s_data_a->top];
	s_data_a->data[s_data_a->top] = s_data_a->data[s_data_a->top - 1];
	s_data_a->data[s_data_a->top - 1] = temp;
}
