/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_and_fill.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 16:45:00 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 20:46:27 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include "../algorithms/algorithms.h"

static int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args && args[count])
		count++;
	return (count);
}

static void	fill_stack_from_split_args(t_stack *stack_a, t_id_list *id_list_a,
		char **args)
{
	int			i;
	int			args_len;
	int			value;
	t_pop_data	data;

	args_len = count_args(args);
	if (args_len == 0)
		return ;
	init_stack(stack_a, args_len);
	init_id_list(id_list_a, stack_a->capacity);
	i = args_len - 1;
	while (i >= 0)
	{
		value = (int)ft_atoll(args[i]);
		data.value = value;
		data.id = 0;
		data.data_value = value;
		push(stack_a, id_list_a, data);
		i--;
	}
}

void	fill_stack_a(t_stack *stack_a, t_id_list *id_list_a, char **parsed_args)
{
	if (!parsed_args)
		exit(EXIT_FAILURE);
	fill_stack_from_split_args(stack_a, id_list_a, parsed_args);
}

void	init_push_swap_data(t_push_swap_data *data, int argc, char **argv)
{
	data->parsed_args = check_arguments(argc, argv);
	fill_stack_a(&data->a, &data->id_list_a, data->parsed_args);
	init_stack(&data->b, data->a.capacity);
	init_id_list(&data->id_list_b, data->b.capacity);
	data->copy_arr = copy_stack_to_arry(&data->a);
	if (!data->copy_arr)
	{
		free_id_list(&data->id_list_a);
		free_id_list(&data->id_list_b);
		free_stack(&data->a);
		free_stack(&data->b);
		if (data->parsed_args)
			free_split_args(data->parsed_args);
		exit(EXIT_FAILURE);
	}
}
