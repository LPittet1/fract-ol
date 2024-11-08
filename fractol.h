/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:21:32 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/08 14:00:13 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define WIDTH 800
# define HEIGTH 600
# define MAX_ITER 60

typedef	struct	s_data	{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*address;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		color;
	int		mouse_x;
	int		mouse_y;
	double	min_x;
	double	max_x;
	double	max_y;
	double	min_y;
	double	julia_cr;
	double	julia_ci;
	char	*name;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_prog(t_data *data);
void	handle_error(char *err, t_data *data);
int	fractal_manager(t_data *data, double r, double i);
int		draw_square(int x_start, int y_start, int size, t_data *data);

int	mandelbrot(t_data *data, double cr, double ci);

int	julia(t_data *data, double zr, double zi);

int	print_key_num(int key, t_data *data);
int exit_prog(t_data *data);
int	handle_key_press(int key, t_data *data);
void	mlx_data_init(t_data *data, char **av);
int	handle_mouse(int key, int x, int y, t_data *data);
void test(t_data *data);
void	render(t_data *data);
void	zoom(t_data *data, double factor);
void get_color(t_data *data, int color);

#endif