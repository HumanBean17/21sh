#include "shell.h"

void	quote(void)
{
	write(STDOUT_FILENO, "quote> ", 7);
}

void	print_promt(void)
{
	char buf[32];

	//ft_putstr_fd(getcwd(buf, 32), STDOUT_FILENO);
	write(STDOUT_FILENO, "$> ", 3);
}

void move_del(void)
{
	move_promt();
	tputs(tgetstr("cd", NULL), STDOUT_FILENO, ft_printnbr);
	print_promt();
}

void del_print()
{
	g_line.y = nl_count(g_line.str, g_line.x);
	move_up(g_line.y);
	move_del();
	write(STDOUT_FILENO, g_line.str, g_line.size);
	move_left((int)g_line.size - g_line.x);
}