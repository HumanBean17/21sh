#include "minishell.h"

void  row_realloc(t_erow **tmp, int len)
{
    t_erow *cur;

    cur = (t_erow *)malloc(sizeof(tmp) * len);
    cur->chars = ft_strdup((*tmp)->chars);
    cur->size = (*tmp)->size;
    ft_strdel(&(*tmp)->chars);
    free(tmp);
    (*tmp) = cur;
}

void append(struct s_draw *ab, const char *s, int len)
{
    char *new = realloc(ab->b, ab->len + len);

    if (new == NULL) return;
    memcpy(&new[ab->len], s, len);
    ab->b = new;
    ab->len += len;
}