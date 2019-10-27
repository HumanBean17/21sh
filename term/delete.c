#include "shell.h"

void delete_ch(t_command *cur)
{
	char *tmp;
	char *sub;

	if (g_line.x - g_line.fix > 0)
	{
		tmp = ft_strsub(g_line.str, 0, g_line.x - 1);
		if (g_line.size - g_line.x > 0)
			sub = ft_strsub(g_line.str, g_line.x, g_line.size - g_line.x);
		else
			sub = ft_strdup("");
		ft_strdel(&g_line.str);
		g_line.str = ft_strjoin(tmp, sub);
		ft_strdel(&cur->str);
		ft_strdel(&tmp);
		ft_strdel(&sub);
		cur->str = ft_strdup(g_line.str);
		g_line.x--;
		g_line.size--;

	}
}