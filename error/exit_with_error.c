#include "error.h"

void exit_with_error(void)
{
    write(2,"Error\n",6);
    exit(EXIT_FAILURE);
}