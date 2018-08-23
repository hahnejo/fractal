/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:39:58 by hjo               #+#    #+#             */
/*   Updated: 2018/08/22 17:39:59 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void	init_hydra(t_fractal *i)
{
	i->c_a = 0.5;
	i->c_b = 0.5;
	i->c_coef = 266;
	i->c_coeff = 100;
	i->n = 2;
	i->zoom = 1.5;
}

void	calc_hydra(t_fractal *i)
{
	double a;
	double b;
	double real;
	double imagi;
	a = 1.5 * (i->x - 400) / (200 * i->zoom) + i->x_move;
	b = (i->y - 400) / (WIDTH / 6 * i->zoom) + i->y_move;
	i->iter = -1;
	i->iter_max = 50;
	while (a * a + b * b < 4 && ++i->iter < i->iter_max)
	{
		real = a;
		imagi = b;
		a = sin(real * real - imagi * imagi) +
			pow(M_E, real * real - imagi * imagi) + i->c_a + i->julia_shape;
		b = sin(2 * real * imagi) +
			pow(M_E, 2 * real * imagi) + i->c_a + i->julia_shape;
	}
	if (i->iter < i->iter_max)
		pixel_to_image(i, i->x, i->y, (1000 * i->iter));
}

void	*execute_hydra(void *ft)
{
	t_fractal *i;
	
	i = (t_fractal *)ft;
	while (i->y < i->y_max)
	{
		i->x = 0;
		while (i->x < WIDTH)
		{
			calc_hydra(i);
			i->x++;
		}
		i->y++;
	}
	return (NULL);
}
