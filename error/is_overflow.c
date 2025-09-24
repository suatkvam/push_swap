#include "../libft/libft.h"
#include "error.h"
#include <stdio.h>

int	is_overflow(const char *str)
{
	int			i;
	int			sign;
	const char	*limit = MAX_INT_STR;
	const char	*limit_neg = MIN_INT_STR;
	size_t		len;
	int			start;

	i = 0;
	sign = 1;
	//! Parse sign character (+ or -)
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	//! Skip all leading zeros to get actual number length
	while (str[i] == '0')
		i++;
	start = i;
	//! If all digits were zeros, it's valid (represents 0)
	if (str[start] == '\0')
		return (0);
	//! Calculate length of significant digits (after leading zeros)
	len = ft_strlen(str);
	len -= start;
	//! If more than 10 digits, definitely overflow
	if (len > 10)
		return (1);
	//! If less than 10 digits, definitely safe
	if (len < 10)
		return (0);
	//! Exactly 10 digits: compare with INT_MAX or INT_MIN
	if (sign == 1 && ft_strncmp(str + start, limit, 10) > 0)
		return (1);
	if (sign == -1 && ft_strncmp(str + start, limit_neg, 10) > 0)
		return (1);
	return (0);
}
