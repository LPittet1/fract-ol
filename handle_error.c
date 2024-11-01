/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:58:25 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/01 10:46:50 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	no_input(void)
{
	ft_putendl_fd("==========Wrong input==========", 1);
	ft_putendl_fd("You can use ./fractol <fractal type>", 1);
}

void	handle_error(char *err, t_data *data)
{
	if (!ft_strncmp(err, "wrong input", ft_strlen(err)))
	{
		no_input();
	}
	exit_prog(data);
}