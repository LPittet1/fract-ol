/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:10:36 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/07 11:14:40 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *data, double factor)
{
	double	c_x = 0;
	double	c_y = 0;
	double	diff_x = 1;
	double	diff_y = 1;
	
	mlx_mouse_get_pos(data->mlx_win, &data->mouse_x, &data->mouse_y);
	c_x = data->min_x + (data->mouse_x * (data->max_x - data->min_x) / WIDTH);
	c_y = data->max_y - (data->mouse_y * (data->max_y - data->min_y) / HEIGTH);
	diff_x = (data->max_x - data->min_y) * factor / 2;
	diff_y = (data->max_y - data->min_y) * factor / 2;
	data->max_x = c_x + diff_x;
	data->min_x = c_x - diff_x;
	data->max_y = c_y + diff_y;
	data->min_y = c_y - diff_y;
	render(data);
}
// zoom faux ne change pas l'image