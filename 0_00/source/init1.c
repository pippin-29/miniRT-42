/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:57:39 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 06:26:02 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	program_init(t_program *program, char *filename)
{
	program->scene_fd = open(filename, O_RDONLY);
	if (program->scene_fd == -1)
	{
		perror("Input Failed: ");
		exit(1);
	}
	program->camera = malloc(sizeof(t_camera));
	program->amb_light = malloc(sizeof(t_amb_light));
	program->light = malloc(sizeof(t_light));
	program->camera->fov = -1;
	program->light->brightness = -1;
	program->amb_light->brightness = -1;
	program->no_cylinders = 0;
	program->no_planes = 0;
	program->no_spheres = 0;
}
