/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:10:36 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/13 10:35:48 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom(t_data *data, double factor)
{
	double	diff_x;
	double	diff_y;
	double	pixel_len;
	double	m_x;
	double	m_y;

	mlx_mouse_get_pos(data->mlx_win, &data->mouse_x, &data->mouse_y);
	diff_x = (data->max_x - data->min_x) * factor;
	diff_y = (data->max_y - data->min_y) * factor;
	pixel_len = diff_x / WIDTH;
	m_x = data->min_x + (data->mouse_x * (data->max_x - data->min_x) / WIDTH);
	m_y = data->max_y - (data->mouse_y * (data->max_y - data->min_y) / HEIGTH);
	data->max_x = m_x + (WIDTH - data->mouse_x) * pixel_len;
	data->min_x = data->max_x - diff_x;
	data->max_y = m_y + (data->mouse_y) * pixel_len;
	data->min_y = data->max_y - diff_y;
	render(data);
}

void	change_color_scale(t_data *data)
{
	if (data->color_scale >= 0 && data->color_scale <= 2)
		data->color_scale += 1;
	else
		data->color_scale = 0;
	render(data);
}

void	move_fractal(int key, t_data *data)
{
	double	displacement;

	displacement = 20 * (data->max_x - data->min_x) / WIDTH;
	if (key == 126)
	{
		data->min_y += displacement;
		data->max_y += displacement;
	}
	else if (key == 125)
	{
		data->min_y -= displacement;
		data->max_y -= displacement;
	}
	else if (key == 124)
	{
		data->min_x += displacement;
		data->max_x += displacement;
	}
	else if (key == 123)
	{
		data->min_x -= displacement;
		data->max_x -= displacement;
	}
	render(data);
}

int	handle_mouse(int key, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (key == 5)
		zoom(data, 0.8);
	if (key == 4)
		zoom(data, 1.25);
	return (0);
}

int	handle_key_press(int key, t_data *data)
{
	if (key == 53)
		exit_prog(data);
	else if (123 <= key && key <= 136)
		move_fractal(key, data);
	else if (key == 8)
		change_color_scale(data);
	else if (key == 4)
		display_help();
	return (0);
}
