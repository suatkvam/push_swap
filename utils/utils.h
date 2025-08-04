#ifndef UTILS_H
# define UTILS_H

# include "../error/error.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int		*data;
	int		top;
	int		capacity;
}			t_stack;

typedef struct s_split_data
{
	char			**res;
	int				word_len;
	int				word_count;
	int				i;
	int				j;
}					t_split_data;

void		*ft_calloc(size_t nmemb, size_t size);
int			ft_atoi(const char *str);
long long	ft_atoll(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
size_t		ft_strlen(const char *s);
void		*ft_memcpy(void *dest, const void *src, size_t n);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *s);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char 		**ft_split(const char *s, char c);
void		init_stack(t_stack *s_data, int capacity);
void		push(t_stack *s_data, int value);
int			pop(t_stack *s_data);
void		free_stack(t_stack *s_data);
void		sa(t_stack *s_data_a);
void		sb(t_stack *s_data_b);
void		ss(t_stack *s_data_a, t_stack *s_data_b);
void		pa(t_stack *s_data_b, t_stack *s_data_a);
void		pb(t_stack *s_data_a, t_stack *s_data_b);
void		ra(t_stack *s_data_a);
void		rb(t_stack *s_data_b);
void		rr(t_stack *s_data_a, t_stack *s_data_b);
void		rra(t_stack *s_data_a);
void		rrb(t_stack *s_data_b);
void		rrr(t_stack *s_data_a, t_stack *s_data_b);

#endif