#include "utils.h"

void	rrr(t_stack *s_data_a, t_stack *s_data_b)
{
	rra(s_data_a);
	rrb(s_data_b);
	write(1,"rrb\n",4);
}
