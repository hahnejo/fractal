
void correct_usage(void)
{
  ft_putendl("Please try: ./fractal <mandelbrot/julia>");
}

void window_init(t_fractal *i)
{
  i->mlx = mlx_init();
  i->win = mlx_new_window(i->mlx, WIDTH, LENGTH, "fractal");
  i->image = mlx_new_image(i->mlx, WIDTH, LENGTH);
  i->image_ptr = mlx_get_data_addr(i->image, &i->bpp, &i->sl, &i->endian);
}

int param_check(char **argv, t_fractal *i)
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

void run_window()
{
  mlx_hook();
  mlx_key_hook();
  mlx_mouse_hook();
  mlx_loop();
}

int main(int argc, char **argv)
{
  t_fractal *i;

  if (!(i = (t_fractal *)malloc(sizeof(t_fractal)))
    return (-1);
  if (argc == 2)
  {
    window_init(i);
    if (param_check(argv, i) == 0)
      return (0);
    run_window();
  }
  else
    correct_usage();
  return (0);
}
