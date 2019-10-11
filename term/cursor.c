#include "shell.h"


void move_back(void)
{
	int zero;

	zero = 0;
	while (zero < g_line.x - g_line.fix)
	{
		tputs(tgetstr("nd", NULL), STDOUT_FILENO, ft_printnbr);
		zero++;
	}
}

void move_promt(void)
{
	write(STDOUT_FILENO, "\x001b[1000D", ft_strlen("\x001b[1000D"));
	if (g_quote == 0 || g_quote % 2 == 0)
		promt();
	else
		quote();
}
