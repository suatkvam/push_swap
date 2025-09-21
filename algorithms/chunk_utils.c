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
static int	calculate_chunk_count(int list_size)
{
	int	chunk;
	int	i;

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
