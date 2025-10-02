/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_max_rank_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:42:52 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:44:41 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	find_max_rank_pos(t_stack *stack, t_id_list *id_list)
{
	int	i;
	int	max_id;
	int	max_pos;

	if (!stack || stack->top < 0)
		return (-1);
	max_id = id_list->id[0];
	max_pos = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (id_list->id[i] > max_id)
		{
			max_id = id_list->id[i];
			max_pos = i;
		}
		i++;
	}
	return (max_pos);
}
