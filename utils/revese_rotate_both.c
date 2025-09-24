#include "utils.h"

void	rrr(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	rra(stack_a, id_list_a);
	rrb(stack_b, id_list_b);
	write(1, "rrr\n", 4);
}