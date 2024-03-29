/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 16:09:52 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/09 16:09:54 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcat(char *str1, const char *str2)
{
	char *string;

	string = str1;
	while (*string)
		string++;
	while (str2 && *str2)
		*string++ = *str2++;
	*string = 0;
	return (str1);
}
