#include "minishell.h"

int insert_ch(char buf)
{
    char 	*tmp;
    char 	*sub;
    char 	*s_buf;

    if (!g_line.str)
    {
        g_line.str = char_str(buf);
        g_line.x++;
        g_line.size++;
    }
    else
    {
    	s_buf = char_str(buf);
        tmp = ft_strsub(g_line.str, 0, g_line.x);
        if (g_line.size - g_line.x > 0)
        	sub = ft_strsub(g_line.str, g_line.x, g_line.size - g_line.x);
		else
			sub = ft_strdup("");
        ft_strdel(&g_line.str);
        g_line.str = ft_strjoin(tmp, s_buf);
        ft_strdel(&tmp);
        tmp = ft_strdup(g_line.str);
        ft_strdel(&g_line.str);
        g_line.str = ft_strjoin(tmp, sub);
        ft_strdel(&tmp);
        ft_strdel(&sub);
        ft_strdel(&s_buf);
        g_line.x++;
        g_line.size++;
    }
	return (1);
}

void    init_edit()
{
	g_line.str = NULL;
	g_line.size = 0;
	g_line.fix = 0;
	g_line.x = 0;
	g_line.y = 0;
}