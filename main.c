#include "error.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>

/*init fill_stack a*/
// todo: bu fonksiyon eklenip düzeltilecek
/* Fill stack a with numbers from argv */
static void	fill_stack_a(t_stack *stack_a, char **argv, int argc)
{
	int		i;
	int		split_data_len;
	char	**split_data;

	split_data_len = 0;
	if (argc == 2)
	{
		split_data = ft_split(argv[1], ' ');
		if (!split_data)
			return ;
		while (split_data[split_data_len])
			split_data_len++;
		init_stack(stack_a, split_data_len);
		i = 0;
		while (split_data[i])
			push(stack_a, (int)ft_atoll(split_data[i++]));
		free_split_args(split_data);
	}
	else
	{
		init_stack(stack_a, argc - 1);
		i = 1;
		while (i < argc)
			push(stack_a, (int)ft_atoll(argv[i++]));
	}
}

// ! bu fonksiyon silinecek
void	print_stack(t_stack *s)
{
	int	i;

	if (s->top < 0)
	{
		printf("stack bos\n");
		return ;
	}
	i = s->top;
	printf("stack(top -> bottom): ");
	while (i >= 0)
	{
		printf("%d ", s->data[i]); // yukarıdan aşağı yazdırır
		i--;
	}
	printf("\n");
}
/* Main function: entry point of the push_swap program */
int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**args;
	int		count;

	args = argv;
	count = argc - 1;
	init_stack(&b, argc - 1);
	/* If no arguments provided, exit normally */
	if (argc < 2)
		exit(0);
	check_arguments(argc, argv);
	fill_stack_a(&a, args,argc);
	set_id_with_bubble_sort(&a);
	print_stack(&a);
	return (0);
}
