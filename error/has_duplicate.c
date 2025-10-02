/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_duplicate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 16:35:58 by akivam            #+#    #+#             */
/*   Updated: 2025/09/30 16:35:59 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

int	has_duplicates(int *number, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (number[i] == number[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
