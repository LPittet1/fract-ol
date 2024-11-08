/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:10:36 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/08 15:10:02 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *data, double factor)
{
	// double	c_x;
	// double	c_y;
	double	diff_x;
	double	diff_y;

	// mlx_mouse_get_pos(data->mlx_win, &data->mouse_x, &data->mouse_y);
	diff_x = (data->max_x - data->min_x) * factor / 2;
	diff_y = (data->max_y - data->min_y) * factor / 2;
	// c_x = 	data->min_x * factor + (data->mouse_x * (2 * diff_x) / WIDTH);
	// c_y = data->max_y * factor - (data->mouse_y * (2 * diff_y) / HEIGTH);
	data->max_x = diff_x;
	data->min_x = -diff_x;
	data->max_y = diff_y;
	data->min_y = -diff_y;
	render(data);
}
