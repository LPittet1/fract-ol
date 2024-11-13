/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:58:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/13 09:31:59 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	no_input(void)
{
	ft_putendl_fd("\033[0;31m==========Wrong input==========", 2);
	ft_putendl_fd("You can use ./fractol <fractal name>", 2);
	ft_putendl_fd("\033[0;32mFractals : julia, mandelbrot, tricorn", 2);
	ft_putendl_fd("If you choose Julia you can change starting parameters", 2);
	ft_putendl_fd("Input 2 numbers between -2 and 2 after the name", 2);
	exit (1);
}

void	handle_error(char *err)
{
	if (!ft_strncmp(err, "wrong input", ft_strlen(err)))
		no_input();
}
