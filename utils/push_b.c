/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:05:30 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 17:05:31 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	pb(t_stack *stack_a, t_stack *stack_b,
	t_id_list *id_list_a, t_id_list *id_list_b)
{
	t_pop_data	data;

	if (stack_a->top < 0)
		return ;
	data = pop(stack_a, id_list_a);
	push(stack_b, id_list_b, data);
	write(1, "pb\n", 3);
}
