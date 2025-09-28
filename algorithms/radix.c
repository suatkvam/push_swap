
#include "algorithms.h"
#include "utils.h"

static int	get_max_id(t_stack *stack_a, t_id_list *id_list_a)
{
	int	i;
	int	max_id;

	i = 1;
	if (!stack_a || stack_a->top < 0)
		return (0);
	max_id = id_list_a->id[0];
	while (i <= stack_a->top)
	{
		if (id_list_a->id[i] > max_id)
			max_id = id_list_a->id[i];
		i++;
	}
	return (max_id);
}

static int	count_bit(int value)
{
	int	bit;

	bit = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		bit++;
		value >>= 1;
	}
	return (bit);
}

static void	process_bit_round(t_stack *stack_a, t_id_list *id_list_a,
		t_stack *stack_b, t_id_list *id_list_b, int bit)
{
	int	n;
	int	top_id;

	n = stack_a->top + 1;
	while (n-- > 0)
	{
		top_id = id_list_a->id[stack_a->top];
		if (((top_id >> bit) & 1) == 0)
			pb(stack_a, stack_b, id_list_a, id_list_b);
		else
			ra(stack_a, id_list_a);
	}
	while (stack_b->top >= 0)
		pa(stack_a, stack_b, id_list_a, id_list_b);
}

void	radix_sort(t_stack *stack_a, t_id_list *id_list_a, t_stack *stack_b,
		t_id_list *id_list_b)
{
	int	max_id;
	int	counted_bits;
	int	bit;

	max_id = get_max_id(stack_a, id_list_a);
	counted_bits = count_bit(max_id);
	bit = 0;
	if (is_sorted(stack_a, id_list_a))
		return ;
	while (bit < counted_bits)
	{
		process_bit_round(stack_a, id_list_a, stack_b, id_list_b, bit);
		bit++;
		if (is_sorted(stack_a, id_list_a))
			break ;
	}
}
