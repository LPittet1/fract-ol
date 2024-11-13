/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 10:30:46 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/13 10:31:21 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

int	exit_prog(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	exit(0);
}

void	init_julia(t_data * data, char **av)
{
	if (!av[2])
	{
		data->julia_cr = 0.285;
		data->julia_ci = 0.013;
	}
	else if (!av[3])
		handle_error("wrong input");
	if (av[2] && av[3])
	{
		if (!is_valid_digit(av[2]) || !is_valid_digit(av[3]))
			handle_error("wrong input");
		if ((-2 < ft_atof(av[2]) && ft_atof(av[2]) < 2)
			&&(-2 < ft_atof(av[3]) && ft_atof(av[3]) < 2))
		{
		data->julia_cr = ft_atof(av[2]);
		data->julia_ci = ft_atof(av[3]);
		}
		else
			handle_error("wrong input");
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
	data->color_scale = 0;
}