/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 14:36:54 by hjo               #+#    #+#             */
/*   Updated: 2018/02/22 14:36:56 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 1. will use zero bytes to the string s.
** 2. n is 0 -> this func doesn't do anything.
*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *p;

	p = s;
	while (n-- != 0)
		*p++ = 0;
}
