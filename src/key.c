/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:39:06 by hjo               #+#    #+#             */
/*   Updated: 2018/08/22 17:39:09 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		key_hook(int key, t_fractal *i)
{
	if (key == 53)
	{
		mlx_destroy_image(i->mlx, i->img);
		mlx_destroy_window(i->mlx, i->win);
		exit(0);
	}
	key == 69 ? i->zoom *= 1.2 : 0;
	key == 78 ? i->zoom /= 1.2 : 0;
	key == 123 ? i->x_move -= 0.005 : 0;
	key == 124 ? i->x_move += 0.005 : 0;
	key == 126 ? i->y_move -= 0.005 : 0;
	key == 125 ? i->y_move += 0.005 : 0;
	key == 12 ? i->julia_shape += 0.040 : 0;
	key == 13 ? i->julia_shape -= 0.040 : 0;
	key == 8 ? i->c_coef += 20 : 0;
	key == 8 ? i->c_coeff += 10 : 0;
	key == 34 ? i->iter += 1 : 0;
	key == 31 && i->iter > 1 ? i->iter -= 1 : 0;
	if (key == 53 || key == 69 || key == 78 || key == 123 || key == 124 ||
		key == 125 || key == 126 || key == 8 || key == 12 || key == 13 ||
		key == 45 || key == 46 || key == 34 || key == 31)
		multipthread(i);
	return (0);
}

int		pointer_hook(int a, int b, t_fractal *i)
{
	if ((i->f_type == 1 || i->f_type == 2 || i->f_type == 3
	|| i->f_type == 4) && a >= 0 && b >= 0)
	{
		i->pointer_x = (a - WIDTH / 4);
		i->pointer_y = (b - HEIGHT / 4);
		multipthread(i);
	}
	return (0);
}

int		mouse_hook(int key, int x, int y, t_fractal *i)
{
	float a;
	float b;

	a = (float)((2 * x - WIDTH) / (WIDTH / 2) / i->zoom);
	b = (float)((2 * y - HEIGHT) / (HEIGHT / 2) / i->zoom);
	if (key == 4)
	{
		i->x_move += (float)(a / 2);
		i->y_move += (float)(b / 2);
		i->zoom *= 1.2;
	}
	if (key == 5)
	{
		i->x_move -= (float)(a / 2);
		i->y_move -= (float)(b / 2);
		i->zoom /= 1.2;
	}
	if (key == 4 || key == 5)
		multipthread(i);
	return (0);
}
