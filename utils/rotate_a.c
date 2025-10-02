/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 17:33:20 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 17:33:21 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ra(t_stack *stack_data_a, t_id_list *id_list)
{
	int	i;
	int	first;
	int	first_id;
	int	first_val;

	if (stack_data_a->top < 1)
		return ;
	first = stack_data_a->data[stack_data_a->top];
	first_id = id_list->id[stack_data_a->top];
	first_val = id_list->data_value[stack_data_a->top];
	i = stack_data_a->top;
	while (i > 0)
	{
		stack_data_a->data[i] = stack_data_a->data[i - 1];
		id_list->id[i] = id_list->id[i - 1];
		id_list->data_value[i] = id_list->data_value[i - 1];
		i--;
	}
	stack_data_a->data[0] = first;
	id_list->id[0] = first_id;
	id_list->data_value[0] = first_val;
	write(1, "ra\n", 3);
}
