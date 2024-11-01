/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 11:08:05 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/01 11:18:51 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	fractal_manager(t_data *data, char *fract)
{
	int	len;

	len = ft_strlen(fract);
	if (!ft_strncmp(fract, "mandelbrot", len))
		mandelbrot(data);
	else if (!ft_strncmp(fract, "julia", len))
		julia(data);
	else
		handle_error("wrong input", data);
}