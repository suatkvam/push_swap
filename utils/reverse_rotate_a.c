/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:19:44 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 17:19:45 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	rra(t_stack *stack_data_a, t_id_list *id_list)
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
	write(1, "rra\n", 4);
}
