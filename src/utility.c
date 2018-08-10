int		exit_failure(void)
{
	exit(1);
	return (0);
}

int		exit_success(void)
{
	exit(0);
	return (0);
}

void display(t_fractal *i)
{
	char *iter_display;
	char *iter_num;

	iter_num = ft_atoi(i->iter_max);
	iter_display = ft_strjoin("iteration(s) : ", iter_num);
	mlx_string_put(i->mlx, i->win, 5, 5, 0xFFF000, iter_display);
	free(&iter_display);
	free(&iter_num);
}

void	put_image(t_fractal *i, double x, double y, int color)
{
	if (i->x < WIDTH && i->y < LENGTH)
	{
		color = mlx_get_color_value(i->mlx, color);
		ft_memcpy(i->image_ptr + 4 * WIDTH * y + x * 4, &color, sizeof(double));
	}
}
