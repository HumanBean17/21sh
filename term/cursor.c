#include "minishell.h"


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

void move_promt(int f)
{
	write(STDOUT_FILENO, "\x001b[1000D", ft_strlen("\x001b[1000D"));
	if (f == 1)
		promt();
	else
		quote();
}
