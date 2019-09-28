#ifndef ANALYZER_H
#define ANALYZER_H

# include <string.h>
# define TCONST 100
# define TEXEX 199
# define TPIPE 150
# define TGREAT 250
# define TDGREAT 350
# define TSEMICOL 101

typedef unsigned short t_type;

typedef struct		s_token
{
    t_type			type;
    char			*val;
    struct s_token	*next;
}					t_token;

typedef	struct		s_tree
{
	t_type			type;
	char			*val;
	struct	s_tree	*left;
	struct	s_tree	*parent;
	struct	s_tree	*right;
}					t_tree;

t_token				*get_last(t_token *lst);
t_token				*new_token(char *str);
t_token				*tokenize(char *inp);
t_tree				*new_tree_elem(t_token *token, t_tree *parent);
size_t				count_tokens(t_token *lst);
t_tree				*make_tree(t_token *token_list, t_tree *parent);
void				parse_tree(t_tree *tree);

#endif