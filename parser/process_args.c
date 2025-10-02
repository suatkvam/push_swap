/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:40:03 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:40:05 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "../error/error.h"

static char	*join_all_args(int argc, char **argv)
{
	char	*result;
	char	*temp;
	char	*with_space;
	int		i;

	result = ft_strdup("");
	if (!result)
		return (NULL);
	i = 0;
	while (++i < argc)
	{
		with_space = ft_strjoin(argv[i], " ");
		if (!with_space)
		{
			free(result);
			return (NULL);
		}
		temp = ft_strjoin(result, with_space);
		free(result);
		free(with_space);
		if (!temp)
			return (NULL);
		result = temp;
	}
	return (result);
}

static char	**combine_and_split_all_args(int argc, char **argv)
{
	char	*joined;
	char	**result;

	joined = join_all_args(argc, argv);
	if (!joined)
		return (NULL);
	result = ft_split(joined, ' ');
	free(joined);
	return (result);
}

static int	count_args(char **args)
{
	int	count;

	count = 0;
	while (args && args[count])
		count++;
	return (count);
}

char	**check_arguments(int argc, char **argv)
{
	char	**args;
	int		total_count;

	if (argc < 2)
		exit(0);
	args = combine_and_split_all_args(argc, argv);
	if (!args)
		exit(0);
	total_count = count_args(args);
	if (validate_arguments(total_count, args))
	{
		free_split_args(args);
		exit_error();
	}
	if (total_count < 2)
	{
		free_split_args(args);
		exit(0);
	}
	return (args);
}
