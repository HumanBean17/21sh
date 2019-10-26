#include "shell.h"

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

void del_print()
{
	nl_count();
	move_up();
    move_promt();
	tputs(tgetstr("cd", NULL), STDOUT_FILENO, ft_printnbr);
	promt();
	write(STDOUT_FILENO, g_line.str, g_line.size);
	move_left();
	g_k = 0;
}