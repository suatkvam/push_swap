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

void		init_id_list(t_id_list *t_id_data, int capacity);
long long	ft_atoll(const char *str);
void		free_split_args(char **args);
int			find_position_of_max(t_stack *stack);
void		init_stack(t_stack *s_data, int capacity);
void		push(t_stack *s_data, t_id_list *id_list, int value, int id,
				int data_value);
void		pop(t_stack *s_data, t_id_list *id_list, int *value, int *id,
				int *data_value);
void		free_stack(t_stack *s_data);
void		free_id_list(t_id_list *id_list);
void		sa(t_stack *s_data_a, t_id_list *id_list);
void		sb(t_stack *s_data_b, t_id_list *id_list);
void		ss(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
				t_id_list *id_list_b);
void		pa(t_stack *s_data_a, t_stack *s_data_b, t_id_list *id_list_a,
				t_id_list *id_list_b);
void		pb(t_stack *s_data_a, t_stack *s_data_b, t_id_list *id_list_a,
				t_id_list *id_list_b);
void		ra(t_stack *s_data_a, t_id_list *id_list);
void		rb(t_stack *s_data_b, t_id_list *id_list);
void		rr(t_stack *s_data_a, t_stack *s_data_b, t_id_list *id_list_a,
				t_id_list *id_list_b);
void		rra(t_stack *s_data_a, t_id_list *id_list);
void		rrb(t_stack *s_data_b, t_id_list *id_list);
void		rrr(t_stack *s_data_a, t_stack *s_data_b, t_id_list *id_list_a,
				t_id_list *id_list_b);

#endif