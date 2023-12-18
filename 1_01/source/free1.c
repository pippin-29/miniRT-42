/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 09:11:14 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:16:07 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_v32	free_program(t_program *program)
{
	if (program->sphere)
		free_spheres(program);
	if (program->plane)
		free_planes(program);
	if (program->cylinder)
		free_cylinders(program);
	if (program->camera)
		free_camera(program);
	if (program->light)
		free_light(program);
	if (program->amb_light)
		free_amb_light(program);
}

t_v32	free_cylinders(t_program *program)
{
	t_u16	i;

	i = 0;
	while (i < program->no_cylinders)
	{
		if (program->cylinder[i]->coord)
			free(program->cylinder[i]->coord);
		if (program->cylinder[i]->normal_vector)
			free(program->cylinder[i]->normal_vector);
		if (program->cylinder[i]->rgb)
			free(program->cylinder[i]->rgb);
		if (program->cylinder[i])
			free(program->cylinder[i]);
		i++;
	}
	free(program->cylinder);
}

t_v32	free_planes(t_program *program)
{
	t_u16	i;

	i = 0;
	while (i < program->no_planes)
	{
		if (program->plane[i]->coord)
			free(program->plane[i]->coord);
		if (program->plane[i]->normal_vector)	
			free(program->plane[i]->normal_vector);
		if (program->plane[i]->rgb)	
			free(program->plane[i]->rgb);
		if (program->plane[i])
			free(program->plane[i]);
		i++;
	}
	free(program->plane);
}

t_v32	free_spheres(t_program *program)
{
	t_u16	i;

	i = 0;
	while (i < program->no_spheres)
	{
		if (program->sphere[i]->coord)
			free(program->sphere[i]->coord);
		if (program->sphere[i]->rgb)
			free(program->sphere[i]->rgb);
		if (program->sphere[i])	
			free(program->sphere[i]);
		i++;
	}
	free(program->sphere);
}