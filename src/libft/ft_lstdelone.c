/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <hjo@student.42.us.org>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/10 15:00:54 by hjo               #+#    #+#             */
/*   Updated: 2018/03/10 15:00:55 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	takes a link's pointer addr as param.
**	then frees mem of link's content, using func del.
**	but mem for next shouldn't be freed!
**	ptr to link (that's freed) must be set to NULL (like memdel).
*/

void	ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (!alst || !del)
		return ;
	del((*alst)->content, (*alst)->content_size);
	free(*alst);
	*alst = NULL;
	return ;
}
