/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 20:00:48 by hjo               #+#    #+#             */
/*   Updated: 2018/03/10 20:00:50 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	when we are trying to find certain substr which is saved at str s1,
**	type substr that you want to find inside s2.
*/

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	if (!s2[0])
		return ((char *)&s1[i]);
	while (s1[i])
	{
		while ((s1[i + j] == s2[j]) && s2[j])
			j += 1;
		if (!s2[j])
			return ((char *)&s1[i]);
		j = 0;
		i += 1;
	}
	return (NULL);
}
