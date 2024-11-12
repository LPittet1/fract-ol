/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:08:05 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/12 14:23:15 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	render(t_data *data)
{
	double	real;
	double	im;
	int		x;
	int		y;
	int		iter;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGTH)
		{
			real = data->min_x + x *((data->max_x - data->min_x) / WIDTH);
			im = data->max_y - y * ((data->max_y - data->min_y) / HEIGTH);
			iter = fractal_manager(data, real, im);
			choose_color(data, iter);
			my_mlx_pixel_put(data, x, y, data->color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
}

int	fractal_manager(t_data *data, double r, double i)
{
	if (!ft_strncmp(data->name, "mandelbrot", 11))
		return (mandelbrot(data, r, i));
	else if (!ft_strncmp(data->name, "julia", 6))
		return (julia(data, r, i));
	else if (!ft_strncmp(data->name, "tricorn", 7))
		return (tricorn(data, r , i));
	else
		handle_error("wrong input");
	return (0);
}
