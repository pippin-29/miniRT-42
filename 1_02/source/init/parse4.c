/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:43:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/19 05:17:34 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_f32	load_brightness_ratio(t_s8 *line, t_program *p)
{
	t_f32	out;
	t_s8	*endptr;

	out = strtof(&line[p->i], &endptr);
	if (out < 0.0 || out > 1.0)
		error_parse("Brightness Ratio Range ( 0.0 - 1.0 )", p);
	p->i = endptr - line;
	return (out);
}

t_f32	*load_normal_vector(t_s8 *line, t_program *p)
{
	t_f32	*out;
	t_s8	*endptr;
	t_u16	i;

	i = 0;
	out = malloc(sizeof(t_f32) * 3);
	out[X] = strtof(&line[p->i], &endptr);
	if (*endptr == ',')
		out[Y] = strtof(endptr + 1, &endptr);
	else
		error_parse("Normalized Vector Configuration ( ',' Between Values )",
			p);
	if (*endptr == ',')
		out[Z] = strtof(endptr + 1, &endptr);
	else
		error_parse("Normalized Vector Configuration ( ',' Between Values )",
			p);
	p->i = endptr - line;
	while (i < 3)
	{
		if (out[i] < 0.0 || out[i] > 1.0)
			error_parse("Normalized Vector Range ( 0.0 - 1.0 )", p);
		i++;
	}
	return (out);
}

t_f32	load_dimension(t_s8 *line, t_program *p)
{
	t_f32	out;
	t_s8	*endptr;

	out = strtof(&line[p->i], &endptr);
	if (out < 0)
		error_parse("Dimensions Must Be Positive!", p);
	p->i = endptr - line;
	return (out);
}

t_f32	*load_coordinates(t_s8 *line, t_program *p)
{
	t_f32	*out;
	t_s8	*endptr;

	out = malloc(sizeof(t_f32) * 3);
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

t_u16	*load_rgb_values(t_s8 *line, t_program *p)
{
	t_u16	*out;
	t_s8	*endptr;
	t_u16	i;

	i = 0;
	out = malloc(sizeof(t_u16) * 3);
	out[X] = (t_u16)strtoul(&line[p->i], &endptr, 10);
	if (*endptr == ',')
		out[Y] = (t_u16)strtoul(endptr + 1, &endptr, 10);
	else
		error_parse("RGB Configuration ( ',' Between Values )", p);
	if (*endptr == ',')
		out[Z] = (t_u16)strtoul(endptr + 1, &endptr, 10);
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
