/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atofloat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:07:10 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/15 18:03:28 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt_functions.h"

int	is_float(char *c)
{
	int	i = 0;
	int decimal_pos = 0;
	int decimal_present = 0;
	int negative = 0;
	if (c[i] == '-')
	{
		negative = 1;
		i = 1;
	}	
	while (c[i])
	{
		if (c[i] < '0' || c[i] > '9')
		{
			if (c[i] != '.')
				return (0);
		}
		i++;
	}
	i = (negative == 0) ? 0 : 1;
	while ((c[i] >= '0' && c[i] <= '9') || c[i] == '.')
	{
		i++;
		if (c[i] == '.' && !decimal_present)
		{
			decimal_pos = i;
			decimal_present = 1;
		}
	}
	if (i > 8)
		return (0);
	return (decimal_pos);
}

float strict_atofloat(char *number)
{
	float	f = 0.0;
	int 	i = 0;
	int		lowpower = 0;
	int		negative = 0;
	if (is_float(number))
	{
		int decimal_pos = is_float(number);
		if (number[i] == '-')
		{
			negative = 1;
			i = 1;
		}	
		while (number[i])
			i++;
		lowpower = i - decimal_pos;
		i = (negative == 0) ? 0 : 1;
		while (number[i])
		{
			if (number[i] == '.')
				i++;
			f = f + (number[i] - 48);
			f *= 10;
			i++;
		}
		while (lowpower)
		{
			f *= 0.1;
			lowpower--;
		}
	}
	else
		return (1000);
	return ((negative == 0) ? f : f * -1);
}