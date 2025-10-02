/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:39:54 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:39:55 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "utils.h"

typedef struct s_stack			t_stack;
typedef struct s_id_list		t_id_list;
typedef struct s_push_swap_data	t_push_swap_data;

char	**check_arguments(int argc, char **argv);
void	fill_stack_a(t_stack *stack_a, t_id_list *id_list_a,
			char **parsed_args);
void	init_push_swap_data(t_push_swap_data *data, int argc, char **argv);

#endif
