#include "error.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>

/* argv tek string olarak verildiyse (argc == 2) */
static void	fill_stack_from_single_arg(t_stack *stack_a, t_id_list *id_list_a,
		char *arg)
{
	int		i;
	int		split_data_len;
	char	**split_data;
	int		value;

	split_data = ft_split(arg, ' ');
	if (!split_data)
		exit(EXIT_FAILURE);
	for (split_data_len = 0; split_data[split_data_len]; split_data_len++)
		;
	init_stack(stack_a, split_data_len);
	init_id_list(id_list_a, stack_a->capacity);
	i = 0;
	while (split_data[i])
	{
		value = (int)ft_atoll(split_data[i]);
		push(stack_a, id_list_a, value, 0, value);
		i++;
	}
	free_split_args(split_data);
}

/* argv çoklu argümanlarla geldiyse (argc > 2) */
static void	fill_stack_from_args(t_stack *stack_a, t_id_list *id_list_a,
		char **argv, int argc)
{
	int	i;
	int	value;

	init_stack(stack_a, argc - 1);
	init_id_list(id_list_a, stack_a->capacity);
	for (i = 1; i < argc; i++)
	{
		value = (int)ft_atoll(argv[i]);
		push(stack_a, id_list_a, value, 0, value);
	}
}

/* Dispatcher */
static void	fill_stack_a(t_stack *stack_a, t_id_list *id_list_a, char **argv,
		int argc)
{
	if (argc == 2)
		fill_stack_from_single_arg(stack_a, id_list_a, argv[1]);
	else
		fill_stack_from_args(stack_a, id_list_a, argv, argc);
}

/* Main function: entry point of the push_swap program */
int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_id_list	id_list_a;
	t_id_list	id_list_b;
	char		**args;
	int			*copy_arr;

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
	{
		start_alg(&a, &id_list_a, a.top + 1);
		printf("büyükten küçüğe doğru sirali islem yapmasi lazim\n");
	}
	else
		printf("sirali zaten");
	free(copy_arr);
	free(id_list_a.id);
	free(id_list_a.data_value);
	free(id_list_b.id);
	free(id_list_b.data_value);
	return (0);
}
