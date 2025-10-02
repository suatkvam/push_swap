/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:11:18 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 18:11:19 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils/utils.h"
#include "algorithms/algorithms.h"
#include "parser/parser.h"

static void	free_all_resources(t_push_swap_data *data)
{
	free_id_list(&data->id_list_a);
	free_id_list(&data->id_list_b);
	free_stack(&data->a);
	free_stack(&data->b);
	if (data->copy_arr)
		free(data->copy_arr);
	if (data->parsed_args)
		free_split_args(data->parsed_args);
}

int	main(int argc, char **argv)
{
	t_push_swap_data	data;

	init_push_swap_data(&data, argc, argv);
	prepare_sorting_context(&data);
	if (!is_sorted(&data.a, &data.id_list_a))
		start_alg(&data.ctx, data.a.top + 1);
	free_all_resources(&data);
	return (0);
}
