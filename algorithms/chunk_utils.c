#include "algorithms.h"
#include "utils.h"

/*
chunk_count: fonksiyonu yapman gerek
	-> 2 4 8 16 32 64 128 bunlar aralında mı diye göz at ve hep yapıcak ilk başta 2^n! kaç chunk oldunu söyler
list size bunların aralığında ise üs sabit değilse üs artıcak kaç chunk oldunu bildin için kaça bölüceğini anlıyorsun
100 sayı için
stack_a full gez => oldu sürece
if min index  chunk start ile end aralında mı diye bak
arasında ise push b değilse
kontrol ettin şey chunkta değilse

1️⃣ Chunk Hesaplama Mantığı

Diyelim ki toplam eleman sayısı = list_size

Chunk sayısını senin fonksiyonuna göre hesaplıyoruz (chunk_count(list_size))

Örnek: list_size = 1000, chunk_count = 36

Her chunk’ın boyutu:

chunk_size=list_sizechunk_count
chunk_size=
chunk_count
list_size

1000 eleman ve 36 chunk → yaklaşık 27–28 eleman per chunk
2️⃣ Elemanın hangi chunk’a ait olduğunu bulma

Her elemanın rank/id değerine bakılır:
chunk_index = rank / chunk_size;
if (chunk_index >= chunk_count)
	chunk_index = chunk_count - 1; // son chunk taşmaları önlemek için
Örnek: rank = 54, chunk_size = 27 → chunk_index = 2 (3. chunk)
3️⃣ Stack_a’dan Stack_b’ye push/rotate mantığı

Stack_a’nın başından başlayıp her elemanı kontrol et:
for each element in stack_a:
	if element.rank in current_chunk:
		push_b(element)
	else:
		rotate_a()
current_chunk: işlediğin chunk aralığı

Eleman chunk’a ait değilse rotate ile stack’in sonuna geçir

Chunk tamamlanınca bir sonraki chunk’a geç

Stack_b’de elemanları genellikle büyükten küçüğe veya küçükten büyüğe sıralı saklamak isteyebilirsin:

Sonra push_swap algoritmasının final sorting adımında kolayca stack_a’ya geri alırsın

💡 Özet Mantık

Rank/id hesaplandı (assign_rank)

Chunk sayısı hesaplandı (chunk_count)

Her elemanın rank/id’ye göre chunk’ı belirlendi

Stack_a’dan elemanları chunk sırasına göre push/rotate ile Stack_b’ye taşıyoruz

Chunk tamamlandı → bir sonraki chunk
*/
static int	sqrt_func(int n)
{
	int	i;

	i = 0;
	while (i * i <= n)
		i++;
	return (i - 1); // i*i > n olduğunda bir önceki değeri döndür
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
		chunk = log2_func(list_size) * 4; // 4 değeri değişebilir
		if (chunk < 16)
			chunk = 16;
		else if (chunk > 128)
			chunk = 128;
	}
	return (chunk);
}
