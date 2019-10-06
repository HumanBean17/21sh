#include "shell.h"

void	delete_ch(void)
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
		ft_strdel(&tmp);
		ft_strdel(&sub);
		g_line.x--;
		g_line.size--;
	}
}