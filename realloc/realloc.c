#include "minishell.h"

void	join_draw(t_draw *to_print, char *append, int len)
{
	char *tmp;

	tmp = ft_strdup(to_print->buf);
	ft_strdel(&to_print->buf);
}