#include "algorithms.h"
#include "utils.h"


int	all_elements_in_chunk_done(t_stack *stack_a, t_id_list *id_list,
		int current_chunk, int chunk_size, int chunk_count)
{
	int rank;
	int chunk_index;
	int i;

	i = 0;
	while (i <= stack_a->top)
	{
		rank = id_list->id[i];
		chunk_index = rank / chunk_size;
		if (chunk_index >= chunk_count)
			chunk_index = chunk_count - 1;
		if (chunk_index == current_chunk)
			return (0);
		i++;
	}
	return (1);
}

static void	rotate_b_after_push(t_stack *b, t_id_list *idb)
{
	// Basit bir sıkılaştırma: tepe ve altındaki id düzenini korumaya çalış
	if (b->top >= 1 && idb->id[b->top] < idb->id[b->top - 1])
		sb(b, idb);
	// İsteğe bağlı: en büyükler üstte kalsın diye,
	// eğer yeni gelen çok küçükse bir rb ile alta it.
	if (b->top >= 2 && idb->id[b->top] < idb->id[b->top - 2])
		rb(b, idb);
	// TODO: B tarafına yerleştirirken uygun pozisyona döndürerek (rb/rrb)
	// araya sokma stratejisi ekle; böylece push-back'te daha az rotasyon olur.
}

static void	push_back_from_b(t_stack *a, t_id_list *ida, t_stack *b,
		t_id_list *idb)
{
	// B boşalana kadar: B'deki en büyük rank'ı (id) tepeye getir, sonra pa
	while (b->top >= 0)
	{
		int max_pos = find_max_rank_pos(b, idb);
		int top = b->top;
		if (max_pos < 0)
			break ;
		// rb/rrb seçimli döndürme
		int rb_count = top - max_pos;
		int rrb_count = max_pos + 1;
		if (rb_count <= rrb_count)
			while (rb_count-- > 0)
				rb(b, idb);
		else
			while (rrb_count-- > 0)
				rrb(b, idb);
		pa(a, b, ida, idb);
		// TODO: A ve B aynı yönde dönecekse rr/rrr ile birleştir ve adım sayısını azalt.
	}
}

static void	setup_chunk_parameters(t_stack *stack_a, t_id_list *id_list_a,
		int *chunk_count, int *chunk_size)
{
	int list_size;
	int *sorted_copy_array;

	list_size = stack_a->top + 1;
	*chunk_count = calculate_chunk_count(list_size);
	*chunk_size = list_size / *chunk_count;
	sorted_copy_array = copy_stack_to_Arry(stack_a);
	if (!sorted_copy_array)
		return ;
	quick_sort(sorted_copy_array, 0, list_size - 1);
	assign_rank(stack_a, id_list_a, sorted_copy_array);
	free(sorted_copy_array);
}

static int	process_single_rotation(t_stack *stack_a, t_stack *stack_b,
		t_id_list *id_list_a, t_id_list *id_list_b, int current_chunk,
		int chunk_size, int chunk_count)
{
	int rank, chunk_index;

	rank = id_list_a->id[stack_a->top];
	chunk_index = rank / chunk_size;
	if (chunk_index >= chunk_count)
		chunk_index = chunk_count - 1;
	if (chunk_index == current_chunk)
	{
		pb(stack_a, stack_b, id_list_a, id_list_b);
		rotate_b_after_push(stack_b, id_list_b);
		return (1);
	}
	else
	{
		ra(stack_a, id_list_a);
		return (0);
	}
}

static void	process_chunks(t_stack *stack_a, t_stack *stack_b,
		t_id_list *id_list_a, t_id_list *id_list_b, int chunk_size,
		int chunk_count)
{
	int current_chunk = 0;

	while (stack_a->top >= 0 && current_chunk < chunk_count)
	{
		int rotations = 0;
		int stack_size = stack_a->top + 1;
		while (rotations < stack_size)
		{
			if (process_single_rotation(stack_a, stack_b, id_list_a,
					id_list_b, current_chunk, chunk_size, chunk_count))
				break ;
			rotations++;
		}
		if (all_elements_in_chunk_done(stack_a, id_list_a, current_chunk,
				chunk_size, chunk_count))
			current_chunk++;
	}
}

void	init_chunk(t_stack *stack_a, t_stack *stack_b, t_id_list *id_list_a,
		t_id_list *id_list_b)
{
	int chunk_count, chunk_size;

	setup_chunk_parameters(stack_a, id_list_a, &chunk_count, &chunk_size);
	process_chunks(stack_a, stack_b, id_list_a, id_list_b, chunk_size,
		chunk_count);
	push_back_from_b(stack_a, id_list_a, stack_b, id_list_b);
}
