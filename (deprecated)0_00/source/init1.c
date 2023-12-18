/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:57:39 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 08:05:05 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	program_init(t_program *program, char *filename)
{
	program->scene_fd = open(filename, O_RDONLY);
	if (program->scene_fd == -1)
		error_parse("Scene File Descriptor Not Assigned!");
	struct_malloc(program);
	init_env(program);
}

void	struct_malloc(t_program *program)
{
	program->camera = malloc(sizeof(t_camera));
	program->amb_light = malloc(sizeof(t_amb_light));
	program->light = malloc(sizeof(t_light));
	program->sphere = malloc(sizeof(t_sphere *) * 32);
	program->cylinder = malloc(sizeof(t_cylinder *) * 32);
	program->plane = malloc(sizeof(t_plane *) * 32);
}

void	init_env(t_program *program)
{
	program->camera->fov = -1;
	program->light->brightness = -1;
	program->amb_light->brightness = -1;
	program->no_cylinders = 0;
	program->no_planes = 0;
	program->no_spheres = 0;
	program->no_amb_light = 0;
	program->no_camera = 0;
	program->no_light = 0;
}
