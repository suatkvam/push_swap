#include "utils.h"

void	pb(t_stack *s_data_a, t_stack *s_data_b)
{
	if (s_data_a->top < 0)
		return ;
	push(s_data_b, pop(s_data_a));
	write(1,"pb\n",3);

}
