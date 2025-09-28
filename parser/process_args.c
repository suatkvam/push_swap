
#include "utils.h"

static void	free_split_and_exit(char ***args) //! ismi değiş sonra
{
	free_split_args(*args);
	exit(EXIT_FAILURE);
}

void	check_arguments(int argc, char **argv)
{
	char **args;
	int count;

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
		validate_arguments(count, args);
		free_split_args(args);
	}
	else
	{
		args = argv + 1;
		count = argc - 1;
		validate_arguments(count, args);
	}
}
