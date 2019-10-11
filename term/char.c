#include "shell.h"

void nl_join(void)
{
    char *tmp;

    tmp = ft_strdup(g_line.str);
    ft_strdel(&g_line.str);
    g_line.str = ft_strjoin(tmp, "\n");
    ft_strdel(&tmp);
    g_line.x++;
    g_line.size++;
}

char *cut_fix(void)
{
    char *str;

    str = ft_strnew(g_line.fix);
    ft_strncpy(str, g_line.str, g_line.fix);
    ft_strdel(&g_line.str);
    return (str);
}

int     quote_find(const char *str)
{
	int i;
	int d_q;
	int o_q;

	i = 0;
	d_q = 0;
	o_q = 0;
	if (!str)
        return (o_q);
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