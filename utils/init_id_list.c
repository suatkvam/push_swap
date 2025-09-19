#include "utils.h"

void	init_id_list(t_id_list *t_id_data, int capacity)
{
	t_id_data->data_value = (int *)ft_calloc(capacity, sizeof(int));
	t_id_data->id = (int *)ft_calloc(capacity, sizeof(int));
	if (!(t_id_data->data_value || t_id_data->id))
		exit_error();
}
