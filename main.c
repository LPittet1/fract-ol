/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 11:57:16 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/07 11:47:05 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
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
		exit_prog(data);
	if (key == 49)
	{
		mlx_mouse_get_pos(data->mlx_win, &data->mouse_x, &data->mouse_y);
		printf("mouse x = %i and mouse y = %i\n", data->mouse_x, data->mouse_y);
	}
	else
		print_key_num(key, data);
	return (0);
}

void	mlx_data_init(t_data *data, char **av)
{
	data->mlx = mlx_init();
	data->mlx_win = mlx_new_window(data->mlx, WIDTH, HEIGTH, av[1]);
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGTH);
	data->address = mlx_get_data_addr(data->img, &data->bits_per_pixel, &data->line_len, &data->endian);
	data->color = 0x00000000;
	data->min_x = -2.0;
	data->max_x = 2.0;
	data->max_y = 1.5;
	data->min_y = -1.5;
	data->julia_ci = 0.1;
	data->julia_cr = 0.1;
	data->name = av[1];
}

int	handle_mouse(int key, int x, int y, t_data *data)
{
	(void) x;
	(void) y;
	if (key == 5)
		zoom(data, 0.75);
	if (key == 4)
		zoom(data, 1.25);
	print_key_num(key, data);
	printf("new diff x = %f\n", data->max_x - data->min_x);
	return (0);
}
void test(t_data *data)
{
	printf("width pixel len = %f\n", (data->max_x - data->min_x) / WIDTH);
	printf("Heigth pixel len = %f\n", (data->max_y - data->min_y) / HEIGTH);
}

int main(int ac, char **av)
{
	t_data	data;
	
	if (ac < 2)
		handle_error("wrong input", &data);
	mlx_data_init(&data, av);
	render(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_mouse_get_pos(data.mlx_win, &data.mouse_x, &data.mouse_y);
	mlx_key_hook(data.mlx_win, &handle_key_press, &data);
	mlx_mouse_hook(data.mlx_win, &handle_mouse, &data);
	mlx_hook(data.mlx_win, 17, 0L, exit_prog, &data);
	mlx_loop(data.mlx);
	return (0);
}
