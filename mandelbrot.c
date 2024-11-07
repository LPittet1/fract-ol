/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:59:48 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/07 13:15:14 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

// Mandeblrot equation = z_1 = z_0 + c, where all are complex nubmber
//z_0 = 0, c = position of the plane
//Distance between the point and the value obtained must not exceed n  = (tbd),
// for a certain amount of iterations
int	mandelbrot(t_data *data, double cr, double ci)
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
		if (pow(zi - ci, 2) + pow(zr - cr, 2) > 4)
			break ;
		temp = zr * zr - zi * zi + cr;
		zi = 2 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return (i);
}
