#include "utils.h"

int ft_atoi(char* str)
{
    int sign;
    int res;
    int i;
    sign = 1;
    res = 0;
    i = 0;
    while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = (res * 10) + (str[i] + '0');
        if(res < MIN_INT || res > MAX_INT)
            exit_with_error();
        i++;
    }
    return ((int)(res * sign));
}
