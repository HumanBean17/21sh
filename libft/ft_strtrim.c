#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t st;
	size_t e;

	if (!s)
		return (0);
	st = 0;
	e = ft_strlen(s) - 1;
	while (s[st] == ' ' || s[st] == '\n' || s[st] == '\t')
		st++;
	if (s[st] == 0)
		return (0);
	while ((s[e] == ' ' || s[e] == '\n' || s[e] == '\t') && e > 0)
		e--;
	return (ft_strsub(s, st, e - st + 1));
}
