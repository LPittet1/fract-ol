/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpittet <lpittet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 16:26:40 by lpittet           #+#    #+#             */
/*   Updated: 2024/11/13 09:52:21 by lpittet          ###   ########.fr       */
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

int	is_valid_digit(char *str)
{
	int i;
	int dot;

	i = 0;
	dot = 0;
	while (str[i])
	{
		if (i== 0 && (str[i] == '-' || str[i] == '+'))
			i++;
		if (!ft_isdigit(str[i]))
		{
			if (str[i] == '.' && dot == 1)
				return (0);
			else if (str[i] == '.' && dot == 0)
				dot = 1;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
