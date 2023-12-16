/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:27:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 05:00:50 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt_functions.h"

void	parse_light(char *line, t_program *program)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	program->light->coord = load_coordinates(&line[i], program);
	while (line[i] == ' ')
		i++;
	program->light->brightness = load_float_ratio(&line[i], program);
}

void	parse_ambient(char *line, t_program *program)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	program->amb_light->brightness = load_float_ratio(&line[i], program);
	while (line[i] == ' ')
		i++;
	program->amb_light->rgb = load_rgb_values(&line[i], program);
}

float	*load_coordinates(char *line, t_program *program)
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
		out[l] = ft_atof(temp);
		l++;
	}
	retrun (out);
}

t_u32	*load_rgb_values(char *line, t_program *program)
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
	return (out);
}

float	load_brightness_ratio(char *line, t_program *program)
{
	char	arr[4];
	float	out;
	int		i;

	i = 0;
	while (i < 4)
	{
		arr[i] = line[i];
		i++;
	}
	out = atof(arr);
	if (out < 0.0 || out > 1.0)
		error_parse("BRIGHTNESS RATIO (range: 0.0 - 1.0 )");
	return (out);
}
