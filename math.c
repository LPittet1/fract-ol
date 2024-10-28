/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 08:59:00 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/28 09:56:32 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

t_data	complex_square(t_data *data)
{
	float	temp;

	temp = 2 * (data->real * data->imaginary);
	data->real = pow(data->real, 2) - pow(data->imaginary, 2);
	data->imaginary = temp;
	return (*data);
}

t_data	complex_addi(t_data *data1, t_data *data2)
{
	data1->real += data2->real;
	data1->imaginary += data2->imaginary;
	return (*data1);
}
