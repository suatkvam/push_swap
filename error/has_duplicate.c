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
