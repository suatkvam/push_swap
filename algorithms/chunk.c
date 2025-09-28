#include "algorithms.h"
#include "utils.h"


int	all_elements_in_chunk_done(t_stack *stack_a, t_id_list *id_list,
		int current_chunk, int chunk_size, int chunk_count)
{
	int rank;
	int chunk_index;
	int i;

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

static int	find_optimal_position_in_b(t_stack *b, t_id_list *idb, int new_rank)
{
	int i;
	int best_pos = 0;

	if (b->top < 0)
		return (0);
	i = 0;
	while (i <= b->top)
	{
		if (idb->id[i] < new_rank && (i == b->top || idb->id[i + 1] > new_rank))
		{
			best_pos = i + 1;
			break ;
		}
		i++;
	}
	return (best_pos);
}

static void	rotate_b_after_push(t_stack *b, t_id_list *idb)
{
	int current_rank;
	int optimal_pos;
	int rotations_needed;

	if (b->top < 1)
		return ;
	current_rank = idb->id[b->top];
	optimal_pos = find_optimal_position_in_b(b, idb, current_rank);
	if (optimal_pos == b->top)
		return ;
	rotations_needed = b->top - optimal_pos;
	if (rotations_needed > 0 && rotations_needed <= (b->top + 1) / 2)
		while (rotations_needed-- > 0)
			rb(b, idb);
	else if (rotations_needed < 0)
		while (rotations_needed++ < 0)
			rrb(b, idb);
}

static void	calculate_a_rotation_needs(t_stack *a, t_id_list *ida,
		int *ra_needed, int *rra_needed)
{
	*ra_needed = 0;
	*rra_needed = 0;
	if (a->top > 0 && ida->id[a->top] > ida->id[0])
	{
		*ra_needed = 1;
		*rra_needed = 0;
	}
	else if (a->top > 1 && ida->id[a->top] < ida->id[a->top - 1])
	{
		*ra_needed = 0;
		*rra_needed = 1;
	}
}

static void	optimize_rotations_ab(t_stack *a, t_id_list *ida, t_stack *b,
		t_id_list *idb, int rb_count, int rrb_count)
{
	int min_a_rotations = 0;
	int ra_needed = 0;
	int rra_needed = 0;

	calculate_a_rotation_needs(a, ida, &ra_needed, &rra_needed);
	if (rb_count > 0 && ra_needed > 0)
	{
		min_a_rotations = (rb_count < ra_needed) ? rb_count : ra_needed;
		while (min_a_rotations-- > 0)
			rr(a, b, ida, idb);
		rb_count -= min_a_rotations;
	}
	else if (rrb_count > 0 && rra_needed > 0)
	{
		min_a_rotations = (rrb_count < rra_needed) ? rrb_count : rra_needed;
		while (min_a_rotations-- > 0)
			rrr(a, b, ida, idb);
		rrb_count -= min_a_rotations;
	}
	while (rb_count-- > 0)
		rb(b, idb);
	while (rrb_count-- > 0)
		rrb(b, idb);
}

static void	push_back_from_b(t_stack *a, t_id_list *ida, t_stack *b,
		t_id_list *idb)
{
	while (b->top >= 0)
	{
		int max_pos = find_max_rank_pos(b, idb);
		int top = b->top;
		if (max_pos < 0)
			break ;
		int rb_count = top - max_pos;
		int rrb_count = max_pos + 1;
		if (rb_count <= rrb_count)
			optimize_rotations_ab(a, ida, b, idb, rb_count, 0);
		else
			optimize_rotations_ab(a, ida, b, idb, 0, rrb_count);
		pa(a, b, ida, idb);
	}
}

static void	setup_chunk_parameters(t_stack *stack_a, t_id_list *id_list_a,
		int *chunk_count, int *chunk_size)
{
	int list_size;
	int *sorted_copy_array;

	list_size = stack_a->top + 1;
	*chunk_count = calculate_chunk_count(list_size);
	*chunk_size = list_size / *chunk_count;
	sorted_copy_array = copy_stack_to_Arry(stack_a);
	if (!sorted_copy_array)
		return ;
	quick_sort(sorted_copy_array, 0, list_size - 1);
	assign_rank(stack_a, id_list_a, sorted_copy_array);
	free(sorted_copy_array);
}

static int	process_single_rotation(t_stack *stack_a, t_stack *stack_b,
		t_id_list *id_list_a, t_id_list *id_list_b, int current_chunk,
		int chunk_size, int chunk_count)
{
	int rank, chunk_index;

	rank = id_list_a->id[stack_a->top];
	chunk_index = rank / chunk_size;
	if (chunk_index >= chunk_count)
		chunk_index = chunk_count - 1;
	if (chunk_index == current_chunk)
	{
		pb(stack_a, stack_b, id_list_a, id_list_b);
		rotate_b_after_push(stack_b, id_list_b);
		return (1);
	}
	else
	{
		ra(stack_a, id_list_a);
		return (0);
	}
}

static void	process_chunks(t_stack *stack_a, t_stack *stack_b,
		t_id_list *id_list_a, t_id_list *id_list_b, int chunk_size,
		int chunk_count)
{
	int current_chunk = 0;

	while (stack_a->top >= 0 && current_chunk < chunk_count)
	{
		int rotations = 0;
		int stack_size = stack_a->top + 1;
		while (rotations < stack_size)
		{
			if (process_single_rotation(stack_a, stack_b, id_list_a,
					id_list_b, current_chunk, chunk_size, chunk_count))
				break ;
			rotations++;
		}
		if (all_elements_in_chunk_done(stack_a, id_list_a, current_chunk,
				chunk_size, chunk_count))
			current_chunk++;
	}
}

void	init_chunk(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	int chunk_count, chunk_size;

	setup_chunk_parameters(stack_a, id_list_a, &chunk_count, &chunk_size);
	process_chunks(stack_a, stack_b, id_list_a, id_list_b, chunk_size,
		chunk_count);
	push_back_from_b(stack_a, id_list_a, stack_b, id_list_b);
}
