/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:05:57 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 18:05:58 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	sb(t_stack *stack_data_b, t_id_list *id_list)
{
	int	temp;
	int	temp_id;
	int	temp_id_val;

	if (stack_data_b->top < 1)
		return ;
	temp = stack_data_b->data[stack_data_b->top];
	stack_data_b->data[stack_data_b->top]
		= stack_data_b->data[stack_data_b->top - 1];
	stack_data_b->data[stack_data_b->top - 1] = temp;
	temp_id = id_list->id[stack_data_b->top];
	id_list->id[stack_data_b->top] = id_list->id[stack_data_b->top - 1];
	id_list->id[stack_data_b->top - 1] = temp_id;
	temp_id_val
		= id_list->data_value[stack_data_b->top];
	id_list->data_value[stack_data_b->top]
		= id_list->data_value[stack_data_b->top - 1];
	id_list->data_value[stack_data_b->top - 1] = temp_id_val;
	write(1, "sb\n", 3);
}
