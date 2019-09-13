#ifndef ANALYZER_H
#define ANALYZER_H

#define TEXEX 255
# define TBRANCHOPEN 299
# define TBRANCHCLOSE 298
#define TPIPE 256
#define TSEMICOL 300

typedef struct		s_token
{
    short			type;
    char			*val;
    struct s_token	*next;
}					t_token;

t_token				*get_last(t_token *lst);
t_token				*new_token(char *str);
t_token				*tokenize(char *inp);

#endif