#ifndef UTILS_H
# define UTILS_H

# include "../libft/libft.h"
# include "error.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*data;
	int		top;
	int		capacity;
}			t_stack;

long long	ft_atoll(const char *str);
void free_split_args(char **args);
void		init_stack(t_stack *s_data, int capacity);
void		push(t_stack *s_data, int value);
int			pop(t_stack *s_data);
void		free_stack(t_stack *s_data);
void		sa(t_stack *s_data_a);
void		sb(t_stack *s_data_b);
void		ss(t_stack *s_data_a, t_stack *s_data_b);
void		pa(t_stack *s_data_b, t_stack *s_data_a);
void		pb(t_stack *s_data_a, t_stack *s_data_b);
void		ra(t_stack *s_data_a);
void		rb(t_stack *s_data_b);
void		rr(t_stack *s_data_a, t_stack *s_data_b);
void		rra(t_stack *s_data_a);
void		rrb(t_stack *s_data_b);
void		rrr(t_stack *s_data_a, t_stack *s_data_b);

#endif