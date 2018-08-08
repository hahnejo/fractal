/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 18:41:43 by hjo               #+#    #+#             */
/*   Updated: 2018/02/22 18:41:45 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** memcpy function copies n bytes from memory area src to memory area dst.
** If dst & src overlap, behavior is undefined, whereas memmove doesn't.
*/

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*c1;
	const char		*c2;

	c1 = dst;
	c2 = src;
	while (n--)
		*c1++ = *c2++;
	return (dst);
}
