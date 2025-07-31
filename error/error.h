#ifndef ERROR_H
# define ERROR_H

# define MIN_INT -2147483648
# define MAX_INT 2147483647

void	exit_error(void);
int		is_not_numeric(const char *str);
int		has_duplicates(int *number, int count);

#endif