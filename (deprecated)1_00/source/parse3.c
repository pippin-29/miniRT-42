/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:27:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 10:37:43 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_light(char *line, t_program *program)
{
	program->no_light++;
	if (program->no_light > 1)
		error_parse("Too Many Lights Detected!", program);
	program->light->coord = load_coordinates(line, program);
	program->light->brightness = load_brightness_ratio(line, program);
	
}

void	parse_amb_light(char *line, t_program *program)
{
	program->no_amb_light++;
	if (program->no_amb_light > 1)
		error_parse("Too Many Ambients Detected!", program);
	program->amb_light->brightness = load_brightness_ratio(line, program);
	program->amb_light->rgb = load_rgb_values(line, program);
	
}

void	parse_camera(char *line, t_program *program)
{
	program->no_camera++;	
	if (program->no_camera > 1)
		error_parse("Too Many Cameras Detected!", program);
	program->camera->coord = load_coordinates(line, program);
	program->camera->normal_vector = load_normal_vector(line, program);
	program->camera->fov = load_dimension(line, program);
}



