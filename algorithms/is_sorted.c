/*
** algorithms/is_sorted.c
** ----------------------
** Stack’in hedef sırada olup olmadığını rank’lara bakarak kontrol eder.
** Hedef: TOP -> BOTTOM artan değer; bu da bottom->top ID’lerin sıkı azalan
** olması demektir.
*/
#include "algorithms.h"

int	is_sorted(t_stack *stack_data, t_id_list *id_list_data)
{
	int i;
	i = 0;
	// Sorted means: ascending from TOP to BOTTOM.
	// With our storage (index 0 = bottom, index top = top), that
	// corresponds to IDs strictly decreasing from bottom->top.
	// So if we ever see id[i] < id[i+1] (i.e., not decreasing), it's unsorted.
	while (i < stack_data->top)
	{
		if (id_list_data->id[i] < id_list_data->id[i + 1])
			return (0);
		i++;
	}
	return (1);
}
