#include "minishell.h"

void	quote(void)
{
	write(STDOUT_FILENO, "quote> ", 7);
}

void	promt(void)
{
	char buf[32];

	//ft_putstr_fd(getcwd(buf, 32), STDOUT_FILENO);
	write(STDOUT_FILENO, "$> ", 3);
}

void del_print(int f)
{
	move_promt(f);
	tputs(tgetstr("cd", NULL), STDOUT_FILENO, ft_printnbr);
	if (f == 1)
	{
		write(STDOUT_FILENO, g_line.str, g_line.size);
		move_promt(f);
		move_back();
	}
	else
	{
		write(STDOUT_FILENO, g_line.str + g_line.fix, g_line.size - g_line.fix);
		move_promt(f);
		move_back();
	}
}