/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_helpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:30:00 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 16:29:26 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include "algorithms.h"

int	all_elements_in_chunk_done(t_sort_context *ctx, int current_chunk,
		int chunk_size, int chunk_count)
{
	int	rank;
	int	chunk_index;
	int	i;

	i = 0;
	while (i <= ctx->stack_a->top)
	{
		rank = ctx->id_list_a->id[i];
		chunk_index = rank / chunk_size;
		if (chunk_index >= chunk_count)
			chunk_index = chunk_count - 1;
		if (chunk_index == current_chunk)
			return (0);
		i++;
	}
	return (1);
}

void	rotate_b_after_push(t_sort_context *ctx)
{
	if (ctx->stack_b->top >= 1 && ctx->id_list_b->id[ctx->stack_b->top]
		< ctx->id_list_b->id[ctx->stack_b->top - 1])
		sb(ctx->stack_b, ctx->id_list_b);
	if (ctx->stack_b->top >= 2 && ctx->id_list_b->id[ctx->stack_b->top]
		< ctx->id_list_b->id[ctx->stack_b->top - 2])
		rb(ctx->stack_b, ctx->id_list_b);
}

void	push_back_from_b(t_sort_context *ctx)
{
	int	max_pos;
	int	top;
	int	rb_count;
	int	rrb_count;

	while (ctx->stack_b->top >= 0)
	{
		max_pos = find_max_rank_pos(ctx->stack_b, ctx->id_list_b);
		top = ctx->stack_b->top;
		if (max_pos < 0)
			break ;
		rb_count = top - max_pos;
		rrb_count = max_pos + 1;
		if (rb_count <= rrb_count)
			while (rb_count-- > 0)
				rb(ctx->stack_b, ctx->id_list_b);
		else
			while (rrb_count-- > 0)
				rrb(ctx->stack_b, ctx->id_list_b);
		pa(ctx->stack_a, ctx->stack_b, ctx->id_list_a, ctx->id_list_b);
	}
}

void	setup_chunk_parameters(t_sort_context *ctx, int *chunk_count,
		int *chunk_size)
{
	int	list_size;
	int	*sorted_copy_array;

	list_size = ctx->stack_a->top + 1;
	*chunk_count = calculate_chunk_count(list_size);
	*chunk_size = list_size / *chunk_count;
	sorted_copy_array = copy_stack_to_arry(ctx->stack_a);
	if (!sorted_copy_array)
		return ;
	quick_sort(sorted_copy_array, 0, list_size - 1);
	assign_rank(ctx->stack_a, ctx->id_list_a, sorted_copy_array);
	free(sorted_copy_array);
}
