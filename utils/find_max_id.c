#include "utils.h"

/*
** find_position_of_max
** --------------------
** Verilen stack içinde (index 0 = bottom, index top = top) en büyük
** data değerine sahip elemanın indeksini döndürür.
** Boş ise -1 döner.
*/
int	find_position_of_max(t_stack *stack)
{
	int i;
	int max_val;
	int max_pos;

	if (!stack || stack->top < 0)
		return (-1);
	max_val = stack->data[0];
	max_pos = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->data[i] > max_val)
		{
			max_val = stack->data[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}
