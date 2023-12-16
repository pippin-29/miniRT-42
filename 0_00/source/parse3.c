/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:27:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 08:30:00 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_light(char *line, t_program *program)
{
	program->i = 1;
	if (program->no_camera > 1)
		error_parse("Too Many Lights Detected!");
	program->light->coord = load_coordinates(line, program);
	program->light->brightness = load_brightness_ratio(line, program);
}

void	parse_ambient(char *line, t_program *program)
{
	program->i = 1;
	if (program->no_camera > 1)
		error_parse("Too Many Ambients Detected!");
	program->amb_light->brightness = load_brightness_ratio(line, program);
	program->amb_light->rgb = load_rgb_values(line, program);
}



