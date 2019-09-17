#include "minishell.h"

void	delete(void)
{
	//write(STDOUT_FILENO, "1", 1);
	tputs(tgetstr("al", NULL), STDOUT_FILENO, ft_printnbr);
	//tputs(tgetstr("dc", NULL), STDOUT_FILENO, ft_printnbr);
}