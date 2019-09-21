#include "minishell.h"

int quote_find(const char *str)
{
	int i;
	int d_q;
	int o_q;

	i = 0;
	d_q = 0;
	o_q = 0;
	while (str[i])
	{
		if (str[i] == '\'' && d_q == 0)
			o_q++;
		else if (str[i] == '"' && o_q == 0)
			d_q++;
		i++;
	}
	if (d_q == 0)
		return (o_q);
	return (d_q);
}

char 	*char_str(char c)
{
	char *str;

	str = ft_strnew(1);
	str[0] = c;
	return (str);
}