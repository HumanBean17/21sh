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

void move_promt(int q)
{
	write(STDOUT_FILENO, "\x001b[1000D", ft_strlen("\x001b[1000D"));
	if (q == 0 || q % 2 == 0)
		promt();
	else
		quote();
}
