/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:43:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 09:27:57 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

float	load_brightness_ratio(char *line, t_program *p)
{
	float	out;
	char	*endptr;

	out = strtof(&line[p->i], &endptr);
	if (out < 0.0 || out > 1.0)
		error_parse("Brightness Ratio Range ( 0.0 - 1.0 )", p);
	p->i = endptr - line;
	return (out);
}

float	*load_normal_vector(char *line, t_program *p)
{
	float	*out;
	char	*endptr;
	int		i;

	i = 0;
	out = malloc(sizeof(float) * 3);
	out[X] = strtof(&line[p->i], &endptr);
	if (*endptr == ',')
		out[Y] = strtof(endptr + 1, &endptr);
	else
		error_parse("Normalized Vector Configuration ( ',' Between Values )", p);
	if (*endptr == ',')
		out[Z] = strtof(endptr + 1, &endptr);
	else
		error_parse("Normalized Vector Configuration ( ',' Between Values )", p);
	p->i = endptr - line;
	while (i < 3)
	{
		if (out[i] < 0.0 || out[i] > 1.0)
			error_parse("Normalized Vector Range ( 0.0 - 1.0 )", p);
		i++;
	}
	return (out);
}

float	load_dimension(char *line, t_program *p)
{
	float	out;
	char	*endptr;

	out = strtof(&line[p->i], &endptr);
	if (out < 0)
		error_parse("Dimensions Must Be Positive!", p);
	p->i = endptr - line;
	return (out);
}

float	*load_coordinates(char *line, t_program *p)
{
	float	*out;
	char	*endptr;

	out = malloc(sizeof(float) * 3);
	out[X] = strtof(&line[p->i], &endptr);
	if (*endptr == ',')
		out[Y] = strtof(endptr + 1, &endptr);
	else
		error_parse("Coordinate Configuration ( ',' Between Values )", p);
	if (*endptr == ',')
		out[Z] = strtof(endptr + 1, &endptr);
	else
		error_parse("Coordinate Configuration ( ',' Between Values )", p);
	p->i = endptr - line;
	return (out);
}

t_u32	*load_rgb_values(char *line, t_program *p)
{
	t_u32	*out;
	char	*endptr;
	t_u32	i;

	i = 0;
	out = malloc(sizeof(t_u32) * 3);
	out[X] = (t_u32)strtoul(&line[p->i], &endptr, 10);
	if (*endptr == ',')
		out[Y] = (t_u32)strtoul(endptr + 1, &endptr, 10);
	else
		error_parse("RGB Configuration ( ',' Between Values )", p);
	if (*endptr == ',')
		out[Z] = (t_u32)strtoul(endptr + 1, &endptr, 10);
	else
		error_parse("RGB Configuration ( ',' Between Values )", p);
	p->i = endptr - line;
	while (i < 3)
	{
		if (out[i] < 0 || out[i] > 255)
			error_parse("RGB Value Range ( 0 - 255 )", p);
		i++;
	}
	return (out);
}
