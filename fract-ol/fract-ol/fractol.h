/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkander <rkander@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 17:26:49 by rkander           #+#    #+#             */
/*   Updated: 2024/06/13 16:12:56 by rkander          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define MAX_ITERATION 400
# define WIDTH 1000
# define HEIGHT 1000
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>

typedef struct s_Complexe
{
	double	real;
	double	imag;
	double	a;
	double	b;
	double	x;
	double	y;
	int		iteration;
}	t_Complexe;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
	char	*fractal;
	char	**argv;
	int		width;
	int		height;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		close_window(void *param);
int		mouse_hook(int button, int x, int y, t_data *param);
void	draw_fractal(t_data *data, int width, int height);
double	ft_atoi(const char *nptr);
int		esc_close(int keycode, void *param);
int		ft_strcmp(const char *s1, const char *s2);
void	error_handlling(int argc, char **argv);
#endif