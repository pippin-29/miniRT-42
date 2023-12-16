/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 05:46:14 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 07:22:48 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	print_parameters(t_program *program)
{
	t_u32 pl;
	t_u32 sp;
	t_u32 cy;

	pl = 0;
	sp = 0;
	cy = 0;
	printf("id			coordinates			normal_vector	fov		diam	height		brightness		rgb\n");
	printf(" A																			%f				%u,%u,%u\n", program->amb_light->brightness, program->amb_light->rgb[R], program->amb_light->rgb[G], program->amb_light->rgb[B]);
	printf(" C			%f,%f,%f			%f,%f,%f		%f\n", program->camera->coord[X], program->camera->coord[Y], program->camera->coord[Z], program->camera->normal_vector[X], program->camera->normal_vector[Y], program->camera->normal_vector[Z], program->camera->fov);
	printf(" L			%f,%f,%f														%f\n", program->light->coord[X], program->light->coord[Y], program->light->coord[Z], program->light->brightness);
	while (pl < program->no_planes)
	{
		printf(" pl			%f,%f,%f			%f,%f,%f													%u,%u,%u\n", program->plane[pl]->coord[X], program->plane[pl]->coord[Z], program->plane[pl]->coord[Y], program->plane[pl]->normal_vector[X], program->plane[pl]->normal_vector[Y], program->plane[pl]->normal_vector[Z], program->plane[pl]->rgb[R], program->plane[pl]->rgb[G], program->plane[pl]->rgb[B]);
		pl++;
	}
	while (sp < program->no_spheres)
	{
		printf(" sp			%f,%f,%f									%f									%u,%u,%u\n", program->sphere[sp]->coord[X], program->sphere[sp]->coord[Y], program->sphere[sp]->coord[Z], program->sphere[sp]->diam, program->sphere[sp]->rgb[R], program->sphere[sp]->rgb[G], program->sphere[sp]->rgb[B]);
		sp++;
	}
	while (cy < program->no_cylinders)
	{
		printf(" cy			%f,%f,%f			%f,%f,%f				%f		%f							%u,%u,%u\n", program->cylinder[cy]->coord[X], program->cylinder[cy]->coord[Y], program->cylinder[cy]->coord[Z], program->cylinder[cy]->normal_vector[X], program->cylinder[cy]->normal_vector[Y], program->cylinder[cy]->normal_vector[Z], program->cylinder[cy]->diam, program->cylinder[cy]->diam, program->cylinder[cy]->rgb[R], program->cylinder[cy]->rgb[G], program->cylinder[cy]->rgb[B]);
		cy++;
	}
}