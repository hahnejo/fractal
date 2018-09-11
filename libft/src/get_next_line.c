/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 16:55:48 by hjo               #+#    #+#             */
/*   Updated: 2018/05/13 19:50:25 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** fd as y and i as x.
** until it reaches new line or null, keep going.
** when it becomes new line, use strsub to store one sentence to line.
** save that string by strdup with the null's space.
** arr is now tmp.
*/

int		get_line(const int fd, char **arr, char **line)
{
	char	*tmp;
	int		i;

	i = 0;
	while (arr[fd][i] != '\n' && arr[fd][i] != '\0')
		i++;
	if (arr[fd][i] == '\n')
	{
		*line = ft_strsub(arr[fd], 0, i);
		tmp = ft_strdup(arr[fd] + i + 1);
		ft_strdel(&arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	else if (arr[fd][i] == '\0')
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

/*
** read's return value is in ret. (Total number of char read)
** creating arr to store buf into tmp.
** strdel contains free.
*/

int		get_next_line(const int fd, char **line)
{
	int			ret;
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*arr[1023];

	if (!line || fd < 0 || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strnew(1);
		tmp = ft_strjoin(arr[fd], buf);
		ft_strdel(&arr[fd]);
		arr[fd] = tmp;
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && arr[fd] == NULL)
		return (0);
	return (get_line(fd, arr, line));
}
