#include <utils.h>

//elemanları boyutuna göre id ata
void	set_id_with_bubble_sort(t_stack *stack_a)
{
	int i;
	int j;
	int len;
	int idx;

	i = 0;
	len = stack_a->top+1;
	while (i < len)
	{
		j = 0;
		idx = 0;
		while (j < len)
		{
			if (stack_a->data[i] > stack_a->data[j])
			{
				idx++;
			}
			j++;
		}
		stack_a->id[i]= idx;
		i++;
	}
}
