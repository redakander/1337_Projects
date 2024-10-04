/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:27:11 by rkander           #+#    #+#             */
/*   Updated: 2024/06/10 21:49:41 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	close_window(void *param)
{
	t_data	*data;

	data = param;
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	esc_close(int keycode, void *param)
{
	if (keycode == 53)
		close_window(param);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_data *param)
{
	(void)y;
	(void)x;
	if (button == 5)
	{
		param->min_imag *= 0.9;
		param->max_imag *= 0.9;
		param->min_real *= 0.9;
		param->max_real *= 0.9;
	}
	else if (button == 4)
	{
		param->min_imag /= 0.9;
		param->max_imag /= 0.9;
		param->min_real /= 0.9;
		param->max_real /= 0.9;
	}
	draw_fractal(param, WIDTH, HEIGHT);
	return (1);
}
