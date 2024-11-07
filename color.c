/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:15:13 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/07 13:57:23 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	get_color(t_data *data, int color)
{
	if (color < 10)
		data->color = 0x00111130;
	else if (color < 20)
		data->color = 0X0000FF00;
	else if (color < 30)
		data->color = 0x000000FF;
	else if (color < 40)
		data->color = 0x00FF0000;
	else if (color < 50)
		data->color = 0x00FFFF00;
	else if (color < 60)
		data->color = 0x0000FFFF;
	else
		data->color = 0x00000000;
}
