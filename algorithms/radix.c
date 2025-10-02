/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:38:47 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 15:26:12 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithms.h"
#include "utils.h"

static int	get_max_id(t_sort_context *ctx)
{
	int	i;
	int	max_id;

	i = 1;
	if (!ctx->stack_a || ctx->stack_a->top < 0)
		return (0);
	max_id = ctx->id_list_a->id[0];
	while (i <= ctx->stack_a->top)
	{
		if (ctx->id_list_a->id[i] > max_id)
			max_id = ctx->id_list_a->id[i];
		i++;
	}
	return (max_id);
}

static int	count_bit(int value)
{
	int	bit;

	bit = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		bit++;
		value >>= 1;
	}
	return (bit);
}

static void	process_bit_round(t_sort_context *ctx, int bit)
{
	int	n;
	int	top_id;

	n = ctx->stack_a->top + 1;
	while (n-- > 0)
	{
		top_id = ctx->id_list_a->id[ctx->stack_a->top];
		if (((top_id >> bit) & 1) == 0)
			pb(ctx->stack_a, ctx->stack_b, ctx->id_list_a, ctx->id_list_b);
		else
			ra(ctx->stack_a, ctx->id_list_a);
	}
	while (ctx->stack_b->top >= 0)
		pa(ctx->stack_a, ctx->stack_b, ctx->id_list_a, ctx->id_list_b);
}

void	radix_sort(t_sort_context *ctx)
{
	int	max_id;
	int	counted_bits;
	int	bit;

	max_id = get_max_id(ctx);
	counted_bits = count_bit(max_id);
	bit = 0;
	if (is_sorted(ctx->stack_a, ctx->id_list_a))
		return ;
	while (bit < counted_bits)
	{
		process_bit_round(ctx, bit);
		bit++;
		if (is_sorted(ctx->stack_a, ctx->id_list_a))
			break ;
	}
}
