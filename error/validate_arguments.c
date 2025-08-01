#include "error.h"
#include "../utils/utils.h" 

void validate_arguments(int argc, char **argv)
{
    int i = 1;
    int *temp_numbers;
    int count = argc - 1;

    while (i < argc)
    {
        if (is_not_numeric(argv[i]) || is_overflow(argv[i]))
            exit_error();
        i++;
    }
    temp_numbers = malloc(sizeof(int) * count);
    if (!temp_numbers)
        exit_error();
    i = 0;
    while (i < count)
    {
        temp_numbers[i] = ft_atoi(argv[i + 1]);
        i++;
    }
    if (has_duplicates(temp_numbers, count))
    {
        free(temp_numbers);
        exit_error();
    }
    free(temp_numbers);
}