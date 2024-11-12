/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:21:32 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/12 16:11:35 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./mlx/mlx.h"
# include "./libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

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
	int		color_scale;
}			t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		exit_prog(t_data *data);
void	handle_error(char *err);
int		fractal_manager(t_data *data, double r, double i);

int		mandelbrot(t_data *data, double cr, double ci);

int		julia(t_data *data, double zr, double zi);

int 	exit_prog(t_data *data);
int		handle_key_press(int key, t_data *data);
void	mlx_data_init(t_data *data, char **av);
int		handle_mouse(int key, int x, int y, t_data *data);
void	render(t_data *data);
void	zoom(t_data *data, double factor);
void 	get_color(t_data *data, int color);
void	get_color_better(t_data *data, int iter);
void	purple_scale(t_data *data, int iter);
void	green_scale(t_data *data, int iter);
void	gray_scale(t_data *data, int iter);
void	orange_scale(t_data *data, int iter);
int		create_color(int t, int r, int g, int b);
int		tricorn(t_data *data, double cr, double ci);
void	move_fractal(int key, t_data *data);
void	change_color_scale(t_data *data);
void	choose_color(t_data *data, int iter);
void	display_help();
double	ft_atof(char *num);

#endif