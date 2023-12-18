/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:24:16 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 10:32:27 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	init_amb_light(t_program *program)
{

	program->amb_light = malloc(sizeof(t_amb_light));
	program->amb_light->brightness = -1;
	program->amb_light->rgb = NULL;
}

void	init_light(t_program *program)
{

	program->light = malloc(sizeof(t_light));
	program->light->brightness = -1;
	program->light->coord = NULL;
}

void	init_camera(t_program *program)
{
	program->camera = malloc(sizeof(t_camera));
	program->camera->fov = -1;
	program->camera->coord = NULL;
	program->camera->normal_vector = NULL;
}

		
	
	
	
	