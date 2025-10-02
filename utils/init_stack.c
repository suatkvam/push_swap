/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:48:48 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:48:49 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_stack(t_stack *s_data, int capacity)
{
	s_data->data = (int *)ft_calloc(capacity, sizeof(int));
	if (!s_data->data)
		exit_error();
	s_data->top = -1;
	s_data->capacity = capacity;
}
