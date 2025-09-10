#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "utils.h"
typedef struct s_steps
{
	char			*step;
	struct s_steps	*next;
}					t_steps;
# include "utils.h"
void				insertion_sort(t_stack *a, t_stack *b, t_steps **steps_list,
						int count);
#endif