
#include "../utils/utils.h"
#include "error.h"


static void	check_format_and_overflow(int count, char **argv)
{
	int i;

	i = 0;
	while (i < count)
	{
		if (is_not_numeric(argv[i]) || is_overflow(argv[i]))
			exit_error();
		i++;
	}
}

static void	check_duplicates(int count, char **argv)
{
	int *temp_numbers;
	long long tmp;
	int i;

	temp_numbers = malloc(sizeof(int) * count);
	if (!temp_numbers)
		exit_error();
	i = 0;
	while (i < count)
	{
		tmp = ft_atoll(argv[i]);
		temp_numbers[i] = (int)tmp;
		i++;
	}
	if (has_duplicates(temp_numbers, count))
	{
		free(temp_numbers);
		exit_error();
	}
	free(temp_numbers);
}

void	validate_arguments(int count, char **argv)
{
	check_format_and_overflow(count, argv);
	check_duplicates(count, argv);
}
