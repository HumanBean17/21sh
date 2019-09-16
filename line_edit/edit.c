#include "minishell.h"

void    k_move()
{
    char *tmp;
    char *itoa;
    int   len;

    itoa = ft_itoa((int)g_line.x);
    tmp = ft_strjoin("\x001b[", itoa);
    len = 4 + (int)ft_strlen(itoa) + 1;
    ft_strdel(&itoa);
    itoa = ft_strdup(tmp);
    ft_strdel(&tmp);
    tmp = ft_strjoin(itoa, "C");
    //write(STDOUT_FILENO, tmp, len);
    ft_strdel(&tmp);
}

void    new_line()
{
    ft_strdel(&g_line.str);
    g_line.size = 0;
    g_line.x = 0;
}

void    insert_ch(char buf)
{
    char *tmp;
    char *sub;

    if (!g_line.str)
    {
        g_line.str = ft_strdup(&buf);
        g_line.x++;
        g_line.size++;
    }
    else
    {
        tmp = ft_strsub(g_line.str, 0, g_line.x);
        sub = ft_strsub(g_line.str, g_line.x, g_line.size - g_line.x);
        ft_strdel(&g_line.str);
        g_line.str = ft_strjoin(tmp, &buf);
        ft_strdel(&tmp);
        tmp = ft_strdup(g_line.str);
        ft_strdel(&g_line.str);
        g_line.str = ft_strjoin(tmp, sub);
        ft_strdel(&tmp);
        ft_strdel(&sub);
        g_line.x++;
        g_line.size++;
    }
}

void    init_edit()
{
	g_line.str = NULL;
	g_line.size = 0;
	g_line.x = 0;
}

void open_edit()
{
    g_E.row = (t_erow *)malloc(sizeof(t_erow));
    g_E.row->chars = ft_strdup("");
    g_E.row->size = 1;
}

void edit_refresh(void)
{
    struct s_draw ab = ABUF_INIT;
    char buf[32];

    append(&ab, "\x1b[?25l", 6);
    append(&ab, "\x1b[H", 3);
    draw_rows(&ab);
    snprintf(buf, sizeof(buf), "\x1b[%d;%dH", g_E.cy + 1, g_E.cx + 1);
    append(&ab, buf, ft_strlen(buf));
    append(&ab, "\x1b[?25h", 6);
    write(STDOUT_FILENO, ab.b, ab.len);
    ft_strdel(&ab.b);
}