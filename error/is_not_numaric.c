#include "error.h"

// kontrol edilecek
int is_not_numeric(const char *str)
{
    int i = 0;
    if(str[0] == '\0')
        return (1);
    if (str[i] == '-' || str[i] == '+')
    {
        if(str[i + 1] == '\0')
            return(1);
        i++;
    }
    while (str[i])
    {
        if(str[i] < '0' || str[i] > '9')
            return(1);
        i++;
    }
    return 0;
}