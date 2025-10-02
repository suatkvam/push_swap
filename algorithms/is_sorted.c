/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 14:40:37 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 14:40:38 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "algorithms.h"

int	is_sorted(t_stack *stack_data, t_id_list *id_list_data)
{
	int	i;

	i = 0;
	while (i < stack_data->top)
	{
		if (id_list_data->id[i] < id_list_data->id[i + 1])
			return (0);
		i++;
	}
	return (1);
}
