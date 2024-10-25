/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:21:32 by lpittet           #+#    #+#             */
/*   Updated: 2024/10/25 10:33:38 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H


typedef	struct s_data	{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	void	*address;
	int		bits_per_pixel;
	int		line_len;
	int		endian;
	int		color;
}			t_data;

# include "./mlx/mlx.h"
# include "./libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>


#endif