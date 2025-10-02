/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:47:33 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:47:34 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	free_stack(t_stack *s_data)
{
	free(s_data->data);
	s_data->data = NULL;
	s_data->top = -1;
	s_data->capacity = 0;
}
