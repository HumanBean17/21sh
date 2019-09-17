#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
    int		i;
    char	*new_s;

    if (s || len > 0)
    {
        i = 0;
        new_s = NULL;
        new_s = ft_strnew(len);
        if (new_s)
        {
            while (s[start] != '\0' && len > 0)
            {
                new_s[i] = s[start];
                start++;
                i++;
                len--;
            }
            return (new_s);
        }
    }
    return (NULL);
}