#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "utils.h"

typedef struct s_stack t_stack;     // Forward declaration
typedef struct s_id_list t_id_list; // Forward declaration
/* ID assignment function */
void	set_rank_by_value(t_stack *stack_a, t_id_list *id_list);
int		is_sorted(t_stack *stack_data, t_id_list *id_list_data);

#endif
