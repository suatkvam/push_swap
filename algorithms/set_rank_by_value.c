#include "algorithms.h"
#include "utils.h"

// elemanları boyutuna göre id ata
void	set_rank_by_value(t_stack *stack_a, t_id_list *id_list)
{
	int	i;
	int	j;
	int	len;
	int	idx;

	i = 0;
	len = stack_a->top + 1;
	while (i < len)
	{
		idx = 0;
		j = 0;
		while (j < len)
		{
			if (stack_a->data[i] > stack_a->data[j])
				idx++;	
			j++;
		}
		id_list->id[i] = idx;                         // id saklama
		id_list->data_value[i] = stack_a->data[i]; // id ile değeride alıyor
		i++;
	}
}
