/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 19:50:32 by hjo               #+#    #+#             */
/*   Updated: 2018/03/10 19:50:34 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	s1_size;

	i = 0;
	s1_size = 0;
	while (s1[s1_size])
		s1_size++;
	while (i < n && s2[i])
	{
		s1[s1_size] = s2[i];
		s1_size++;
		i++;
	}
	s1[s1_size] = '\0';
	return (s1);
}
