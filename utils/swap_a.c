/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 19:32:34 by akivam            #+#    #+#             */
/*   Updated: 2025/07/30 19:32:38 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void sa(t_stack *s_data_a)
{
    int temp;

    if(s_data_a->top < 1)
        return ;
    temp = s_data_a->data[s_data_a->top];
    s_data_a->data[s_data_a->top] = s_data_a->data[s_data_a->top - 1];
    s_data_a->data[s_data_a->top - 1] = temp;
}
