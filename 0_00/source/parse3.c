/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 13:27:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 06:18:50 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_light(char *line, t_program *program)
{
	int	i;

	i = 0;
	if (program->no_camera > 1)
		error_parse("Too Many Lights Detected!");
	while (line[i] == ' ')
		i++;
	program->light->coord = load_coordinates(&line[i], program);
	while (line[i] == ' ')
		i++;
	program->light->brightness = load_brightness_ratio(&line[i], program);
}

void	parse_ambient(char *line, t_program *program)
{
	int	i;

	i = 0;
	if (program->no_camera > 1)
		error_parse("Too Many Ambients Detected!");
	while (line[i] == ' ')
		i++;
	program->amb_light->brightness = load_brightness_ratio(&line[i], program);
	while (line[i] == ' ')
		i++;
	program->amb_light->rgb = load_rgb_values(&line[i], program);
}



