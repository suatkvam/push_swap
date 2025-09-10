// #include "utils.h"

// void	pa(t_stack *s_data_b, t_stack *s_data_a)
// {
// 	if (s_data_b->top < 0)
// 		return ;
// 	push(s_data_a, pop(s_data_b));
// }
#include "utils.h"
#include <stdio.h> // EKLE

void	pa(t_stack *s_data_b, t_stack *s_data_a)
{
	int value_to_push;

	if (s_data_b->top < 0)
		return ;
	
	printf("  pa'nın içi: pop'tan ÖNCE b->top = %d\n", s_data_b->top);
	fflush(stdout);

	value_to_push = pop(s_data_b);

	printf("  pa'nın içi: pop'tan SONRA b->top = %d, A'ya itilecek değer = %d\n", s_data_b->top, value_to_push);
	fflush(stdout);
	
	printf("  pa'nın içi: push'tan ÖNCE b->top = %d\n", s_data_b->top);
	fflush(stdout);

	push(s_data_a, value_to_push);

	printf("  pa'nın içi: push'tan SONRA b->top = %d\n", s_data_b->top);
	fflush(stdout);
}