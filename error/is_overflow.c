#include "error.h"
#include "../utils/utils.h"

int is_overflow(const char* str)
{
    long long num;

    num = ft_atoll(str);

    if(num > MAX_INT || num < MIN_INT)
        return (1);
    return (0);
}