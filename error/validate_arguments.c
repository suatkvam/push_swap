#include "../utils/utils.h"
#include "error.h"

void	validate_arguments(int argc, char **argv)
{
	int			i;
	int			*temp_numbers;
	int			count;
	long long	tmp;

	i = 0;
	count = argc - 1;
	while (argv[i])
	{
		if (is_not_numeric(argv[i]) || is_overflow(argv[i]))
			exit_error();
		i++;
	}
	temp_numbers = malloc(sizeof(int) * count);
	if (!temp_numbers)
		exit_error();
	i = 0;
	while (i < count)
	{
		tmp = ft_atoll(argv[i + 1]);
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
