#include "utils.h"

void	free_id_list(t_id_list *id_list)
{
	if (!id_list)
		return ;
	free(id_list->id);
	id_list->id = NULL;
	free(id_list->data_value);
	id_list->data_value = NULL;
}
