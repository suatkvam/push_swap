#include "algorithms.h"
#include "utils.h"

/*
			Stack sağa doğru büyüdüğü için, 2 eleman olduğunda ilk eleman top
				- 1,
			ikinci eleman ise top indeksinde bulunuyor.”
			sa(stack_a, id_list);
		*/
// !bu başka fonksiyonla birleşicek
static void sort_two(t_stack *stack_a, t_id_list *id_list)
{
		if (stack_a->data[stack_a->top - 1] > stack_a->data[stack_a->top])
			sa(stack_a, id_list);
}

static void sort_three(t_stack *stack_a, t_id_list *id_list_a)
{
    int a = stack_a->data[stack_a->top];     // en üst
    int b = stack_a->data[stack_a->top - 1]; // ortadaki
    int c = stack_a->data[stack_a->top - 2]; // en alt

    // (3 2 1) → sa + rra
    if (a > b && b > c)
    {
        sa(stack_a, id_list_a);
        rra(stack_a, id_list_a);
    }
    // (3 1 2) → ra
    else if (a > b && a > c && b < c)
        ra(stack_a, id_list_a);
    // (2 1 3) → sa
    else if (a > b && a < c)
        sa(stack_a, id_list_a);
    // (1 3 2) → sa + ra
    else if (a < b && a < c && b > c)
    {
        sa(stack_a, id_list_a);
        ra(stack_a, id_list_a);
    }
    // (2 3 1) → rra
    else if (a < b && a > c)
        rra(stack_a, id_list_a);
}


void start_alg(t_stack *stack_a, t_id_list *id_list,int list_size)
{
	if (list_size == 2)
		sort_two(stack_a, id_list);
	else if (list_size == 3)
		sort_three(stack_a, id_list);
}