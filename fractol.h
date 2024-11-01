/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:21:32 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/01 14:19:40 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H


typedef	struct s_data	{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*address;
	double	imaginary;
	double	real;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		color;
	int		mouse_x;
	int		mouse_y;
}			t_data;

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>


void 	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int 	exit_prog(t_data *data);
void	handle_error(char *err, t_data *data);
void	fractal_manager(t_data *data, char *fract);
int		draw_square(int x_start, int y_start, int size, t_data *data);

void	mandelbrot(t_data *data);

void	julia(t_data *data);

#endif