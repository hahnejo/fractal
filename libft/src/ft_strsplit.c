/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 19:38:17 by hjo               #+#    #+#             */
/*   Updated: 2018/03/11 19:38:17 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	we will get rid of whatever recurring character specified in c
**	from the string given as an arg in *s.
**	if we have hello***world**, and wanting to rid of '*',
**	use this function and ultimately give out broken words
**	that were within '*'.
*/

char				**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**w;

	i = 0;
	k = 0;
	if (!s || !(w = (char **)malloc(sizeof(char *) *
	(ft_countwords(s, c) + 1))))
		return (NULL);
	while (i < ft_countwords(s, c))
	{
		if (!(w[i] = (char *)malloc(sizeof(char) *
		(ft_wordlength(&s[k], c) + 1))))
			return (NULL);
		j = 0;
		while (s[k] == c)
			k += 1;
		while (s[k] != c && s[k])
			w[i][j++] = s[k++];
		w[i][j] = '\0';
		i += 1;
	}
	w[i] = NULL;
	return (w);
}
