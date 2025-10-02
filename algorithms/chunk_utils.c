/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akivam <akivam@student.42istanbul.com.tr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 15:04:34 by akivam            #+#    #+#             */
/*   Updated: 2025/10/01 15:04:37 by akivam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include "algorithms.h"

static int	sqrt_func(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1);
}

static int	log2_func(int n)
{
	int	log_value;

	log_value = 0;
	while (n > 1)
	{
		n = n / 2;
		log_value++;
	}
	return (log_value);
}

int	calculate_chunk_count(int list_size)
{
	int	chunk;

	if (list_size <= 100)
	{
		chunk = sqrt_func(list_size);
		if (chunk < 2)
			chunk = 2;
	}
	else
	{
		chunk = log2_func(list_size) * 4;
		if (chunk < 16)
			chunk = 16;
		else if (chunk > 128)
			chunk = 128;
	}
	return (chunk);
}
