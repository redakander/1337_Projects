/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:26:18 by rkander           #+#    #+#             */
/*   Updated: 2024/06/13 15:57:42 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_Complexe z, double real, double imag)
{
	double	a;
	double	b;
	double	x;
	double	y;

	z.iteration = 0;
	while (z.iteration < MAX_ITERATION)
	{
		a = z.real * z.real;
		b = z.real * z.imag;
		x = z.imag * z.real;
		y = z.imag * z.imag;
		z.real = a - y + real;
		z.imag = b + x + imag;
		if (z.real * z.real + z.imag * z.imag > 4)
			return (z.iteration * 5);
		z.iteration++;
	}
	return (z.iteration);
}

int	mandelbrot(t_Complexe c)
{
	t_Complexe	z;
	double		a;
	double		b;
	double		x;
	double		y;

	z.real = 0;
	z.imag = 0;
	z.iteration = 0;
	while (z.iteration < MAX_ITERATION)
	{
		a = z.real * z.real;
		b = z.real * z.imag;
		x = z.imag * z.real;
		y = z.imag * z.imag;
		z.real = a - y + c.real;
		z.imag = b + x + c.imag;
		if (z.real * z.real + z.imag * z.imag > 4)
			return (z.iteration * 5);
		z.iteration++;
	}
	return (z.iteration);
}

int	draw(t_data *data, int x, int y)
{
	t_Complexe	c;

	c.imag = data->max_imag - y * (data->max_imag - data->min_imag)
		/ (double)WIDTH;
	c.real = data->min_real + x * (data->max_real - data->min_real)
		/ (double)HEIGHT;
	if (ft_strcmp(data->fractal, "mandelbrot"))
		return (mandelbrot(c));
	else if (ft_strcmp(data->fractal, "julia"))
		return (julia(c, ft_atoi(data->argv[2]), ft_atoi(data->argv[3])));
	return (0);
}

void	draw_fractal(t_data *data, int width, int height)
{
	int	x;
	int	y;
	int	color;

	x = 0;
	while (x < width)
	{
		y = 0;
		while (y < height)
		{
			color = draw(data, x, y);
			my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	error_handlling(argc, argv);
	data.argv = argv;
	data.fractal = argv[1];
	data.min_real = -2.0;
	data.max_real = 2.0;
	data.min_imag = -2.0;
	data.max_imag = 2.0;
	data.mlx = mlx_init();
	if (!data.mlx)
		exit(1);
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
	if (!data.mlx)
		exit(1);
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (!data.img)
		exit(1);
	data.addr = mlx_get_data_addr(data.img,
			&data.bits_per_pixel, &data.line_length, &data.endian);
	draw_fractal(&data, WIDTH, HEIGHT);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_hook(data.win, 2, 0, esc_close, &data);
	mlx_mouse_hook(data.win, mouse_hook, &data);
	mlx_loop(data.mlx);
}
