#include "minishell.h"

void draw_rows(struct s_draw *ab)
{
	int y;
	int len;

	y = 0;
	while (y < g_E.screenrows)
	{
        len = g_E.row[y].size;
        if (len > g_E.screencols)
            len = g_E.screencols;
        append(ab, g_E.row[y].chars, len);
        y++;
	}
    append(ab, "\x1b[K", 3);
	if (y < g_E.screenrows - 1)
        append(ab, "\r\n", 2);
    //write(STDOUT_FILENO, ab->b, ab->len);
}