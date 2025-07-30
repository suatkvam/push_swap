/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:27 by akivam            #+#    #+#             */
/*   Updated: 2025/07/30 19:32:32 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void sb(t_stack *s_data_b)
{
    int temp;

    if(s_data_b->top < 1)
        return ;
    temp = s_data_b->data[s_data_b->top];
    s_data_b->data[s_data_b->top] = s_data_b->data[s_data_b->top - 1];
    s_data_b->data[s_data_b->top - 1] = temp;
}
