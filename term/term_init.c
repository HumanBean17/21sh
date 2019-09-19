#include "minishell.h"

int		ft_printnbr(int nbr)
{
	return (write(STDERR_FILENO, &nbr, 1));
}

void	term_init(void)
{
	char b[32];

	tgetent(b, getenv("TERM"));
	tputs(tgetstr("cl", NULL), STDOUT_FILENO, ft_printnbr);
}