#include "utils.h"

void	ss(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	sa(stack_a, id_list_a);
	sb(stack_b, id_list_b);
	write(1, "ss\n", 3);
}
