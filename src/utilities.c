/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:39:33 by hjo               #+#    #+#             */
/*   Updated: 2018/08/22 17:39:35 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	multipthread(t_fractal *i)
{
	t_fractal	ft[8];
	pthread_t	id[8];
	int			c;

	ft_bzero(i->img_ptr, 800 * 800 * 4);
	c = -1;
	while (++c < 8)
	{
		ft_memcpy((void *)&ft[c], (void *)i, sizeof(t_fractal));
		ft[c].y = 100 * c;
		ft[c].y_max = 100 * (c + 1);
	}
	c = -1;
	while (++c < 8 && (i->f_type == 1 || i->f_type == 2 ||
	i->f_type == 3 || i->f_type == 4))
	{
		i->f_type == 1 ? pthread_create(&id[c], NULL,
			*execute_mandelbrot, &ft[c]) : 0;
		i->f_type == 2 ? pthread_create(&id[c], NULL,
			*execute_julia, &ft[c]) : 0;
		i->f_type == 3 ? pthread_create(&id[c], NULL,
			*execute_burningship, &ft[c]) : 0;
		i->f_type == 4 ? pthread_create(&id[c], NULL,
			*execute_hydra, &ft[c]) : 0;
	}
	c = -1;
	while (++c < 8)
		pthread_join(id[c], NULL);
	mlx_put_image_to_window(i->mlx, i->win, i->img, 0, 0);
}

void	pixel_to_image(t_fractal *i, int x, int y, int color)
{
	int tmp;

	tmp = x * 4 + y * i->sl;
	i->img_ptr[tmp] = color;
	i->img_ptr[++tmp] = i->c_coef * color;
	i->img_ptr[++tmp] = color % i->c_coeff;
}
