/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:27:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/27 08:49:33 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8	parse_light(t_s8 *line, t_program *program)
{
	program->no_light++;
	if (program->no_light > 1)
		error_parse("Too Many Lights Detected!", program);
	program->light->coord = load_coordinates(line, program);
	program->light->brightness = load_brightness_ratio(line, program);
}

t_v8	parse_amb_light(t_s8 *line, t_program *program)
{
	program->no_amb_light++;
	if (program->no_amb_light > 1)
		error_parse("Too Many Ambients Detected!", program);
	program->amb_light->brightness = load_brightness_ratio(line, program);
	program->amb_light->rgb = load_rgb_values(line, program);
}

t_v8	parse_camera(t_s8 *line, t_program *program)
{
	program->no_camera++;
	if (program->no_camera > 1)
		error_parse("Too Many Cameras Detected!", program);
	program->camera->coord = load_coordinates(line, program);
	program->camera->normal_vector[X] = load_normal_vector(line, program);
	program->camera->normal_vector[Y] = load_normal_vector(line, program);
	program->camera->normal_vector[Z] = load_normal_vector(line, program);
	program->camera->fov = load_dimension(line, program);
}

t_v8	check_normal_vector(t_f32 *n_vec, t_program *program)
{
	t_f32	length;
	t_f32	sum;

	sum = (n_vec[0] * n_vec[0]) + (n_vec[1] * n_vec[1]) + (n_vec[2] * n_vec[2]);
	length = sqrtf(sum);
	if (length != 1)
		error_parse("Vector Length Not Normalized", program);
}
