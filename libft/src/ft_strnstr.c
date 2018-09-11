/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:33:38 by hjo               #+#    #+#             */
/*   Updated: 2018/03/10 21:33:41 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	char	*c;
	size_t	i;
	size_t	j;

	i = -1;
	c = (char *)s1;
	if (*s2 == '\0')
		return (c);
	while (c[++i] != '\0')
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < len)
		{
			if (s2[j + 1] == '\0')
				return (&c[i]);
			++j;
		}
	}
	return (NULL);
}
