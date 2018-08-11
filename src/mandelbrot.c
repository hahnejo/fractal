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

void	mandelbrot_calc(t_fractal *i)
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
		put_image(i, i->x, i->y, 0x5a0000);
	else
		put_image(i, i->x, i->y, (i->color * i->iter));
}

void	*mandelbrot_process(void *tab)
{
	t_fractal *info;
	double tmp;

	info = (t_fractal *)tab;
	info->x = 0;
	tmp = info->y;
	while (info->x < WIDTH)
	{
		info->y = tmp;
		while (info->y < info->y_max)
		{
			mandelbrot_calc(info);
			info->y++;
		}
		info->x++;
	}
	return (tab);
}

void mandelbrot_pthread(t_fractal *i)
{
	t_fractal arr[4];
	pthread_t p[4];
	int c;

	c = 0;
	while (c < 4)
	{
		ft_memcpy((void *)&arr[c], (void *)i, sizeof(t_fractal));
		arr[c].y = 100 * c;
		arr[c].x = 100 * (c + 1);
		c++;
	}
	c = 0;
	while (++c <= 4)
		pthread_create(&p[c - 1], NULL, mandelbrot_process, &arr[c - 4]);
	while (c--)
		pthread_join(p[c], NULL);
	mlx_put_image_to_window(i->mlx, i->win, i->image, 0, 0);
}
