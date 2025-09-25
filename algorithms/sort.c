#include "algorithms.h"
#include "utils.h"


/*
			Stack sağa doğru büyüdüğü için, 2 eleman olduğunda ilk eleman top
				- 1,
			ikinci eleman ise top indeksinde bulunuyor.”
			sa(stack_a, id_list);
		*/
// !bu başka fonksiyonla birleşicek
static void	sort_two(t_stack *stack_a, t_id_list *id_list)
{
	// We want ascending order from TOP to BOTTOM
	// top element should be <= the element below it
	if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
		sa(stack_a, id_list);
}

static void	sort_three(t_stack *stack_a, t_id_list *id_list)
{
	int a = id_list->id[stack_a->top];     // en üst elemanın rank'ı
	int b = id_list->id[stack_a->top - 1]; // ortadaki rank
	int c = id_list->id[stack_a->top - 2]; // en alt rank

	if (a > b && b > c) // 3 2 1 durumuna karşılık
	{
		sa(stack_a, id_list);
		rra(stack_a, id_list);
	}
	else if (a > b && a > c && b < c) // 3 1 2
		ra(stack_a, id_list);
	else if (a > b && a < c) // 2 1 3
		sa(stack_a, id_list);
	else if (a < b && a < c && b > c) // 1 3 2
	{
		sa(stack_a, id_list);
		ra(stack_a, id_list);
	}
	else if (a < b && a > c) // 2 3 1
		rra(stack_a, id_list);
}

void	start_alg(t_stack *stack_a, t_id_list *id_list, int list_size)
{
	if (list_size == 2)
		sort_two(stack_a, id_list);
	else if (list_size == 3)
		sort_three(stack_a, id_list);
}
