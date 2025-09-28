#include "algorithms.h"


int	*copy_stack_to_Arry(t_stack *stack_a)
{
	int len;
	int *copy_area;
	int i;

	i = 0;
	len = stack_a->top + 1;

	copy_area = ft_calloc(len, sizeof(int));
	if (!copy_area)
		return (NULL);
	while (i < len)
	{
		copy_area[i] = stack_a->data[i];
		i++;
	}
	return (copy_area);
}

static int	partion_loop(int *cp_arr, int left, int right, int pivot)
{
	int i;
	int j;
	int tmp;

	i = left;
	j = left;
	while (j < right)
	{
		if (cp_arr[j] < pivot)
		{
			tmp = cp_arr[i];
			cp_arr[i] = cp_arr[j];
			cp_arr[j] = tmp;
			i++;
		}
		j++;
	}
	return (i);
}

void	quick_sort(int *cp_arr, int left, int right)
{
	int pivot;
	int i;
	int tmp;

	if (left >= right)
		return ;
	pivot = cp_arr[right];
	i = partion_loop(cp_arr, left, right, pivot);
	tmp = cp_arr[i];
	cp_arr[i] = cp_arr[right];
	cp_arr[right] = tmp;

	quick_sort(cp_arr, left, i - 1);
	quick_sort(cp_arr, i + 1, right);
}

int	binary_search(int *cp_arr, int size, int value)
{
	int left;
	int right;
	int middle;

	left = 0;
	right = size - 1;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (cp_arr[middle] == value)
			return (middle);
		else if (cp_arr[middle] < value)
			left = middle + 1;
		else
			right = middle - 1;
	}
	return (-1);
}

void	assign_rank(t_stack *stack_a, t_id_list *id_list, int *sorted_arr)
{
	int len;
	int i;
	int rank;

	len = stack_a->top + 1;
	i = 0;
	while (i < len)
	{
		rank = binary_search(sorted_arr, len, stack_a->data[i]);
		id_list->id[i] = rank;
		id_list->data_value[i] = stack_a->data[i];
		i++;
	}
}
