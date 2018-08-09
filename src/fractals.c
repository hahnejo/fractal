
#include "fractal.h"

void	correct_usage(void)
{
	ft_putendl("Please try: ./fractal <mandelbrot/julia>");
}

void	window_init(t_fractal *i)
{
	i->mlx = mlx_init();
	printf("mlx_init complete");
	i->win = mlx_new_window(i->mlx, WIDTH, LENGTH, "fractal");
	i->image = mlx_new_image(i->mlx, WIDTH, LENGTH);
	i->image_ptr = mlx_get_data_addr(i->image, &i->bpp, &i->s_l, &i->endian);
}

int		param_check(char **argv, t_fractal *i)
{
	if (argv[1] == "mandelbrot")
		i->f_type = 0;
	else if (argv[1] == "julia")
		i->f_type = 1;
	else
		correct_usage();
		return (0);
	return (1);
}

void	run_window(t_fractal *i)
{
	mlx_hook(i->win, 4, 4, deal_key, i);
	mlx_key_hook(i->win, deal_key, i);
	mlx_mouse_hook(i->win, deal_key, i);
	mlx_loop(i->mlx);
}

int		main(int argc, char **argv)
{
	t_fractal *i;

	if (!(i = (t_fractal *)malloc(sizeof(t_fractal))))
		return (-1);
	if (argc == 2)
	{
		window_init(i);
		if (param_check(argv, i) == 0)
			return (0);
		run_window(i);
	}
	else
		correct_usage();
	return (0);
}
