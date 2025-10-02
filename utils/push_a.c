/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:05:03 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 17:05:03 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	pa(t_stack *stack_a, t_stack *stack_b,
	t_id_list *id_list_a, t_id_list *id_list_b)
{
	t_pop_data	data;

	if (stack_b->top < 0)
		return ;
	data = pop(stack_b, id_list_b);
	push(stack_a, id_list_a, data);
	write(1, "pa\n", 3);
}
