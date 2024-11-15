/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:58:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/13 13:09:33 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	wrong_input(void)
{
	ft_putendl_fd("\033[0;31m==========Wrong input==========", 2);
	ft_putendl_fd("You can use ./fractol <fractal name>", 2);
	ft_putendl_fd("\033[0;32mFractals : julia, mandelbrot, tricorn", 2);
	ft_putendl_fd("If you choose julia you can change starting parameters", 2);
	ft_putendl_fd("Input 2 numbers between -2 and 2 after the name", 2);
	exit (1);
}

void	display_help(void)
{
	ft_printf("\033[0;34mUse the mouse wheel to zoom in and out.\n");
	ft_printf("Press \"c\" to change colors.\n");
	ft_printf("Press \"h\" to see this message again.\n");
	ft_printf("Use the arrow keys to move in the fractal.\n");
	ft_printf("Press \"ESC\" to close.");
}
