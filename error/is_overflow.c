#include "error.h"
#include "../utils/utils.h"

int is_overflow(const char *str)
{
    int i = 0;
    int sign = 1;
    const char *limit = MAX_INT_STR;
    const char *limit_neg = MIN_INT_STR;

    if (str[i] == '+' || str[i] == '-')
    {
        if (str[i] == '-')
            sign = -1;
        i++;
    }

    int len = ft_strlen(str + i);

    if (len > 10)
        return 1;
    if (len < 10)
        return 0;

    if (sign == 1 && ft_strncmp(str + i, limit, 10) > 0)
        return 1;
    if (sign == -1 && ft_strncmp(str + i, limit_neg, 10) > 0)
        return 1;

    return 0;
}
