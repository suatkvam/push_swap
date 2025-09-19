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

	split_data = ft_split(arg, ' ');
	if (!split_data)
		exit(EXIT_FAILURE);
	split_data_len = 0;
	while (split_data[split_data_len])
		split_data_len++;
	init_stack(stack_a, split_data_len);
	init_id_list(id_list_a, stack_a->capacity);
	i = 0;
	while (split_data[i])
		push(stack_a, (int)ft_atoll(split_data[i++]));
	free_split_args(split_data);
}

/* argv çoklu argümanlarla geldiyse (argc > 2) */
static void	fill_stack_from_args(t_stack *stack_a, t_id_list *id_list_a,
		char **argv, int argc)
{
	int	i;

	init_stack(stack_a, argc - 1);
	init_id_list(id_list_a, stack_a->capacity);
	i = 1;
	while (i < argc)
		push(stack_a, (int)ft_atoll(argv[i++]));
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
	t_id_list	stack_id_list;
	char		**args;

	args = argv;
	check_arguments(argc, argv);
	fill_stack_a(&a, &stack_id_list, args, argc);
	init_stack(&b, a.capacity);
	set_rank_by_value(&a, &stack_id_list);
	if (!is_sorted(&a, &stack_id_list))
		printf("büyükten küçüğe doğru sirali");
	return (0);
}
