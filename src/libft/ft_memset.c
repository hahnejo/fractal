/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 11:45:56 by hjo               #+#    #+#             */
/*   Updated: 2018/02/22 11:45:58 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	p is placeholder and it's to modify string *str.
**	lower length to know how long to copy i to str.
**	copy i to str thru placeholder p.
**	return str.
*/

void		*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*p;

	p = b;
	while (len-- != 0)
		*p++ = (unsigned char)c;
	return (b);
}
