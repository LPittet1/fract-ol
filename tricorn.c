/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tricorn.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 10:05:36 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/12 10:30:35 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	tricorn(t_data *data, double cr, double ci)
{
	int		i;
	double	zr;
	double	zi;
	double	temp;

	(void) data;
	i = 0;
	zr = 0;
	zi = 0;
	temp = 0;
	while (i < MAX_ITER)
	{
		if (pow(zi, 2) + pow(zr, 2) > 4)
			break ;
		temp = zr * zr - zi * zi + cr;
		zi = -2 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}