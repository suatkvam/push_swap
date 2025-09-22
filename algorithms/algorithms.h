#ifndef ALGORITHMS_H
# define ALGORITHMS_H
# include "utils.h"

typedef struct s_stack t_stack;     // Forward declaration
typedef struct s_id_list t_id_list; // Forward declaration
/* ID assignment function */
void	assign_rank(t_stack *stack_a, t_id_list *id_list, int *sorted_arr);

	int is_sorted(t_stack *stack_data, t_id_list *id_list_data);
int		calculate_chunk_count(int list_size);
int		*copy_stack_to_Arry(t_stack *stack_a);
void	quick_sort(int *cp_arr, int left, int right);
int		binary_search(int *cp_arr, int size, int value);

#endif
