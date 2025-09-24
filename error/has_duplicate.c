#include "error.h"

int	has_duplicates(int *number, int count)
{
	int	i;
	int	j;

	i = 0;
	//! Check each number against all subsequent numbers
	while (i < count)
	{
		j = i + 1;
		//! Compare current number with remaining numbers
		while (j < count)
		{
			//! If duplicate found, return error
			if (number[i] == number[j])
				return (1);
			j++;
		}
		i++;
	}
	//! No duplicates found
	return (0);
}
