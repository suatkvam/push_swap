#include "algorithms.h"

void	add_move(t_steps **step_list, char *step)
{
	t_steps	*new_node;
	t_steps	*current;

	new_node = malloc(sizeof(t_steps));
	if (!new_node)
		return ;
	new_node->step = ft_strdup(step);
	new_node->next = NULL;
	if (*step_list == NULL)
		*step_list = new_node;
	else
	{
		current = *step_list;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
	}
}
#include "algorithms.h"

void	insertion_sort(t_stack *a, t_stack *b, t_steps **steps_list, int count)
{
	int	i;
	int	target_index;
	int	cost_rb;
	int	cost_rrb;

	// Aşama 1: A'daki tüm elemanları B'ye it.
	i = 0;
	while (i < count)
	{
		pb(a, b);
		add_move(steps_list, "pb");
		i++;
	}
	// Aşama 2: Sıralı olarak A'ya geri çek.
	while (b->top > -1)
	{
		target_index = find_position_of_max(b);
		cost_rb = b->top - target_index;
		cost_rrb = target_index + 1;
		if (cost_rb <= cost_rrb)
		{
			i = 0;
			while (i++ < cost_rb)
			{
				rb(b);
				add_move(steps_list, "rb");
			}
		}
		else
		{
			i = 0;
			while (i++ < cost_rrb)
			{
				rrb(b);
				add_move(steps_list, "rrb");
			}
		}
		pa(a, b);
		add_move(steps_list, "pa");
	}
}
