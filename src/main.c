/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hjo <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 17:39:19 by hjo               #+#    #+#             */
/*   Updated: 2018/08/22 17:39:20 by hjo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractal.h"

int		check_param(t_fractal *i, char *str)
{
	if (ft_strcmp(str, "mandelbrot") == 0)
		i->f_type = 1;
	else if (ft_strcmp(str, "julia") == 0)
		i->f_type = 2;
	else if (ft_strcmp(str, "burningship") == 0)
		i->f_type = 3;
	else if (ft_strcmp(str, "hydra") == 0)
		i->f_type = 4;
	else
	{
		correct_usage();
		return (0);
	}
	return (1);
}

void	execute_fractal(t_fractal *i)
{
	if (i->f_type == 1)
	{
		init_mandelbrot(i);
		multipthread(i);
	}
	if (i->f_type == 2)
	{
		init_julia(i);
		multipthread(i);
	}
	if (i->f_type == 3)
	{
		init_burningship(i);
		multipthread(i);
	}
	if (i->f_type == 4)
	{
		init_hydra(i);
		multipthread(i);
	}
}

/*
** This function runs the window
** While running the window, it readily takes keys
*/

void	set_window(t_fractal *i)
{
	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, WIDTH, HEIGHT, "fractal");
	i->img = mlx_new_image(i->mlx, WIDTH, HEIGHT);
	i->img_ptr = mlx_get_data_addr(i->img, &i->bpp, &i->sl, &i->en);
}

void	run_window(t_fractal *i)
{
	mlx_hook(i->win, 2, 0, key_hook, i);
	mlx_hook(i->win, 6, 0, pointer_hook, i);
	mlx_mouse_hook(i->win, mouse_hook, i);
	mlx_hook(i->win, 17, 0, exit_hook, i);
	mlx_loop(i->mlx);
}

int		main(int argc, char **argv)
{
	t_fractal	*i;

	if (!(i = ft_memalloc(sizeof(t_fractal))))
		return (-1);
	if (argc == 2)
	{
		if (check_param(i, argv[1]) == 0)
			return (0);
		open_usage();
		set_window(i);
		execute_fractal(i);
		run_window(i);
	}
	else if (argc != 2)
		correct_usage();
	return (0);
}
