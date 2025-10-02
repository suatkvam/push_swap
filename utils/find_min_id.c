/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_id.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:45:08 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:45:15 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	find_min_id(t_stack *stack_a, t_id_list *id_list_a)
{
	int	i;
	int	min_id;

	if (!stack_a || stack_a->top < 0)
		return (-1);
	min_id = id_list_a->id[0];
	i = 1;
	while (i <= stack_a->top)
	{
		if (id_list_a->id[i] < min_id)
			min_id = id_list_a->id[i];
		i++;
	}
	return (min_id);
}

int	find_min_id_pos(t_stack *stack_a, t_id_list *id_list_a)
{
	int	i;
	int	min_id;
	int	min_pos;

	if (!stack_a || stack_a->top < 0)
		return (-1);
	min_id = id_list_a->id[0];
	min_pos = 0;
	i = 1;
	while (i <= stack_a->top)
	{
		if (id_list_a->id[i] < min_id)
		{
			min_id = id_list_a->id[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}
