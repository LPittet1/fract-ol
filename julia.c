/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:22:57 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/07 13:13:47 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia(t_data *data, double zr, double zi)
{
	int		i;
	double	temp;

	i = 0;
	temp = 0;
	while (i < MAX_ITER)
	{
		if (pow(zi - data->julia_ci, 2) + pow(zr - data->julia_cr, 2) > 4)
			break ;
		temp = zr * zr - zi * zi + data->julia_cr;
		zi = 2 * zr * zi + data->julia_ci;
		zr = temp;
		i++;
	}
	return (i);
}
