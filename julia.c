/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:22:57 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/14 10:40:04 by lpittet          ###   ########.fr       */
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
		if (zi * zi + zr * zr > 4)
			break ;
		temp = zr * zr - zi * zi + data->julia_cr;
		zi = 2 * zr * zi + data->julia_ci;
		zr = temp;
		i++;
	}
	return (i);
}
