/*
** push_swap main
** --------------
** - Argümanları doğrular (numeric/overflow/duplicate)
** - Stack A’yı (argv[1] tepe olacak şekilde) doldurur
** - Rank atar ve sıralı değilse start_alg ile sıralamayı başlatır
** - Debug çıktıları stderr’e, operasyonlar stdout’a yazılır
*/
#include "error.h"
#include "libft.h"
#include "utils.h"
#include <stdio.h>


/* argv tek string olarak verildiyse (argc == 2) */
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
	// Push in reverse so that the first argument becomes the TOP of the stack
	i = split_data_len - 1;
	while (i >= 0)
	{
		value = (int)ft_atoll(split_data[i]);
		push(stack_a, id_list_a, value, 0, value);
		i--;
	}
	free_split_args(split_data);
}

/* argv çoklu argümanlarla geldiyse (argc > 2) */
static void	fill_stack_from_args(t_stack *stack_a, t_id_list *id_list_a,
		char **argv, int argc)
{
	int i;
	int value;
	// Push in reverse so that argv[1] (first number) ends up at the TOP
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

/* Dispatcher */
static void	fill_stack_a(t_stack *stack_a, t_id_list *id_list_a, char **argv,
		int argc)
{
	if (argc == 2)
		fill_stack_from_single_arg(stack_a, id_list_a, argv[1]);
	else
		fill_stack_from_args(stack_a, id_list_a, argv, argc);
}
void	print_stack(t_stack *s_data)
{
	if (s_data->top < 0)
	{
		fprintf(stderr, "stack bos!\n");
		return ;
	}
	fprintf(stderr, "stack (top -> bottom): ");
	for (int i = s_data->top; i >= 0; i--)
	{
		fprintf(stderr, "%d ", s_data->data[i]);
	}
	fprintf(stderr, "\n");
}

/* Main function: entry point of the push_swap program */
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
	fprintf(stderr, "stack: ");
	print_stack(&a);
	fprintf(stderr, "\n");
	fprintf(stderr, "copy array: ");
	for (int i = 0; i < a.top + 1; i++)
	{
		fprintf(stderr, "%d ", copy_arr[i]);
	}
	quick_sort(copy_arr, 0, a.top);
	assign_rank(&a, &id_list_a, copy_arr);
	fprintf(stderr, "\n siralanmiş hali: ");
	for (int j = 0; j < a.top + 1; j++)
	{
		fprintf(stderr, "%d: ", copy_arr[j]);
	}
	fprintf(stderr, "\n id sirasi: ");
	for (int k = 0; k < a.top + 1; k++)
	{
		fprintf(stderr, "%d ", id_list_a.id[k]);
	}
	fprintf(stderr, "\norijinal degerler: ");
	for (int k = 0; k < a.top + 1; k++)
		fprintf(stderr, "%d ", id_list_a.data_value[k]);
	fprintf(stderr, "\n");
	if (!is_sorted(&a, &id_list_a))
	{
		start_alg(&a, &id_list_a, &b, &id_list_b, a.top + 1);
		//! duruma göre gözatılacak
	}
	else
		fprintf(stderr, "sirali zaten\n");
	fprintf(stderr, "islemler bitti zaman stack: ");
	print_stack(&a);
	fprintf(stderr, "\n");
	free(copy_arr);
	free_id_list(&id_list_a);
	free_id_list(&id_list_b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
