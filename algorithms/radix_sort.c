#include "algorithms.h"

// void	add_move(t_steps **step_list, char *step)
// {
// 	t_steps	*new_node;
// 	t_steps	*current;

// 	new_node = malloc(sizeof(t_steps));
// 	if (!new_node)
// 		return ;
// 	new_node->step = ft_strdup(step);
// 	new_node->next = NULL;
// 	if (*step_list == NULL)
// 		*step_list = new_node;
// 	else
// 	{
// 		current = *step_list;
// 		while (current->next != NULL)
// 			current = current->next;
// 		current->next = new_node;
// 	}
// }
int maxelembit(len)
{
    int a = len - 1;
    int bitsize;

    bitsize = 0;
    while (a!=0)
    {
        a = a >> 1;
        bitsize++;
    }
    return bitsize;
}
char* radix_sort(t_stack **a,t_stack **b)
{
    int len = sizeof(t_stack *a) / sizeof(*a[0]);
    int count;
    int max_bit = maxelembit()
    int b = 0;

}
/*
int count = 0;
int b = 0;

char maxelembit(len)
{
    int a = len - 1;
    char bitsize;

    bitsize = 0;
    while (a!=0)
    {
        a = a >> 1;
        bitsize++;
    }
    return bitsize;
}

int maxbit = maxelembit(arr);
while(count < maxbit)
{
    while(a[b])
    {
        if(((a[b] >> count) & 0))
            pb();
        else
            ra();
    }
    while(b.lenght != 0)
    {
        pa();
    }
}



*/