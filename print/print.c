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

void move_del_print(void)
{
	move_up();
	move_promt();
	tputs(tgetstr("dl", NULL), STDOUT_FILENO, ft_printnbr);
	promt();
}

void del_print()
{
	//promt_join();
	nl_count();
	move_del_print();
	write(STDOUT_FILENO, g_line.str, g_line.size);
	move_left();
}