#include "algorithms.h"
#include "utils.h"

// !bu başka fonksiyonla birleşicek
void	sort_five_and_under(t_stack *stack_a, t_id_list *id_list, int list_size)
{
	if (list_size == 2)
	{
		if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
			sa(stack_a, id_list);
	}
	// else if (list_size >= 3 && list_size <= 5)
	// {
	// 	while (!is_sorted(stack_a, id_list))
	// 	{
	// 		if (id_list->id[stack_a->top] > id_list->id[stack_a->top - 1])
	// 			sa(stack_a, id_list);
	// 		if (!is_sorted(stack_a, id_list))
	// 			ra(stack_a, id_list);
	// 	}
	// }
}
