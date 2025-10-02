/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:45:00 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 20:49:44 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include "algorithms.h"

void	prepare_sorting_context(t_push_swap_data *data)
{
	quick_sort(data->copy_arr, 0, data->a.top);
	assign_rank(&data->a, &data->id_list_a, data->copy_arr);
	data->ctx.stack_a = &data->a;
	data->ctx.id_list_a = &data->id_list_a;
	data->ctx.stack_b = &data->b;
	data->ctx.id_list_b = &data->id_list_b;
}
