#include "minishell.h"

void	new_line(void)
{
	ft_strdel(&g_line.str);
	g_line.size = 0;
	g_line.x = 0;
	write(STDOUT_FILENO, "\n", 1);
}

int key_mv(void)
{
	char key_1;
	char key_2;

	read(STDIN_FILENO, &key_1, 1);
	read(STDIN_FILENO, &key_2, 1);
	if (key_1 == 91)
	{
		if (key_2 == 68 && g_line.x > 0) // LEFT
		{
			g_line.x--;
			return (-1);
		}
		else if (key_2 == 67 && g_line.x < g_line.size) // RIGHT
		{
			g_line.x++;
			return (1);
		}
	}
	return (0);
}