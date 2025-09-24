// error/is_not_numeric.c
#include "error.h"
#include <stdio.h>

int	is_not_numeric(const char *str)
{
	int	i;

	i = 0;
	//! Skip leading whitespaces
	while (str[i] == ' ')
		i++;
	//! Check and skip optional sign (+/-)
	if (str[i] == '+' || str[i] == '-')
		i++;
	//! Must have at least one digit after sign
	if (!(str[i] >= '0' && str[i] <= '9'))
		return (1);
	//! Skip all valid digits
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	//! Skip trailing whitespaces
	while (str[i] == ' ')
		i++;
	//! String must end here (no invalid characters)
	if (str[i] != '\0')
		return (1);
	return (0);
}
