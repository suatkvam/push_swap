#include "algorithms.h"

/*
** copy_stack_to_Arry
** -------------------
** A yığınındaki mevcut değerleri (index 0 = bottom, index top = top)
** yeni ayrılmış bir int dizisine aynı sırayla kopyalar.
**
** Dönüş: Başarılıysa ayrılmış dizi işaretçisi; aksi halde NULL.
** Not: Dönüş değeri kullanılınca free edilmelidir.
*/


int	*copy_stack_to_Arry(t_stack *stack_a)
{
	int len;
	int *copy_area;
	int i;

	i = 0;
	len = stack_a->top + 1;
	// Eleman sayısı kadar yer ayır (0'larla doldurulur)
	copy_area = ft_calloc(len, sizeof(int));
	if (!copy_area)
		return (NULL);
	while (i < len)
	{
		// Stack içeriğini aynı indekslerle kopyala
		copy_area[i] = stack_a->data[i];
		i++;
	}
	return (copy_area);
}

/*
** partion_loop (Lomuto partition taraması)
** ---------------------------------------
** cp_arr[left..right-1] aralığını pivot'tan küçük olanları başa toplayacak
** şekilde tek geçişte düzenler. Dönen değer pivot'un yerleşeceği indeks olur.
*/
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

/*
** quick_sort (Lomuto partition)
** -----------------------------
** Pivot olarak sağ uç (right) seçilir; partion_loop ile bölme yapılır,
** pivot doğru konuma takaslanır ve sol/sağ alt diziler sıralanır.
*/
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
	// Sol ve sağ alt dizileri sıralama
	quick_sort(cp_arr, left, i - 1);
	quick_sort(cp_arr, i + 1, right);
}
/*
** binary_search
** -------------
** Sıralı cp_arr dizisinde value'nun indeksini (rank) döndürür.
** Bulunamazsa -1 döner (unique değerlerde beklenmez).
*/
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
	return (-1); // bulunamazsa(benzersiz elemanlarda sorun olmaz)
}
/*
** assign_rank
** -----------
** stack_a içindeki her değerin sorted_arr içindeki konumunu (rank) bulur ve
** id_list->id içine yazar. Ayrıca orijinal değeri id_list->data_value içine
** kopyalar. Rank: 0 en küçük, len-1 en büyük olacak şekilde indeks.
*/
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
		id_list->data_value[i] = stack_a->data[i]; // Orijinal değeri sakla
		i++;
	}
}
