/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:15:15 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 14:15:16 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include "algorithms.h"

static void	rotate_a_min_to_top(t_stack *a, t_id_list *ida, int pos)
{
	int	top;
	int	ra_count;
	int	rra_count;

	if (pos < 0)
		return ;
	top = a->top;
	ra_count = top - pos;
	rra_count = pos + 1;
	if (ra_count <= rra_count)
		while (ra_count-- > 0)
			ra(a, ida);
	else
		while (rra_count-- > 0)
			rra(a, ida);
}

static void	sort_two(t_stack *stack_a, t_id_list *id_list)
{
	if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
		sa(stack_a, id_list);
}

static void	sort_three(t_stack *stack_a, t_id_list *id_list)
{
	int	a;
	int	b;
	int	c;

	a = id_list->id[stack_a->top];
	b = id_list->id[stack_a->top - 1];
	c = id_list->id[stack_a->top - 2];
	if (a > b && b > c)
	{
		sa(stack_a, id_list);
		rra(stack_a, id_list);
	}
	else if (a > b && a > c && b < c)
		ra(stack_a, id_list);
	else if (a > b && a < c)
		sa(stack_a, id_list);
	else if (a < b && a < c && b > c)
	{
		sa(stack_a, id_list);
		ra(stack_a, id_list);
	}
	else if (a < b && a > c)
		rra(stack_a, id_list);
}

static void	small_sort_upto_20(t_sort_context *ctx)
{
	int	size;
	int	pos;

	size = ctx->stack_a->top + 1;
	while (size > 3)
	{
		pos = find_min_id_pos(ctx->stack_a, ctx->id_list_a);
		rotate_a_min_to_top(ctx->stack_a, ctx->id_list_a, pos);
		pb(ctx->stack_a, ctx->stack_b, ctx->id_list_a, ctx->id_list_b);
		if (ctx->stack_b->top >= 1 && ctx->id_list_b->id[ctx->stack_b->top]
			< ctx->id_list_b->id[ctx->stack_b->top - 1])
			sb(ctx->stack_b, ctx->id_list_b);
		size--;
	}
	if (size == 3)
		sort_three(ctx->stack_a, ctx->id_list_a);
	else if (size == 2)
		sort_two(ctx->stack_a, ctx->id_list_a);
	while (ctx->stack_b->top >= 0)
		pa(ctx->stack_a, ctx->stack_b, ctx->id_list_a, ctx->id_list_b);
}

void	start_alg(t_sort_context *ctx, int list_size)
{
	if (list_size == 2)
		sort_two(ctx->stack_a, ctx->id_list_a);
	else if (list_size == 3)
		sort_three(ctx->stack_a, ctx->id_list_a);
	else if (list_size <= 20)
	{
		small_sort_upto_20(ctx);
	}
	else if (list_size > 20 && list_size <= 100)
	{
		init_chunk(ctx);
	}
	else
	{
		radix_sort(ctx);
	}
}
