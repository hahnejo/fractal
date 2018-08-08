/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:37:02 by hjo               #+#    #+#             */
/*   Updated: 2018/03/10 21:37:21 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	alphabetically compares the null term'ed str s1 and s2.
*/

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*i;
	unsigned char	*j;

	i = (unsigned char *)s1;
	j = (unsigned char *)s2;
	while (*i && (*i == *j))
	{
		i += 1;
		j += 1;
	}
	return (*i - *j);
}
