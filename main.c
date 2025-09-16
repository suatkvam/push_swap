#include "error.h"
#include "libft.h"
#include "utils.h"

/* Process command line arguments by validating them and checking for duplicates */
static void	process_args(int count, char **args)
{
	int	*numbers;
	int	i;

	/* Validate all arguments for numeric format and overflow */
	validate_arguments(count, args);
	/* Allocate memory for storing the integer array */
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		exit_error();
	i = 0;
	/* Convert string arguments to integers */
	while (i < count)
	{
		numbers[i] = (int)ft_atoll(args[i]);
		i++;
	}
	/* Check for duplicate values in the array */
	if (has_duplicates(numbers, count))
	{
		free(numbers);
		exit_error();
	}
}

/*init stack a and fill stack a*/
/*buna ekleme yapılacak*/
t_stack init_stack_a_and_fill(char **argc, int len)
{
	t_stack stack_a;
	int i = 0;
	init_stack(&stack_a,len);
	while (i <= len)
	{
		push(&stack_a,ft_atoi(*argc[i]))
	}
	

}

/* Main function: entry point of the push_swap program */
int	main(int argc, char **argv)
{
	char	**args;
	int		count;

	/* If no arguments provided, exit normally */
	if (argc < 2)
		return (0);
	/* Handle single string argument (space-separated numbers) */
	if (argc == 2)
	{
		/* Split the single argument by spaces */
		args = ft_split(argv[1], ' ');
		if (!args)
			exit_error();
		count = 0;
		/* Count the number of split arguments */
		while (args[count])
			count++;
		/* Check if we have valid arguments */
		if (count == 0)
		{
			free_split_args(args);
			exit_error();
		}
		process_args(count, args);
		free_split_args(args);
	}
	else
	{
		/* Handle multiple arguments (each number as separate argument) */
		args = argv + 1;
		count = argc - 1;
		process_args(count, args);
	}
	return (0);
}
