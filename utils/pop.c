#include "utils.h"

int	pop(t_stack *s_data)
{
	return (s_data->data[s_data->top--]);
}
