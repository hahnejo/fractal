void mandelbrot_setting(t_fractal *i)
{
  i->iter_max = 45;
  i->color = ;
}

void mandelbrot()
{
  z_real = z_real * z_real - z_im * z_im + c_real;
  z_im = 2 * z_real * z_im + c_im;
}
