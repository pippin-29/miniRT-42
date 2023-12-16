/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:43:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 06:21:14 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	load_brightness_ratio(char *line)
{
	float	out;
	char 	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * 32);
	while (line[i] || line[i] != ' ')
	{
		if (!ft_isdigit(line[i]) || line[i] != '.')
			error_parse("Brightness Ratio ( Input NAN )");
		temp[i] = line[i];
		i++;
	}
	out = atof(temp);
	if (out < 0.0 || out > 1.0)
		error_parse("Brightness Ratio Range ( 0.0 - 1.0 )");
	free(temp);
	return (out);
}

float	*load_normal_vector(char *line)
{
	float	*out;
	char	*temp;
	int		i;
	int		q;
	int		l;

	i = 0;
	q = 0;
	l = 0;
	out = malloc(sizeof(float) * 3);
	temp = malloc(sizeof(char) * 32);
	while (line[i])
	{
		q = 0;
		while (line[i] != ',')
		{
			if (!ft_isdigit(line[i]) || line[i] != '.')
				error_parse("Normallized Vector ( Input NAN )");
			temp[q] = line[i];
			q++;
			i++;
		}
		out[l] = atof(temp);
		if (out[l] < 0.0 || out[l] > 1.0)
			error_parse("Normallized Vector Range ( 0.0 - 1.0 )");
		l++;
	}
	free(temp);
	return (out);
}

float	load_dimension(char *line)
{
	float	out;
	char 	*temp;
	int		i;

	i = 0;
	temp = malloc(sizeof(char) * 32);
	while (line[i] || line[i] != ' ')
	{
		if (!ft_isdigit(line[i]) || line[i] != '.')
			error_parse("Dimension ( Input NAN )");
		temp[i] = line[i];
		i++;
	}
	out = atof(temp);
	free(temp);
	return (out);
}

float	*load_coordinates(char *line)
{
	float	*out;
	char	*temp;
	int		i;
	int		q;
	int		l;

	i = 0;
	q = 0;
	l = 0;
	out = malloc(sizeof(float) * 3);
	temp = malloc(sizeof(char) * 32);
	while (line[i])
	{
		q = 0;
		while (line[i] != ',')
		{
			if (!ft_isdigit(line[i]) || line[i] != '.')
				error_parse("Coordinates ( Input NAN )");
			temp[q] = line[i];
			q++;
			i++;
		}
		out[l] = atof(temp);
		l++;
	}
	free(temp);
	return (out);
}

t_u32	*load_rgb_values(char *line)
{
	char	*temp;
	t_u32	*out;
	int		i;
	int		q;
	int		l;

	i = 0;
	l = 0;
	temp = malloc(sizeof(char) * 32);
	out = malloc(sizeof(t_u32) * 3);
	while (line[i])
	{
		q = 0;
		while (line[i] != ',')
		{
			if (!ft_isdigit(line[i]))
				error_parse("RGB ( Input NAN )");
			temp[q] = line[i];
			q++;
			i++;
		}
		out[l] = ft_atoi(temp);
		l++;
	}
	free(temp);
	return (out);
}
