/*
** error/validate_arguments.c
** --------------------------
** Argümanları doğrular: numeric format, 32-bit taşma ve duplicate kontrolü.
*/
#include "../utils/utils.h"
#include "error.h"


void	validate_arguments(int count, char **argv)
{
	int i;
	int *temp_numbers;
	long long tmp;

	i = 0;
	while (i < count)
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
