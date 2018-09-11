/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/11 20:23:00 by hjo               #+#    #+#             */
/*   Updated: 2018/03/11 20:23:02 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	allocates and returns fresh link.
**	var content and content_size are initialized by copy of param of func.
**	if param content is null, var content is also null.
*/

t_list		*ft_lstnew(const void *content, size_t content_size)
{
	t_list		*new_link;

	if (!(new_link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content || !content_size)
	{
		new_link->content = NULL;
		new_link->content_size = 0;
	}
	else
	{
		new_link->content = ft_memalloc(content_size);
		new_link->content = ft_memcpy(new_link->content, content, content_size);
		new_link->content_size = content_size;
	}
	return (new_link);
}
