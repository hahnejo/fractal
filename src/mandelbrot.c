#include "fractal.h"

void	mandelbrot_setting(t_fractal *i)
{
	i->iter_max = 45;
	i->color = 265;
	i->x1 = -2.05;
	i->y1 = -1.3;
	i->zoom = 250;
	i->c_real = i->x / i->zoom + i->x1;
	i->c_image = i->y / i->zoom + i->y1;
	i->z_real = 0;
	i->z_image = 0;
}

void	calc_mandelbrot(t_fractal *i)
{
	double sqared;

	sqared = i->z_real * i->z_real + i->z_image * i->z_image;
	while (sqared < 4 && i->iter < i->iter_max)
	{
		i->temp = i->z_real;
		i->z_real = i->z_real * i->z_real - i->z_image * i->z_image + i->c_real;
		i->z_image = 2 * i->z_real * i->z_image + i->c_image;
		i->iter++;
	}
	if (i->iter == i->iter_max)
		put_image(i, i->x, i->y, 0);
}

void	process_mandelbrot(t_fractal *i)
{
	if (i->f_type == 0)
	{
		mandelbrot_setting(i);
		calc_mandelbrot(i);
	}
}
