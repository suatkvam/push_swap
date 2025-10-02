/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 18:09:52 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 18:09:52 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** utils/utils.h
** -------------
** Stack ve ID listesi veri yapıları ile çekirdek operasyonların prototipleri.
*/
#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "../error/error.h"
# include "../parser/parser.h"

typedef struct s_stack
{
	int	*data;
	int	top;
	int	capacity;
}	t_stack;

typedef struct s_id_list
{
	int	*data_value;
	int	*id;
}	t_id_list;

typedef struct s_min_info
{
	int	value;
	int	pos;
}	t_min_info;

typedef struct s_pop_data
{
	int	value;
	int	id;
	int	data_value;
}	t_pop_data;

typedef struct s_sort_context
{
	t_stack		*stack_a;
	t_id_list	*id_list_a;
	t_stack		*stack_b;
	t_id_list	*id_list_b;
}	t_sort_context;

typedef struct s_push_swap_data
{
	t_stack			a;
	t_stack			b;
	t_id_list		id_list_a;
	t_id_list		id_list_b;
	int				*copy_arr;
	t_sort_context	ctx;
	char			**parsed_args;
}	t_push_swap_data;

typedef struct s_stack_pair
{
	t_stack		*stack_a;
	t_id_list	*id_list_a;
	t_stack		*stack_b;
	t_id_list	*id_list_b;
}	t_stack_pair;

t_min_info	find_min(t_stack *stack_a);
int			find_min_id(t_stack *stack_a, t_id_list *id_list_a);
int			find_min_id_pos(t_stack *stack_a, t_id_list *id_list_a);
void		init_id_list(t_id_list *t_id_data, int capacity);
long long	ft_atoll(const char *str);
void		free_split_args(char **args);
int			find_position_of_max(t_stack *stack);
int			find_max_rank_pos(t_stack *stack, t_id_list *ids);
void		init_stack(t_stack *s_data, int capacity);
void		push(t_stack *s_data, t_id_list *id_list, t_pop_data data);
t_pop_data	pop(t_stack *s_data, t_id_list *id_list);
void		free_stack(t_stack *s_data);
void		free_id_list(t_id_list *id_list);
void		sa(t_stack *stack_data_a, t_id_list *id_list);
void		sb(t_stack *stack_data_b, t_id_list *id_list);
void		ss(t_stack_pair *stacks);
void		pa(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
				t_id_list *id_list_b);
void		pb(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
				t_id_list *id_list_b);
void		ra(t_stack *stack_data_a, t_id_list *id_list);
void		rb(t_stack *stack_data_b, t_id_list *id_list);
void		rr(t_stack_pair *stacks);
void		rra(t_stack *stack_data_a, t_id_list *id_list);
void		rrb(t_stack *stack_data_b, t_id_list *id_list);
void		rrr(t_stack_pair *stacks);

#endif
