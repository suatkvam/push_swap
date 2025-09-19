#include "utils.h"

/* Process command line arguments by validating them and checking for duplicates and argument count */

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
	free(numbers);
}
/**/
static void	free_split_and_exit(char ***args) //! ismi değiş sonra
{
	free_split_args(*args);
	exit(EXIT_FAILURE);
}

/* this function check the arguments
and Handle single string arguments (space-separated numbers) */
void	check_arguments(int argc, char **argv)
{
	char	**args;
	int		count;

	count = 0;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			exit_error();
		count = 0;
		while (args[count])
			count++;
		if (count == 0)
			free_split_and_exit(&args);
		process_args(count, args);
		free_split_args(args);
	}
	else
	{
		args = argv + 1;
		count = argc - 1;
		process_args(count, args);
	}
}
