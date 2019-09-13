#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*dst;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	dst = (char *)ft_memalloc(len + 1);
	if (!dst)
		return (NULL);
	while (len--)
		dst[i++] = s[start++];
	return (dst);
}