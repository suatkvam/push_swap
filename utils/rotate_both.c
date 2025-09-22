#include "utils.h"

void rr(t_stack *s_data_a, t_stack *s_data_b, t_id_list *id_list_a, t_id_list *id_list_b)
{
    ra(s_data_a, id_list_a);
    rb(s_data_b, id_list_b);
    write(1, "rr\n", 3);
}
