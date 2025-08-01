#include "utils.h"
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	s_len;
	size_t	sub_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	if (len > s_len - start)
		sub_len = s_len - start;
	else
		sub_len = len;
	temp = (char *)malloc(sub_len + 1);
	if (!temp)
		return (NULL);
	ft_memcpy(temp, s + start, sub_len);
	temp[sub_len] = '\0';
	return (temp);
}
