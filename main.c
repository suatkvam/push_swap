
#include "error.h"
#include "libft.h"
#include "utils.h"


static void	fill_stack_from_single_arg(t_stack *stack_a, t_id_list *id_list_a,
		char *arg)
{
	int i;
	int split_data_len;
	char **split_data;
	int value;

	split_data = ft_split(arg, ' ');
	if (!split_data)
		exit(EXIT_FAILURE);
	for (split_data_len = 0; split_data[split_data_len]; split_data_len++)
		;
	init_stack(stack_a, split_data_len);
	init_id_list(id_list_a, stack_a->capacity);
	i = split_data_len - 1;
	while (i >= 0)
	{
		value = (int)ft_atoll(split_data[i]);
		push(stack_a, id_list_a, value, 0, value);
		i--;
	}
	free_split_args(split_data);
}

static void	fill_stack_from_args(t_stack *stack_a, t_id_list *id_list_a,
		char **argv, int argc)
{
	int i;
	int value;
	i = argc - 1;
	init_stack(stack_a, argc - 1);
	init_id_list(id_list_a, stack_a->capacity);
	while (i >= 1)
	{
		value = (int)ft_atoll(argv[i]);
		push(stack_a, id_list_a, value, 0, value);
		i--;
	}
}

static void	fill_stack_a(t_stack *stack_a, t_id_list *id_list_a, char **argv,
		int argc)
{
	if (argc == 2)
		fill_stack_from_single_arg(stack_a, id_list_a, argv[1]);
	else
		fill_stack_from_args(stack_a, id_list_a, argv, argc);
}

static	void free_all(t_id_list id_list_a, t_id_list id_list_b, t_stack stack_a,
		t_stack stack_b)
{
	free_id_list(&id_list_a);
	free_id_list(&id_list_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
}

int	main(int argc, char **argv)
{
	t_stack a;
	t_stack b;
	t_id_list id_list_a;
	t_id_list id_list_b;
	char **args;
	int *copy_arr;

	args = argv;
	check_arguments(argc, argv);
	fill_stack_a(&a, &id_list_a, args, argc);
	init_stack(&b, a.capacity);
	init_id_list(&id_list_b, b.capacity);
	copy_arr = copy_stack_to_Arry(&a);
	if (!copy_arr)
		return (1);
	quick_sort(copy_arr, 0, a.top);
	assign_rank(&a, &id_list_a, copy_arr);
	if (!is_sorted(&a, &id_list_a))
		start_alg(&a, &id_list_a, &b, &id_list_b, a.top + 1);
	else
		free(copy_arr);
	free_all(id_list_a, id_list_b, a, b);
	return (0);
}
