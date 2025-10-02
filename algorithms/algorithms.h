/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:41:18 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 15:41:19 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHMS_H
# define ALGORITHMS_H

typedef struct s_stack			t_stack;
typedef struct s_id_list		t_id_list;
typedef struct s_sort_context	t_sort_context;
typedef struct s_push_swap_data	t_push_swap_data;

void	assign_rank(t_stack *stack_a, t_id_list *id_list, int *sorted_arr);
int		is_sorted(t_stack *stack_data, t_id_list *id_list_data);
int		calculate_chunk_count(int list_size);
int		*copy_stack_to_arry(t_stack *stack_a);
void	quick_sort(int *cp_arr, int left, int right);
int		binary_search(int *cp_arr, int size, int value);
void	init_chunk(t_sort_context *ctx);
void	radix_sort(t_sort_context *ctx);
void	start_alg(t_sort_context *ctx, int list_size);

/* Chunk helper functions */
int		all_elements_in_chunk_done(t_sort_context *ctx, int current_chunk,
			int chunk_size, int chunk_count);
void	rotate_b_after_push(t_sort_context *ctx);
void	push_back_from_b(t_sort_context *ctx);
void	setup_chunk_parameters(t_sort_context *ctx, int *chunk_count,
			int *chunk_size);
void	prepare_sorting_context(t_push_swap_data *data);

#endif
