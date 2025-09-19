#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "algorithms.h"
# include "error.h"
# include "parser.h"

typedef struct s_stack
{
	int		*data;
	int		top;
	int		capacity;
}			t_stack;

typedef struct s_id_list
{
	int		*data_value;
	int		*id;
}			t_id_list;

void		init_id_list(t_id_list *t_id_data, int cpacity);
long long	ft_atoll(const char *str);
void		free_split_args(char **args);
int			find_position_of_max(t_stack *stack);
void		init_stack(t_stack *s_data, int capacity);
void		push(t_stack *s_data, int value);
int			pop(t_stack *s_data);
void		free_stack(t_stack *s_data);
void		sa(t_stack *s_data_a);
void		sb(t_stack *s_data_b);
void		ss(t_stack *s_data_a, t_stack *s_data_b);
void		pa(t_stack *s_data_a, t_stack *s_data_b);
void		pb(t_stack *s_data_a, t_stack *s_data_b);
void		ra(t_stack *s_data_a);
void		rb(t_stack *s_data_b);
void		rr(t_stack *s_data_a, t_stack *s_data_b);
void		rra(t_stack *s_data_a);
void		rrb(t_stack *s_data_b);
void		rrr(t_stack *s_data_a, t_stack *s_data_b);

#endif