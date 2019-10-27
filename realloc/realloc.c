#include "shell.h"

void		print_list(t_command *command)
{
	t_command *tmp;
	t_command *prev;

	tmp = command;
	prev = command;
	while (tmp)
	{
		printf("%s\n", tmp->str);
		prev = tmp;
		tmp = tmp->next;
	}
	printf("\n-----------\n");
	while(prev)
	{
		printf("%s\n", prev->str);
		prev = prev->prev;
	}
	printf("\n");
}

t_command *push_front(t_command **command, char *str)
{
	t_command	*tmp;
	t_command   *cp;

	cp = (*command);
	tmp = new_command(str);
	if (!(*command))
	{
		(*command) = tmp;
		return (*command);
	}
	else
		tmp->next = cp;
	(*command) = tmp;
	cp->prev = tmp;
	return (*command);
}

t_command	*new_command(char *str)
{
	t_command *tmp;

	tmp = (t_command *)malloc(sizeof(t_command));
	if (str)
		tmp->str = ft_strdup(str);
	else
		tmp->str = ft_strdup("");
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}