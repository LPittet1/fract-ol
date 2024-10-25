/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:57:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/25 13:34:12 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->address + (y * data->line_len + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	draw_square(int x_start, int y_start, int size, t_data *data)
{
	int	i;

	i = 0;
	while(i < size)
	{
		my_mlx_pixel_put(data, x_start + i, y_start, 0x0000FF00);
		my_mlx_pixel_put(data, x_start, y_start + i, 0x00FFFF00);
		my_mlx_pixel_put(data, x_start + i, y_start + size, 0x0000FFFF);
		my_mlx_pixel_put(data, x_start + size, y_start + i, 0x00FF0000);
		i++;
	}
	return (0);
}

int	print_key_num(int key, t_data *data)
{
	ft_putnbr_fd(key, 1);
	ft_putchar_fd(' ', 1);
	return (data->line_len);
}
int exit_prog(t_data *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	exit(0);
	return (0);
}
int	handle_key_press(int key, t_data *data)
{
	if (key == 53)
	{
		exit_prog(data);
	}
	else
		print_key_num(key, data);
	return (0);
}
int main()
{
	t_data	data;

	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, 1000, 1000, "fractol");
	data.img = mlx_new_image(data.mlx, 1000, 1000);
	data.address = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_len, &data.endian);
	my_mlx_pixel_put(&data, 100, 100, 0x00FF0000);
	draw_square(250, 250, 50, &data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, &handle_key_press, &data);
	mlx_hook(data.mlx_win, 17, 0L, exit_prog, &data); 
	mlx_loop(data.mlx);
}
