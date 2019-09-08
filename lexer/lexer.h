#ifndef LEXER_H
# define LEXER_H
# define COMMAND 255
# define SEMICOLON 265
# define BRACKETS 264
typedef unsigned short t_type;

typedef struct  s_token
{
    t_type      type;
    char		*val;
}               t_token;


#endif