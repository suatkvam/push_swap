/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_position.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:45:38 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:45:39 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_min_info	find_min(t_stack *stack)
{
	t_min_info	result;
	int			i;

	if (!stack || stack->top < 0)
	{
		result.value = 0;
		result.pos = -1;
		return (result);
	}
	result.value = stack->data[0];
	result.pos = 0;
	i = 1;
	while (i <= stack->top)
	{
		if (stack->data[i] < result.value)
		{
			result.value = stack->data[i];
			result.pos = i;
		}
		i++;
	}
	return (result);
}
