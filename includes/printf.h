/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lcrawn <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:49:05 by lcrawn            #+#    #+#             */
/*   Updated: 2019/07/19 11:48:05 by lcrawn           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct		s_flags
{
	char			flag;
	struct s_flags	*flag_next;
}					t_flags;

typedef struct		s_printf
{
	struct s_flags	*flag;
	int				width;
	int				acc;
	char			len[2];
	int				type;
}					t_printf;

typedef	struct		s_double
{
	unsigned long	man		: 64;
	unsigned long	exp		: 15;
	unsigned long	sign	: 1;
}					t_double;

typedef union		u_printf
{
	long double		number;
	t_double		num;
}					t_uprintf;

int					ft_width_mod(t_printf **elem, int i, char *str);
void				ft_flag_new(t_printf **elem, const char c);
void				ft_condition_spec(t_printf *tmp, char **line,
		char **spec, char *width);
void				ft_condition_width(t_printf *tmp,
		char **line, char **width);
void				ft_condition_tab(t_printf *tmp, char **line,
		char **tab, char *width);
void				ft_condition_sign(t_printf *tmp, char **line,
		char **sign, char *width);
void				ft_char_zero(char **width, const char *line, t_printf *tmp);
int					ft_check_zero(const char *line);
char				*ft_strrrev(char *str, int flag);
char				*ft_return_f(t_printf *list, va_list ap);
char				*ft_return_x(t_printf *list, va_list ap);
char				*ft_return_u(t_printf *list, va_list ap);
char				*ft_return_o(t_printf *list, va_list ap);
char				*ft_return_di(t_printf *list, va_list ap);
int					ft_printf_putstr(int type, char *field, const char *number);
void				ft_do_del(t_printf **list, char **number, char **field);
char				*ft_strdup_n(const char *str, int round);
char				*ft_round_dioux(char **num, int round);
char				*ft_strcpy_end(char *destination, const char *source);
char				*ft_strcpy_n(char *destination, const char *source);
char				*ft_strnew_n(size_t size, char c);
char				*ft_return_field(t_printf *tmp, char *line);
int					ft_flag_find(t_flags *alst, char c);
char				*ft_base_llong(unsigned long long int num,
		int base, int round);
char				*ft_base_long(unsigned long int num, int base, int round);
char				*ft_base_char(unsigned char num, int base, int round);
char				*ft_base_short(unsigned short int num, int base, int round);
char				*ft_put_unsigned_llong(unsigned long long int n, int round);
char				*ft_put_unsigned_long(unsigned long int n, int round);
char				*ft_put_unsigned_char(unsigned char n, int round);
char				*ft_put_unsigned_short(unsigned short int n, int round);
char				*ft_putnbr_llong(long long int n, int round);
char				*ft_putnbr_long(long int n, int round);
char				*ft_putnbr_signed(signed char n, int round);
char				*ft_putnbr_short(short n, int round);
int					ft_len_check_dioux(const char *c);
char				*ft_putchar_2(char c);
char				*ft_convert_1(int *a, int round);
void				ft_move_1(int **a);
char				*ft_convert_2(int *a, int sign);
int					ft_find_start(const int *a);
int					*ft_cast_1(unsigned long num, int round);
void				ft_sum_2(int **sum, const int *b);
int					*ft_cast_2(unsigned long num, int len);
int					ft_len_check(const char c[]);
char				*ft_put_address(unsigned long s, int round);
void				ft_round(int **a, int **b, int round);
void				ft_int_del(int **a);
int					*ft_int_cpy(const int *a);
void				ft_move_2(int **a);
void				ft_sum_1(int **sum, const int *b);
int					*ft_new_malloc(size_t size);
int					*ft_mlt(const int *a, const int *b, int n);
int					*ft_long_pow(int power, int num);
char				*ft_put_float_2(t_double *tmp, int round);
int					ft_abs(int x);
char				*ft_put_float(long double num, int round);
char				*ft_strupper(char *str);
void				ft_printf_del(t_printf **to_del);
char				*ft_put_unsigned(unsigned int n, int round);
int					ft_n_len(int num);
char				*ft_base(unsigned int num, int base, int round);
int					ft_fill(t_printf **elem, const char *str);
t_printf			*ft_printf_new(void);
int					ft_len(const char c);
int					ft_flag(const char c);
int					ft_printf(const char *str, ...);
int					ft_fill_info(const char *str, va_list ap);
int					ft_type_and(char c);
int					ft_type_or(char c);
int					ft_atoi(const char *str);
void				*ft_memset(void *destination, int c, size_t n);
char				*ft_strcpy(char *destination, const char *source);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_isdigit(int c);
int					ft_toupper(int c);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_putnbr(int n, int round);

#endif
