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
    move_promt();
	tputs(tgetstr("cd", NULL), STDOUT_FILENO, ft_printnbr);
	if (!g_quote || !(g_quote % 2))
	{
		write(STDOUT_FILENO, g_line.str, g_line.size);
        move_promt();
		move_back();
	}
	else
    {
	    write(STDOUT_FILENO, g_line.str + g_line.fix, g_line.size - g_line.fix);
        move_promt();
	    move_back();
	}
}