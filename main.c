#include "error.h"
#include "libft.h"
#include "utils.h"

static void	process_args(int count, char **args)
{
	int	*numbers;
	int	i;

	validate_arguments(count, args);
	numbers = malloc(sizeof(int) * count);
	if (!numbers)
		exit_error();
	i = 0;
	while (i < count)
	{
		numbers[i] = (int)ft_atoll(args[i]);
		i++;
	}
	if (has_duplicates(numbers, count))
	{
		free(numbers);
		exit_error();
	}
	free(numbers);
}

int	main(int argc, char **argv)
{
	char	**args;
	int		count;

	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			exit_error();
		count = 0;
		while (args[count])
			count++;
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
		args = argv + 1;
		count = argc - 1;
		process_args(count, args);
	}
	return (0);
}
