#include "algorithms.h"
#include "utils.h"

/*
			Stack sağa doğru büyüdüğü için, 2 eleman olduğunda ilk eleman top
				- 1,
			ikinci eleman ise top indeksinde bulunuyor.”
			sa(stack_a, id_list);
		*/
// !bu başka fonksiyonla birleşicek
void	sort_five_and_under(t_stack *stack_a, t_id_list *id_list, int list_size)
{
	if (list_size == 2)
	{
		if (stack_a->data[stack_a->top - 1] > stack_a->data[stack_a->top])
			sa(stack_a, id_list);
	}
	else // Örnek 3 elemanlı minimal swap/rotate
		if (list_size == 3)
	{
	}
}
