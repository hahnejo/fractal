/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:39:52 by hjo               #+#    #+#             */
/*   Updated: 2018/03/10 19:39:54 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	allocs suff mem for a copy of str s1, and copies, and returns ptr to it.
*/

char	*ft_strdup(const char *s1)
{
	char	*new;
	char	*ptr;

	new = ft_strnew(ft_strlen((char *)s1));
	if (new == NULL)
		return (NULL);
	ptr = new;
	while (*s1 != '\0')
		*new++ = *s1++;
	return (ptr);
}
