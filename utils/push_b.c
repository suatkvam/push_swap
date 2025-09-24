#include "utils.h"

void	pb(t_stack *s_data_a, t_stack *s_data_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	int	value;
	int	id;
	int	val;

	if (s_data_a->top < 0)
		return ;
	pop(s_data_a, id_list_a, &value, &id, &val);
	push(s_data_b, id_list_b, value, id, val);
	write(1, "pb\n", 3);
}
