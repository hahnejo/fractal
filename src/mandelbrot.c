#include "fractal.h"

void mandelbrot_setting(t_fractal *i)
{
	i->iter_max = 45;
	i->color = 265;
	i->x1 = -2.05;
	i->y1 = -1.3;
}

void mandelbrot(t_fractal *i)
{
	i->z_real = i->z_real * i->z_real - i->z_image * i->z_image + i->c_real;
	i->z_image = 2 * i->z_real * i->z_image + i->c_image;
}
