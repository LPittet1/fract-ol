/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:15:13 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/13 10:34:23 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	gray_scale(t_data *data, int iter)
{
	int	i;

	i = MAX_ITER;
	data->color = 0x00000000;
	while (i > iter)
	{
		data->color += create_color(0, i, i, i);
		i--;
	}
}

void	purple_scale(t_data *data, int iter)
{
	int	i;

	i = MAX_ITER;
	if (i == iter)
		data->color = 0x00000000;
	else
		data->color = 0x0041077a;
	while (i > iter)
	{
		data->color += create_color(0, i, 0, i);
		i--;
	}
}

void	green_scale(t_data *data, int iter)
{
	int	i;

	i = MAX_ITER;
	if (i == iter)
		data->color = 0x00000000;
	else
		data->color = 0x002a751c;
	while (i > iter)
	{
		data->color += create_color(0, 0, i, i);
		i--;
	}
}

void	orange_scale(t_data *data, int iter)
{
	int	i;

	i = MAX_ITER;
	if (i == iter)
		data->color = 0x00000000;
	else
		data->color = 0x00eb8831;
	while (i > iter)
	{
		data->color += create_color(0, 0, i, i);
		i--;
	}
}

void	choose_color(t_data *data, int iter)
{
	if (data->color_scale == 0)
		purple_scale(data, iter);
	else if (data->color_scale == 1)
		orange_scale(data, iter);
	else if (data->color_scale == 2)
		green_scale(data, iter);
	else if (data->color_scale == 3)
		gray_scale(data, iter);
}
