#include "algorithms.h"
#include "utils.h"


static void	rotate_a_min_to_top(t_stack *a, t_id_list *ida, int pos)
{
	int top;
	int ra_count;
	int rra_count;

	if (pos < 0)
		return ;
	top = a->top;
	ra_count = top - pos;
	rra_count = pos + 1;
	if (ra_count <= rra_count)
		while (ra_count-- > 0)
			ra(a, ida);
	else
		while (rra_count-- > 0)
			rra(a, ida);
}

static void	sort_two(t_stack *stack_a, t_id_list *id_list)
{
	if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
		sa(stack_a, id_list);
}

static void	sort_three(t_stack *stack_a, t_id_list *id_list)
{
	int a = id_list->id[stack_a->top];
	int b = id_list->id[stack_a->top - 1];
	int c = id_list->id[stack_a->top - 2];

	if (a > b && b > c)
	{
		sa(stack_a, id_list);
		rra(stack_a, id_list);
	}
	else if (a > b && a > c && b < c)
		ra(stack_a, id_list);
	else if (a > b && a < c)
		sa(stack_a, id_list);
	else if (a < b && a < c && b > c)
	{
		sa(stack_a, id_list);
		ra(stack_a, id_list);
	}
	else if (a < b && a > c)
		rra(stack_a, id_list);
}

static void	small_sort_upto_20(t_stack *a, t_id_list *ida, t_stack *b,
		t_id_list *idb)
{
	int size;

	size = a->top + 1;
	while (size > 3)
	{
		int pos = find_min_id_pos(a, ida);
		rotate_a_min_to_top(a, ida, pos);
		pb(a, b, ida, idb);
		if (b->top >= 1 && idb->id[b->top] < idb->id[b->top - 1])
			sb(b, idb);
		size--;
	}
	if (size == 3)
		sort_three(a, ida);
	else if (size == 2)
		sort_two(a, ida);
	while (b->top >= 0)
		pa(a, b, ida, idb);
}

void	start_alg(t_stack *stack_a, t_id_list *id_list_a, t_stack *stack_b,
		t_id_list *id_list_b, int list_size)
{
	if (list_size == 2)
		sort_two(stack_a, id_list_a);
	else if (list_size == 3)
		sort_three(stack_a, id_list_a);
	else if (list_size <= 20)
	{
		small_sort_upto_20(stack_a, id_list_a, stack_b, id_list_b);
	}
	else if (list_size > 20 && list_size <= 100)
	{
		init_chunk(stack_a, stack_b, id_list_a, id_list_b);
	}
	else
	{
		radix_sort(stack_a, id_list_a, stack_b, id_list_b);
		return ;
	}
}
