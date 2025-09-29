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

int	find_optimal_position_in_b(t_stack *stack_b, t_id_list *id_list_b,
		int new_rank)
{
	int	i;
	int	best_pos;

	best_pos = 0;
	if (stack_b->top < 0)
		return (0);
	i = 0;
	while (i <= stack_b->top)
	{
		if (id_list_b->id[i] < new_rank && (i == stack_b->top || id_list_b->id[i
				+ 1] > new_rank))
		{
			best_pos = i + 1;
			break ;
		}
		i++;
	}
	return (best_pos);
}

void	rotate_b_after_push(t_stack *stack_b, t_id_list *id_list_b)
{
	int	current_rank;
	int	optimal_pos;
	int	rotations_needed;

	if (stack_b->top < 1)
		return ;
	current_rank = id_list_b->id[stack_b->top];
	optimal_pos = find_optimal_position_in_b(stack_b, id_list_b, current_rank);
	if (optimal_pos == stack_b->top)
		return ;
	rotations_needed = stack_b->top - optimal_pos;
	if (rotations_needed > 0 && rotations_needed <= (stack_b->top + 1) / 2)
		while (rotations_needed-- > 0)
			rb(stack_b, id_list_b);
	else if (rotations_needed < 0)
		while (rotations_needed++ < 0)
			rrb(stack_b, id_list_b);
}

void	calculate_a_rotation_needs(t_stack *stack_a, t_id_list *id_list_a,
		int *ra_needed, int *rra_needed)
{
	*ra_needed = 0;
	*rra_needed = 0;
	if (stack_a->top > 0 && id_list_a->id[stack_a->top] > id_list_a->id[0])
	{
		*ra_needed = 1;
		*rra_needed = 0;
	}
	else if (stack_a->top > 1 && id_list_a->id[stack_a->top] < id_list_a->id[stack_a->top - 1])
	{
		*ra_needed = 0;
		*rra_needed = 1;
	}
}

void	optimize_rotations_ab(t_stack *stack_a, t_id_list *id_list_a, t_stack *stack_b,
		t_id_list *id_list_b, int rb_count, int rrb_count)
{
	int min_a_rotations = 0;
	int ra_needed = 0;
	int rra_needed = 0;

	calculate_a_rotation_needs(stack_a, id_list_a, &ra_needed, &rra_needed);
	if (rb_count > 0 && ra_needed > 0)
	{
		min_a_rotations = (rb_count < ra_needed) ? rb_count : ra_needed;
		while (min_a_rotations-- > 0)
			rr(stack_a, stack_b, id_list_a, id_list_b);
		rb_count -= min_a_rotations;
	}
	else if (rrb_count > 0 && rra_needed > 0)
	{
		min_a_rotations = (rrb_count < rra_needed) ? rrb_count : rra_needed;
		while (min_a_rotations-- > 0)
			rrr(stack_a, stack_b, id_list_a, id_list_b);
		rrb_count -= min_a_rotations;
	}
	while (rb_count-- > 0)
		rb(stack_b, id_list_b);
	while (rrb_count-- > 0)
		rrb(stack_b, id_list_b);
}