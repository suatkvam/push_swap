// TODO: Radix sort (LSD) implement et ve dispatcher'da 100+ eleman için kullan.

//

/* döngü içinde kendinden sonra gelen en küçük sayıyı döndüren ve
 rank atıyan bir fonksiyon
(var zaten???) */

// en büyük sayının bit sayısını bulup ana döngü şartı o olacak
// en sağdan başlıyarak bitleri kontrol edilecek eğer kontrol bit 0 sa b stack atılacak
// 1 olan en alta kaydırılacak işlem bitince b dekiler geri alınacak
// bu şekilde devam edilecek

// TODO: Fonksiyon iskeletleri (implement edilecek)
// - get_max_id: max rank bul (id_list_a->id içindeki en büyük rank)
// - count_bits: bit sayısı (max_id'yi temsil etmek için gereken bit sayısı)
// - radix_sort: bit döngüsü (bit=0..bits-1), her turda:
//     - A'nın tepesinden n elemanı sırayla işle
//     - (id >> bit) & 1 == 0 ise pb, aksi halde ra
//     - Tur sonunda B'dekileri pa ile A'ya geri al

// TODO: Geliştirme ve Optimizasyon
// - Early exit: Turlar arasında is_sorted(a, ida) true ise döngüden çık.
// - Boş/küçük n: n < 2 için iş yok; 2–3’te mevcut küçük sorter devrede.
// - Duplicates: Validator zaten engelliyor; rank benzersiz → radix stabil.
// - Performans: O(n * log2(n)); büyük n için chunk’a göre genelde daha iyi.
// - (İleri) rr/rrr birleştirme: A ve/veya B aynı yönde dönecekse rotasyonları
//   birleştirerek adım sayısını azalt.

// TODO: Dispatcher entegrasyonu
// - 100+ için radix_sort çağır. Şu an >20 chunk’a yönlendiriliyor; 100+’ı
//   radix’e almak için algorithms/sort.c içindeki start_alg içinde koşul ekle.

#include "algorithms.h"
#include "utils.h"
/**/
static int	get_max_id(t_stack *stack_a, t_id_list *id_list_a)
{
	int	i;
	int	max_id;

	i = 1;
	if (!stack_a || stack_a->top < 0)
		return (0);
	max_id = id_list_a->id[0];
	while (i <= stack_a->top)
	{
		if (id_list_a->id[i] > max_id)
			max_id = id_list_a->id[i];
		i++;
	}
	return (max_id);
}

static int	count_bit(int value)
{
	int	bit;

	bit = 0;
	if (value == 0)
		return (1);
	while (value)
	{
		bit++;
		value >>= 1;
	}
	return (bit);
}

static void	process_bit_round(t_stack *stack_a, t_id_list *id_list_a,
		t_stack *stack_b, t_id_list *id_list_b, int bit)
{
	int	n;
	int	top_id;

	n = stack_a->top + 1;
	while (n-- > 0)
	{
		top_id = id_list_a->id[stack_a->top];
		if (((top_id >> bit) & 1) == 0)
			pb(stack_a, stack_b, id_list_a, id_list_b);
		else
			ra(stack_a, id_list_a);
	}
	while (stack_b->top >= 0)
		pa(stack_a, stack_b, id_list_a, id_list_b);
}

void	radix_sort(t_stack *stack_a, t_id_list *id_list_a, t_stack *stack_b,
		t_id_list *id_list_b)
{
	int	max_id;
	int	counted_bits;
	int	bit;

	max_id = get_max_id(stack_a, id_list_a);
	counted_bits = count_bit(max_id);
	bit = 0;
	if (is_sorted(stack_a, id_list_a))
		return ;
	while (bit < counted_bits)
	{
		process_bit_round(stack_a, id_list_a, stack_b, id_list_b, bit);
		bit++;
		if (is_sorted(stack_a, id_list_a))
			break ;
	}
}
