/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 21:39:25 by hjo               #+#    #+#             */
/*   Updated: 2018/03/10 21:39:30 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	compares up to n characters of the str s1 to those in s2.
**	so an extra feature added to ft_strcmp.
**	potentially useful in comparing DNA strings :)
**	s1 and s2 will refer to regions of interest in sequence.
*/

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*seq1;
	unsigned char	*seq2;

	if (!n)
		return (0);
	seq1 = (unsigned char *)s1;
	seq2 = (unsigned char *)s2;
	while ((*seq1 && (*seq1 == *seq2)) && --n)
	{
		if (*seq1 != *seq2)
			return (*seq1 - *seq2);
		seq1 += 1;
		seq2 += 1;
	}
	return (*seq1 - *seq2);
}
