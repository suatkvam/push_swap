/*
** algorithms/sort.c
** ------------------
** Küçük ölçek sıralama:
** - sort_two, sort_three
** - small_sort_upto_20: min-push (selection benzeri) strateji
** Dispatcher:
** - start_alg: 2/3 özel; diğerleri geçici olarak small_sort yolunda
*/
#include "algorithms.h"
#include "utils.h"


/*
			Stack sağa doğru büyüdüğü için, 2 eleman olduğunda ilk eleman top
				- 1,
			ikinci eleman ise top indeksinde bulunuyor.”
			sa(stack_a, id_list);
		*/
// !bu başka fonksiyonla birleşicek
static void	rotate_a_min_to_top(t_stack *a, t_id_list *ida, int pos)
{
	int top;
	int ra_count;
	int rra_count;

	if (pos < 0)
		return;
	top = a->top;
	ra_count = top - pos;
	rra_count = pos + 1;
	if (ra_count <= rra_count)
		while (ra_count-- > 0)
			ra(a, ida);
	else
		while (rra_count-- > 0)
			rra(a, ida);
}

static void	sort_two(t_stack *stack_a, t_id_list *id_list)
{
	// We want ascending order from TOP to BOTTOM
	// top element should be <= the element below it
	if (stack_a->data[stack_a->top] > stack_a->data[stack_a->top - 1])
		sa(stack_a, id_list);
}

static void	sort_three(t_stack *stack_a, t_id_list *id_list)
{
	int a = id_list->id[stack_a->top];     // en üst elemanın rank'ı
	int b = id_list->id[stack_a->top - 1]; // ortadaki rank
	int c = id_list->id[stack_a->top - 2]; // en alt rank

	if (a > b && b > c) // 3 2 1 durumuna karşılık
	{
		sa(stack_a, id_list);
		rra(stack_a, id_list);
	}
	else if (a > b && a > c && b < c) // 3 1 2
		ra(stack_a, id_list);
	else if (a > b && a < c) // 2 1 3
		sa(stack_a, id_list);
	else if (a < b && a < c && b > c) // 1 3 2
	{
		sa(stack_a, id_list);
		ra(stack_a, id_list);
	}
	else if (a < b && a > c) // 2 3 1
		rra(stack_a, id_list);
}


static void small_sort_upto_20(t_stack *a, t_id_list *ida,
							   t_stack *b, t_id_list *idb)
{
	int size;

	size = a->top + 1;
	// Min-id'leri tepeye kısa yoldan getirip B'ye aktar
	while (size > 3)
	{
		int pos = find_min_id_pos(a, ida);
		rotate_a_min_to_top(a, ida, pos);
		pb(a, b, ida, idb);
		// B'yi kabaca azalan id tut (top daha büyük id olsun)
		if (b->top >= 1 && idb->id[b->top] < idb->id[b->top - 1])
			sb(b, idb);
		size--;
	}
	// Kalanı A'da sırala
	if (size == 3)
		sort_three(a, ida);
	else if (size == 2)
		sort_two(a, ida);
	// B'yi geri al
	while (b->top >= 0)
		pa(a, b, ida, idb);
}


void	start_alg(t_stack *stack_a, t_id_list *id_list_a,
			   t_stack *stack_b, t_id_list *id_list_b,
			   int list_size)
{
	if (list_size == 2)
		sort_two(stack_a, id_list_a);
	else if (list_size == 3)
		sort_three(stack_a, id_list_a);
	else if( list_size <= 20)
	{
		// General min-push sorting strategy works for any size; it's simple and
		// produces correct results for the checker. Chunk optimization can be
		// re-enabled later for move-count improvements.
		small_sort_upto_20(stack_a, id_list_a, stack_b, id_list_b);
	}
	else
	{
		// 21+ elemanlar için chunk tabanlı sıralama
		init_chunk(stack_a, stack_b, id_list_a, id_list_b);
		// TODO: 100+ elemanlarda radix algoritmasına yönlendir (performans için)
	}
}
