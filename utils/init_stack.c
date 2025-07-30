/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 18:12:31 by akivam            #+#    #+#             */
/*   Updated: 2025/07/30 18:12:32 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void init_stack(t_stack *s_data, int capacity)
{
   s_data->data = (int *) ft_calloc(capacity - 1 ,sizeof(int));
   if(!s_data->data)
      exit_with_error();
   s_data->top = -1;
   s_data->capacity = capacity;
}
