#ifndef ANALYZER_H
#define ANALYZER_H

# define TCONST 100
# define TEXEX 101
# define TBRANCHOPEN 198
# define TBRANCHCLOSE 197
# define TPIPE 150
# define TREDIRECT 250
# define TREDIRECTX2 350
# define TSEMICOL 199

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
	struct	s_tree	*right;
}					t_tree;

t_token				*get_last(t_token *lst);
t_token				*new_token(char *str);
t_token				*tokenize(char *inp);

#endif