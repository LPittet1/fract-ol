/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:08:05 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/07 11:46:00 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_data *data)
{
	double	real;
	double	imaginary;
	int		x;
	int		y;
	int		color;
	
	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			real = data->min_x + (double)x *((data->max_x - data->min_x) / WIDTH);
			imaginary = data->max_y - (double)y * ((data->max_y - data->min_y) / HEIGTH);
			color = fractal_manager(data, real, imaginary);
			get_color(data, color);
			my_mlx_pixel_put(data, x, y, data->color);
			y++;
		}
		x++;
	}
	mlx_new_image(data->mlx, WIDTH, HEIGTH);
}

int	fractal_manager(t_data *data, double r,  double i)
{
	if (!ft_strncmp(data->name, "mandelbrot", 10))
		return (mandelbrot(data, r, i));
	else if (!ft_strncmp(data->name, "julia", 5))
		return(julia(data, r, i));
	else
		handle_error("wrong input", data);
	return (0);
}