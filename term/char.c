#include "shell.h"

void    promt_join(void)
{
	char *tmp;

	if (g_line.size > 3 &&
	g_line.str[0] == '$' && g_line.str[1] == '>' &&
	g_line.str[2] == ' ') {
		return ;
	}
	/*sleep(2);
	move_del();
	sleep(2);*/
	tmp = ft_strdup(g_line.str);
	ft_strdel(&g_line.str);
	g_line.str = ft_strjoin("$> ", tmp);
	g_line.x += 3;
	g_line.size += 3;
	/*sleep(2);
	move_del();
	sleep(2);*/
	ft_strdel(&tmp);
}

int nl_count(const char *str, int limit)
{
	int i;
	int y;

	i = 0;
	y = 0;
	while (str[i] && i < limit)
	{
		if (str[i] == '\n')
			y++;
		i++;
	}
	return (y);
}

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