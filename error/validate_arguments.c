/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_arguments.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:37:57 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:37:58 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils/utils.h"
#include "error.h"

static int	check_format_and_overflow(int count, char **argv)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (is_not_numeric(argv[i]) || is_overflow(argv[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	check_duplicates(int count, char **argv)
{
	int			*temp_numbers;
	long long	tmp;
	int			i;

	temp_numbers = malloc(sizeof(int) * count);
	if (!temp_numbers)
		return (1);
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
		return (1);
	}
	free(temp_numbers);
	return (0);
}

int	validate_arguments(int count, char **argv)
{
	if (check_format_and_overflow(count, argv))
		return (1);
	if (check_duplicates(count, argv))
		return (1);
	return (0);
}
