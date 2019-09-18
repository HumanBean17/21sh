#include "minishell.h"

char 	*char_str(char c)
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}