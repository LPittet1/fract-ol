/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:15:13 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/11 15:02:48 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	gray_scale(t_data *data, int iter)
{
	int	i;

	i = MAX_ITER;
	data->color_scale = 3;
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
	data->color_scale = 2;
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
	data->color_scale = 2;
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
	data->color_scale = 2;
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