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

void del_print(int q)
{
	move_promt(q);
	tputs(tgetstr("cd", NULL), STDOUT_FILENO, ft_printnbr);
	if (q == 0 || q % 2 == 0)
	{
		write(STDOUT_FILENO, g_line.str, g_line.size);
		move_promt(q);
		move_back();
	}
	else
	{
		write(STDOUT_FILENO, g_line.str + g_line.fix, g_line.size - g_line.fix);
		move_promt(q);
		move_back();
	}
}