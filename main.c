/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:57:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/12 14:34:02 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->address + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	exit_prog(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(0);
	return (0);
}

int	handle_key_press(int key, t_data *data)
{
	if (key == 53)
		exit_prog(data);
	else if (123 <= key && key <= 136)
		move_fractal(key, data);
	else if (key == 8)
		change_color_scale(data);
	else if (key == 4)
		display_help();
	return (0);
}

void	mlx_data_init(t_data *data, char **av)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGTH, av[1]);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_len, &data->endian);
	data->color = 0x00000000;
	data->min_x = -2.0;
	data->max_x = 2.0;
	data->max_y = 1.5;
	data->min_y = -1.5;
	data->julia_ci = 0.013;
	data->julia_cr = 0.285;
	data->name = av[1];
	data->color_scale = 0;
}

int	handle_mouse(int key, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (key == 5)
		zoom(data, 0.75);
	if (key == 4)
		zoom(data, 1.25);
	return (0);
}


int	main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		handle_error("wrong input");
	mlx_data_init(&data, av);
	render(&data);
	display_help();
	mlx_key_hook(data.mlx_win, &handle_key_press, &data);
	mlx_mouse_hook(data.mlx_win, &handle_mouse, &data);
	mlx_hook(data.mlx_win, 17, 0L, exit_prog, &data);
	mlx_loop(data.mlx);
	return (0);
}
