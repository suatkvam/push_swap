/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:06:00 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 17:06:02 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	push(t_stack *stack, t_id_list *id_list, t_pop_data data)
{
	stack->data[++stack->top] = data.value;
	id_list->id[stack->top] = data.id;
	id_list->data_value[stack->top] = data.data_value;
}
