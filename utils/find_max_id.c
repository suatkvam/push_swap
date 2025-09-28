#include "utils.h"

// TODO: Bu fonksiyon data değerine göre maksimumun pozisyonunu döndürür.
// Rank (id) bazlı maksimum için find_max_rank_pos'u kullan.


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
