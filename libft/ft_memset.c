#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
    unsigned char	*str;

    str = (unsigned char *)destination;
    while (n--)
        *(str++) = c;
    return (destination);
}