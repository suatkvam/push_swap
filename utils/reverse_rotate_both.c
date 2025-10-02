/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_both.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:24:55 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 17:24:57 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	quiet_rra(t_stack *stack_data_a, t_id_list *id_list)
{
	int	i;
	int	last_element;
	int	last_id;
	int	last_value;

	if (stack_data_a->top < 1)
		return ;
	last_element = stack_data_a->data[0];
	last_id = id_list->id[0];
	last_value = id_list->data_value[0];
	i = 0;
	while (i < stack_data_a->top)
	{
		stack_data_a->data[i] = stack_data_a->data[i + 1];
		id_list->id[i] = id_list->id[i + 1];
		id_list->data_value[i] = id_list->data_value[i + 1];
		i++;
	}
	stack_data_a->data[stack_data_a->top] = last_element;
	id_list->id[stack_data_a->top] = last_id;
	id_list->data_value[stack_data_a->top] = last_value;
}

static void	quiet_rrb(t_stack *stack_data_b, t_id_list *id_list)
{
	int	i;
	int	last;
	int	last_id;
	int	last_val;

	if (stack_data_b->top < 1)
		return ;
	last = stack_data_b->data[0];
	last_id = id_list->id[0];
	last_val = id_list->data_value[0];
	i = 0;
	while (i < stack_data_b->top)
	{
		stack_data_b->data[i] = stack_data_b->data[i + 1];
		id_list->id[i] = id_list->id[i + 1];
		id_list->data_value[i] = id_list->data_value[i + 1];
		i++;
	}
	stack_data_b->data[stack_data_b->top] = last;
	id_list->id[stack_data_b->top] = last_id;
	id_list->data_value[stack_data_b->top] = last_val;
}

void	rrr(t_stack_pair *stacks)
{
	quiet_rra(stacks->stack_a, stacks->id_list_a);
	quiet_rrb(stacks->stack_b, stacks->id_list_b);
	write(1, "rrr\n", 4);
}
