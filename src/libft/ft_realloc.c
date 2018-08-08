/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 22:44:05 by hjo               #+#    #+#             */
/*   Updated: 2018/03/26 22:44:07 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t new_size)
{
	void	*out;
	size_t	size;
	char	*p;
	char	*op;

	p = (char *)ptr;
	size = 0;
	if (!new_size)
		new_size = 1;
	if (!ptr && (out = malloc(new_size)))
		return (out);
	while (p[size])
		size++;
	if (size + 1 == new_size)
		return (ptr);
	out = malloc(new_size);
	if (!out)
		return (NULL);
	ft_bzero(out, new_size);
	op = (char *)out;
	out = (void *)ft_strcpy(op, p);
	free(ptr);
	return (out);
}
