/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:57:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/13 11:40:03 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2 || ac > 4)
		wrong_input();
	mlx_data_init(&data, av);
	render(&data);
	display_help();
	mlx_key_hook(data.mlx_win, &handle_key_press, &data);
	mlx_mouse_hook(data.mlx_win, &handle_mouse, &data);
	mlx_hook(data.mlx_win, 17, 0L, exit_prog, &data);
	mlx_loop(data.mlx);
	return (0);
}
