/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:30:46 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/14 11:45:23 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	exit_prog(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	init_julia(t_data *data, char **av)
{
	double	r;
	double	i;

	if (!av[2])
	{
		data->julia_cr = 0.285;
		data->julia_ci = 0.01;
	}
	else if (!av[3])
		wrong_input();
	if (av[2] && av[3])
	{
		r = ft_atof(av[2]);
		i = ft_atof(av[3]);
		if (!is_valid_digit(av[2]) || !is_valid_digit(av[3]))
			wrong_input();
		if ((-2 <= r && r <= 2)
			&& (-2 <= i && i <= 2))
		{
			data->julia_cr = r;
			data->julia_ci = i;
		}
		else
			wrong_input();
	}
}

void	mlx_data_init(t_data *data, char **av)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGTH, av[1]);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_len, &data->endian);
	data->color = 0x00000000;
	data->name = av[1];
	data->min_x = -2.0;
	data->max_x = 2.0;
	data->max_y = 1.5;
	data->min_y = -1.5;
	if (!ft_strncmp(data->name, "julia", 6))
		init_julia(data, av);
	if (ft_strncmp(data->name, "julia", 6) && av[2])
		wrong_input();
	data->color_scale = 0;
}
