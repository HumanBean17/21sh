#include "libft.h"

char	*ft_strnew(size_t size)
{
    char *str;

    str = NULL;
    str = (char *)malloc(sizeof(char) * size + 1);
    if (str)
    {
        ft_memset(str, '\0', size + 1);
        return (str);
    }
    return (NULL);
}