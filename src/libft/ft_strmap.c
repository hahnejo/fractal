/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:26:40 by hjo               #+#    #+#             */
/*   Updated: 2018/03/11 19:26:41 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	applies the func f to each char of the str given as arg
**	to create a fresh new str.
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	size_t	len;
	char	*str;

	if (!s)
		return (NULL);
	i = 0;
	len = ft_strlen((char *)s);
	str = (char *)malloc(sizeof(*s) * len + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(s[i]);
		i += 1;
	}
	str[i] = '\0';
	return (str);
}
