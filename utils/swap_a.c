
#include "utils.h"

void	sa(t_stack *stack_data_a, t_id_list *id_list)
{
	int	temp;
	int	temp_id;
	int	temp_id_val;

	if (stack_data_a->top < 1)
		return ;
	temp = stack_data_a->data[stack_data_a->top];
	stack_data_a->data[stack_data_a->top] = stack_data_a->data[stack_data_a->top - 1];
	stack_data_a->data[stack_data_a->top - 1] = temp;
	
	temp_id = id_list->id[stack_data_a->top];
	id_list->id[stack_data_a->top] = id_list->id[stack_data_a->top - 1];
	id_list->id[stack_data_a->top - 1] = temp_id;
	
	temp_id_val = id_list->data_value[stack_data_a->top];
	id_list->data_value[stack_data_a->top] = id_list->data_value[stack_data_a->top - 1];
	id_list->data_value[stack_data_a->top - 1] = temp_id_val;
	write(1, "sa\n", 3);
}
