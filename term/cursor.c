#include "minishell.h"


void move_back(void)
{
	int zero;

	zero = 0;
	while (zero < g_line.x)
	{
		tputs(tgetstr("nd", NULL), STDOUT_FILENO, ft_printnbr);
		zero++;
	}
}

void move_promt(void)
{
	int zero;

	/*zero = g_line.x;
	while (zero > 0)
	{
		tputs(tgetstr("le", NULL), STDOUT_FILENO, ft_printnbr);
		zero--;
	}*/
	write(STDOUT_FILENO, "\x001b[1000D", ft_strlen("\x001b[1000D"));
	promt();
}
