/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 17:41:30 by mmarti            #+#    #+#             */
/*   Updated: 2019/08/26 20:30:50 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>

char			*ft_itoa(int n);
int     ft_min(int a, int b);
int     ft_max(int a, int b);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strnew(size_t size);
void	*ft_memset(void *destination, int c, size_t n);
void	ft_strdel(char **as);
int 				ft_isprint(int c);
void				ft_bzero(void *destination, size_t n);
void				*ft_memcpy(void *destination,
		const void *source, size_t n);
char				*ft_strchr(const char *str, int ch);
int					ft_strcmp(char const *s1, char const *s2);
char				*ft_strdup(const char *str);
char				*ft_strwdup(const char *str);
size_t				ft_strlen(const char *string);
size_t				ft_strwlen(char const *s);
int					ft_strncmp(char const *s1,
		char const *s2, size_t n);
char				*ft_strstr(char const *haystack, char const *needle);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s1, int fd);
void				*ft_memalloc(size_t size);
char				**ft_strsplit(const char *s, int c);
size_t				ft_count_str(char **tab);
char				**ft_strtok(char *s);
void				*ft_memchr(const void *arr, int c, size_t n);
char				*ft_strcat(char *str1, const char *str2);
size_t				ft_strclen(char *s, char c);

#endif
