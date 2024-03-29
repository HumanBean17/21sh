/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 16:43:22 by mmarti            #+#    #+#             */
/*   Updated: 2019/09/03 16:43:24 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H
# define ENOMEM 1
# define EPERM 2
# define ENOFILE 3
# define ENOCOM 4
# define EFEWARGS 5
# define EMANYARGS 6
# define EBADOPT 7

void	ft_error(char const *s1, int code, char const *s2);

#endif