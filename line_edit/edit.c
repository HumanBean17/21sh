#include "minishell.h"

void append_edit(char *s, size_t len)
{
    /*g_E.row = realloc(g_E.row, sizeof(t_erow) * (g_E.numrows + 1));
    int at = g_E.numrows;
    g_E.row[at].size = len;
    g_E.row[at].chars = malloc(len + 1);
    memcpy(g_E.row[at].chars, s, len);
    g_E.row[at].chars[len] = '\0';*/
    char *tmp;

    //write(STDOUT_FILENO, g_E.row->chars, 1);
    tmp = ft_strdup(g_E.row->chars);
    ft_strdel(&g_E.row->chars);
    free(g_E.row);
    g_E.row = (t_erow *)malloc(sizeof(t_erow));
    g_E.row->chars = ft_strjoin(tmp, s);
    g_E.row->size = ft_strlen(g_E.row->chars);
    //g_E.numrows++;
}

void init_edit()
{
	g_E.cx = 0;
	g_E.cy = 0;
	g_E.rowoff = 0;
	g_E.screenrows = 1;
	g_E.screencols = 0;
	g_E.numrows = 0;
	g_E.row = NULL;
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