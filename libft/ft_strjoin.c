#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
    int		i;
    char	*concat_str;

    i = 0;
    concat_str = NULL;
    if (!s1 || !s2)
        return (NULL);
    concat_str = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
    if (!concat_str)
        return (NULL);
    while (s1[i] != '\0')
    {
        concat_str[i] = s1[i];
        i++;
    }
    concat_str = ft_strcat(concat_str, s2);
    return (concat_str);
}