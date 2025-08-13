/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 09:41:39 by akivam            #+#    #+#             */
/*   Updated: 2025/06/16 16:03:52 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *str, char c)
{
	int	count;
	int	in_word;
	int	i;

	count = 0;
	i = 0;
	in_word = 0;
	while (str[i])
	{
		if (str[i] == c)
			in_word = 0;
		else if (in_word == 0)
		{
			in_word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static int	ft_get_word_len(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	ft_split_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
}

static char	**ft_allocate_memory(int word_count)
{
	char	**res;

	res = ft_calloc(word_count + 1, sizeof(char *));
	if (!res)
		return (NULL);
	return (res);
}

char	**ft_split(char const *s, char c)
{
	t_split_data	data;

	data.i = 0;
	data.j = 0;
	if (!s)
		return (NULL);
	data.word_count = ft_count_word(s, c);
	data.res = ft_allocate_memory(data.word_count);
	if (!data.res)
		return (NULL);
	while (s[data.i] && data.j < data.word_count)
	{
		while (s[data.i] == c)
			data.i++;
		data.word_len = ft_get_word_len(s + data.i, c);
		data.res[data.j] = ft_substr(s, data.i, data.word_len);
		if (!data.res[data.j])
			return (ft_split_free(data.res), NULL);
		data.i += data.word_len;
		data.j++;
	}
	data.res[data.j] = NULL;
	return (data.res);
}
