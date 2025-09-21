#include "algorithms.h"
#include "utils.h"

void	init_chunk(t_stack *stack_a, t_stack *b, t_id_list *id_list)
{
	int	list_size;
	int	chunk_count;
	int	chunk_size;
	int	*sorted_copy_array;
	int	current_chunk;
	int	i;
	int	rank;
	int	chunk_index;

	list_size = stack_a->top + 1;
	chunk_count = calculate_chunk_count(list_size); // kaç chunk
	chunk_size = list_size / chunk_count;           // her chunk boyutu
	current_chunk = 0;
	i = 0;
	sorted_copy_array = copy_stack_to_Arry(stack_a);
	if (!copy_stack_to_Arry)
		return (NULL);
	quick_sort(sorted_copy_array, 0, list_size - 1);
	assign_rank(stack_a, id_list, sorted_copy_array);
	free(sorted_copy_array);
	while (stack_a->top >= 0)
	{
		i = 0;
		while (i <= stack_a->top)
		{
			rank = id_list->id[i];
			chunk_index = rank / chunk_size;
			if (chunk_index >= chunk_count)
				chunk_index = chunk_count - 1;
			if (chunk_index == current_chunk)
			{
				// Eleman current chunk içinde, push stack_b
				push_b(stack_a, stack_b);
				break ; // baştan başla
			}
			else
			{
				// Eleman chunk içinde değil, rotate stack_a
				rotate_a(stack_a);
			}
			i++;
		}
	}
	// Eğer current chunk bitmişse, bir sonraki chunk'a geç
	if (all_elements_in_chunk_done(stack_a, id_list, current_chunk, chunk_size))
		current_chunk++;
}
