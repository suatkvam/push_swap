#include <utils.h>

// index için
void	set_id_with_bubble_sort(t_stack *arr, int len)
{
	int i;
	int j;
	int idx;

	idx = 0;
	i = 0;
	while (i < len - 1)
	{
        j = 0;
		arr[i].id = 0;
		while (j < len - 1 - i)
		{
			if (arr[i] > arr[j])
			{
				id[idx] = arr[i] = arr[j];
				idx++;
			}
			j++;
		}
		i++;
	}
}
