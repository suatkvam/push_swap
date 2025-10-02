/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_overflow.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:37:39 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:37:40 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "error.h"

static int	parse_sign_and_skip_zeros(const char *str, int *start)
{
	int	i;
	int	sign;

	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	*start = i;
	return (sign);
}

static int	check_length_overflow(const char *str, int start, int sign)
{
	const char	*limit = MAX_INT_STR;
	const char	*limit_neg = MIN_INT_STR;
	size_t		len;

	if (str[start] == '\0')
		return (0);
	len = ft_strlen(str) - start;
	if (len > 10)
		return (1);
	if (len < 10)
		return (0);
	if (sign == 1 && ft_strncmp(str + start, limit, 10) > 0)
		return (1);
	if (sign == -1 && ft_strncmp(str + start, limit_neg, 10) > 0)
		return (1);
	return (0);
}

int	is_overflow(const char *str)
{
	int	start;
	int	sign;

	sign = parse_sign_and_skip_zeros(str, &start);
	return (check_length_overflow(str, start, sign));
}
