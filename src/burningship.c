/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:38:54 by hjo               #+#    #+#             */
/*   Updated: 2018/08/22 17:38:55 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

void init_burningship(t_fractal *i)
{
	i->c_coef = 225;
	i->c_coeff = 233;
	i->x_move = 0;
	i->y_move = 0;
	i->zoom = 1.5;
}

void calc_burningship(t_fractal *i)
{
	double a;
	double b;
	double real;
	double imagi;

	a = 1.5 * (i->x - 400) / (200 * i->zoom) + i->x_move;
	b = (i->y - 400) / (WIDTH / 6 * i->zoom) + i->y_move;
	i->iter = -1;
	i->iter_max = 100;
	i->c_a = 0;
	i->c_b = 0;
	while (i->c_a * i->c_a + i->c_b * i->c_b < 4 && ++i->iter < i->iter_max)
	{
		real = i->c_a;
		imagi = i->c_b;
		i->c_a = real * real - imagi * imagi + a;
		i->c_b = fabs(2 * real * imagi) + b;
	}
	if (i->iter < i->iter_max)
		pixel_to_image(i, i->x, i->y, (1000 * i->iter));
}

void *execute_burningship(void *ft)
{
	t_fractal *i;
	
	i = (t_fractal *)ft;
	while (i->y < i->y_max)
	{
		i->x = 0;
		while (i->x < WIDTH)
		{
			calc_burningship(i);
			i->x++;
		}
		i->y++;
	}
	return (NULL);
}
