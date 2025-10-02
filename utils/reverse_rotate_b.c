/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:19:52 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 17:19:53 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rrb(t_stack *stack_data_b, t_id_list *id_list)
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
	write(1, "rrb\n", 4);
}
