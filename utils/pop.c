/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:49:03 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:49:04 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_pop_data	pop(t_stack *stack, t_id_list *id_list)
{
	t_pop_data	data;

	data.value = stack->data[stack->top];
	data.id = id_list->id[stack->top];
	data.data_value = id_list->data_value[stack->top];
	stack->top--;
	return (data);
}
