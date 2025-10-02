/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:45:16 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 15:45:21 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include "algorithms.h"

static int	process_single_rotation(t_sort_context *ctx, int current_chunk,
		int chunk_size, int chunk_count)
{
	int	rank;
	int	chunk_index;

	rank = ctx->id_list_a->id[ctx->stack_a->top];
	chunk_index = rank / chunk_size;
	if (chunk_index >= chunk_count)
		chunk_index = chunk_count - 1;
	if (chunk_index == current_chunk)
	{
		pb(ctx->stack_a, ctx->stack_b, ctx->id_list_a, ctx->id_list_b);
		rotate_b_after_push(ctx);
		return (1);
	}
	else
	{
		ra(ctx->stack_a, ctx->id_list_a);
		return (0);
	}
}

static void	process_chunks(t_sort_context *ctx, int chunk_size, int chunk_count)
{
	int	current_chunk;
	int	rotations;
	int	stack_size;

	current_chunk = 0;
	while (ctx->stack_a->top >= 0 && current_chunk < chunk_count)
	{
		rotations = 0;
		stack_size = ctx->stack_a->top + 1;
		while (rotations < stack_size)
		{
			if (process_single_rotation(ctx, current_chunk,
					chunk_size, chunk_count))
				break ;
			rotations++;
		}
		if (all_elements_in_chunk_done(ctx, current_chunk, chunk_size,
				chunk_count))
			current_chunk++;
	}
}

void	init_chunk(t_sort_context *ctx)
{
	int	chunk_count;
	int	chunk_size;

	setup_chunk_parameters(ctx, &chunk_count, &chunk_size);
	process_chunks(ctx, chunk_size, chunk_count);
	push_back_from_b(ctx);
}
