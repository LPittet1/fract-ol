/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:58:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/12 15:10:30 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	no_input(void)
{
	ft_putendl_fd("\033[0;31m==========Wrong input==========", 1);
	ft_putendl_fd("\033[0;31mYou can use ./fractol <fractal type>", 1);
	ft_putendl_fd("\033[0;32mAvailable fractals : Julia, Mandelbrot, Tricorn", 1);
	exit (1);
}

void	handle_error(char *err)
{
	if (!ft_strncmp(err, "wrong input", ft_strlen(err)))
		no_input();
}
