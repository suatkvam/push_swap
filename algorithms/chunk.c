#include "algorithms.h"
#include "utils.h"

int	all_elements_in_chunk_done(t_stack *stack_a, t_id_list *id_list,
		int current_chunk, int chunk_size, int chunk_count)
{
	int	rank;
	int	chunk_index;
	int	i;

	i = 0;
	while (i <= stack_a->top)
	{
		rank = id_list->id[i];
		chunk_index = rank / chunk_size;
		if (chunk_index >= chunk_count)
			chunk_index = chunk_count - 1;
		if (chunk_index == current_chunk)
			return (0);
		i++;
	}
	return (1);
}

void	init_chunk(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	int	list_size;
	int	chunk_count;
	int	chunk_size;
	int	current_chunk;
	int	*sorted_copy_array;
	int	i;
	int	rank;
	int	chunk_index;

	list_size = stack_a->top + 1;
	chunk_count = calculate_chunk_count(list_size);
	chunk_size = list_size / chunk_count;
	current_chunk = 0;
	sorted_copy_array = copy_stack_to_Arry(stack_a);
	if (!sorted_copy_array)
		return ;
	quick_sort(sorted_copy_array, 0, list_size - 1);
	assign_rank(stack_a, id_list_a, sorted_copy_array);
	free(sorted_copy_array);
	while (stack_a->top >= 0 && current_chunk < chunk_count)
	{
		i = 0;
		while (i <= stack_a->top)
		{
			rank = id_list_a->id[i];
			chunk_index = rank / chunk_size;
			if (chunk_index >= chunk_count)
				chunk_index = chunk_count - 1;
			if (chunk_index == current_chunk)
			{
				pb(stack_a, stack_b, id_list_a, id_list_b);
				break ;
			}
			else
			{
				ra(stack_a, id_list_a);
			}
			i++;
		}
		if (all_elements_in_chunk_done(stack_a, id_list_a, current_chunk,
				chunk_size, chunk_count))
			current_chunk++;
	}
}
