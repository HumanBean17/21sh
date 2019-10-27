#include "shell.h"

void move_up(int limit)
{
	while (limit > 0)
	{
		tputs(tgetstr("up", NULL), STDOUT_FILENO, ft_printnbr);
		limit--;
	}
}

void move_right(int to_mv)
{
	while (to_mv > 0)
	{
		tputs(tgetstr("nd", NULL), STDOUT_FILENO, ft_printnbr);
		to_mv--;
	}
}

void move_back(void)
{
	move_right(g_line.x - g_line.fix);
}

void move_left(int limit)
{
	while (limit > 0)
	{
		tputs(tgetstr("le", NULL), STDOUT_FILENO, ft_printnbr);
		limit--;
	}
}

void move_promt(void)
{
	write(STDOUT_FILENO, "\x001b[1000D", ft_strlen("\x001b[1000D"));
}
