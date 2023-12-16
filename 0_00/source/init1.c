/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:57:39 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/15 13:00:58 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt_functions.h"

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
	program->camera->fov = 0;
	program->light->brightness = 0;
	program->amb_light->brightness = 0;
	program->no_cylinders = 0;
	program->no_planes = 0;
	program->no_spheres = 0;
	ft_bzero(program->camera->coord, 3);
	ft_bzero(program->camera->normal_vector, 3);
	ft_bzero(program->light->coord, 3);
	ft_bzero(program->amb_light->rgb, 3);
}
