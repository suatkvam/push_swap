
#include "utils.h"

void	rrr(t_stack *a, t_stack *b, t_id_list *ida, t_id_list *idb)
{
	int i;
	int last, last_id, last_val;

	if (a->top >= 1)
	{
		last = a->data[0];
		last_id = ida->id[0];
		last_val = ida->data_value[0];
		i = 0;
		while (i < a->top)
		{
			a->data[i] = a->data[i + 1];
			ida->id[i] = ida->id[i + 1];
			ida->data_value[i] = ida->data_value[i + 1];
			i++;
		}
		a->data[a->top] = last;
		ida->id[a->top] = last_id;
		ida->data_value[a->top] = last_val;
	}

	if (b->top >= 1)
	{
		last = b->data[0];
		last_id = idb->id[0];
		last_val = idb->data_value[0];
		i = 0;
		while (i < b->top)
		{
			b->data[i] = b->data[i + 1];
			idb->id[i] = idb->id[i + 1];
			idb->data_value[i] = idb->data_value[i + 1];
			i++;
		}
		b->data[b->top] = last;
		idb->id[b->top] = last_id;
		idb->data_value[b->top] = last_val;
	}

	write(1, "rrr\n", 4);
}