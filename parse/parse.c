/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:05:09 by mmarti            #+#    #+#             */
/*   Updated: 2019/10/11 11:24:59 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char *insert(char *s, char *envname, char *tmp)
{
	char *envval;
	char *res;

	envval = ft_getenv(envname);
	if (!(res = (char *)ft_memalloc(ft_strlen(s) + ft_strlen(envval) - ft_strlen(envname))))
	{
		ft_error(0, ENOMEM, 0);
		exit(ENOMEM);
	}
	*tmp = 0;
	ft_memcpy(res, s, ft_strlen(s));
	if (envval)
		ft_memcpy(&res[ft_strlen(res)],  envval, ft_strlen(envval));
	while (*tmp && *tmp != ' ' && *tmp != '\t')
		tmp++;
	ft_memcpy(&res[ft_strlen(res)], tmp, ft_strlen(tmp));
	free(s);
	free(envname);
	return (res);
}

char *insenv(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '~')
		{
			s = insert(s, ft_strdup("HOME"), &s[i]);
			i = 0;
		}
		else if (s[i] == '$')
		{
			s = insert(s, ft_strwdup(s + 1), &s[i]);
			i = 0;
		}
		i++;
	}
	return (s);
}

void pasteenv(char **com)
{
	while (*com)
	{
		*com = insenv(*com);
		com++;
	}
}


//void prtr(t_tree *tree)
//{
//	while (tree->right)
//	{
//		printf("%s", tree->val[0]);
//		printf("!!left!!%s", tree->left->val[0]);
//		printf("!!right!!%s", tree->right->val[0]);
//		tree = tree->right;
//	}
//}

int	check_built(char **command)
{
    int ac;

    ac = ft_count_str(command);
    if (!(ft_strcmp("setenv", command[0])))
        ft_setenv(ac, command);
	else if (!(ft_strcmp("cd", command[0])))
		ft_cd(ft_count_str(&command[1]), &command[1]);
    else if (!(ft_strcmp("unsetenv", command[0])))
        ft_unsetenv(ac, command);
    else if (!(ft_strcmp("env", command[0])))
        ft_env(ac, command);
    else if (!(ft_strcmp("echo", command[0])))
        ft_echo(&command[1]);
    else if (!(ft_strcmp("pwd", command[0])))
        ft_putdir(ac, command);
    else
        return (-1);
	return (0);
}

//void	free_token_list(t_token *list)
//{
//	t_token *tmp;
//
//	if (!list)
//		return ;
//	while (list)
//	{
//		tmp = list->next;
//		//free(list->val);
//		free(list);
//		list = tmp;
//	}
//}

void	free_tree(t_tree *tree)
{
	if (!tree)
		return ;
	free_tree(tree->left);
	free_tree(tree->right);
	free_tab(tree->val, ft_count_str(tree->val));
	free(tree);
}

void	ft_do(char *inp)
{
    t_token *token_list;
	t_tree	*tree;

    if (!inp)
        return ;
    if (!(strcmp("exit", inp)))
    	exit (0);
    token_list = tokenize(inp);
    /* a place for validation */
    tree = make_tree(token_list, 0);
    parse_tree(tree);
    free_tree(tree);
}
