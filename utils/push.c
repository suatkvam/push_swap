/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:41 by akivam            #+#    #+#             */
/*   Updated: 2025/07/30 19:32:42 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void push(t_stack *s_data, int value)
{
    if (s_data->top >= s_data->capacity - 1)
        exit_with_error();
    s_data->data[++(s_data->top)] = value;
}
