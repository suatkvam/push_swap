#include "error.h"
#include <stdlib.h>
#include <unistd.h>

void exit_error(void)
{
    write(2,"Error\n",6);
    exit(EXIT_FAILURE);
}