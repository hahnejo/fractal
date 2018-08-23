/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:39:00 by hjo               #+#    #+#             */
/*   Updated: 2018/08/22 17:39:02 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_julia(t_fractal *i)
{
	i->c_a = -0.8;
	i->c_b = 0.156;
	i->c_coef = 555;
	i->c_coeff = 233;
	i->zoom = 1.5;
}

void	calc_julia(t_fractal *i)
{
	double a;
	double b;
	double real;
	double imagi;

	a = 1.5 * (i->x - 400) / (200 * i->zoom) + i->x_move;
	b = (i->y - 400) / (WIDTH / 6 * i->zoom) + i->y_move;
	i->iter = -1;
	i->iter_max = 100;
	while (a * a + b * b <= 4 && ++i->iter < i->iter_max)
	{
		real = a;
		imagi = b;
		a = real * real - imagi * imagi + i->c_a + i->julia_shape;
		b = 2 * real * imagi - i->c_b + i->julia_shape;
	}
	if (i->iter < i->iter_max)
		pixel_to_image(i, i->x, i->y, (1000 * i->iter));
}

void	*execute_julia(void *ft)
{
	t_fractal *i;
	
	i = (t_fractal *)ft;
	while (i->y < i->y_max)
	{
		i->x = 0;
		while (i->x < WIDTH)
		{
			calc_julia(i);
			i->x++;
		}
		i->y++;
	}
	return (NULL);
}
