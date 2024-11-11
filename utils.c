/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:26:40 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/11 14:25:27 by lpittet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *num)
{
	double	whole;
	double	decimal;
	int		len;
	
	whole = ft_atoi(num);
	while (*num != '.')
		num++;
	if (*num == '.')
		num++;
	decimal = ft_atoi(num);
	len = ft_strlen(num);
	while (len > 0)
	{
		decimal /= 10;
		len--;
	}
	if (whole >= 0)
		return (whole + decimal);
	else
		return (whole - decimal);
}

int	create_color(int t, int r, int g, int b)
{
	return (t <<  24 | r << 16 | g << 8 | b);
}