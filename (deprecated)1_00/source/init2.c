/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 10:07:12 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 10:23:36 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	init_plane(t_program *program)
{
	program->plane[program->no_planes] = malloc(sizeof(t_plane));
	program->plane[program->no_planes]->coord = NULL;
	program->plane[program->no_planes]->normal_vector = NULL;
	program->plane[program->no_planes]->rgb = NULL;
	program->no_planes++;
}

void	init_cylinder(t_program *program)
{
	program->cylinder[program->no_cylinders] = malloc(sizeof(t_cylinder));
	program->cylinder[program->no_cylinders]->coord = NULL;
	program->cylinder[program->no_cylinders]->normal_vector = NULL;
	program->cylinder[program->no_cylinders]->rgb = NULL;
	program->cylinder[program->no_cylinders]->diam = -1;
	program->cylinder[program->no_cylinders]->height = -1;
	program->no_cylinders++;
}

void	init_sphere(t_program *program)
{
	program->sphere[program->no_spheres] = malloc(sizeof(t_sphere));
	program->sphere[program->no_spheres]->coord = NULL;
	program->sphere[program->no_spheres]->rgb = NULL;
	program->sphere[program->no_spheres]->diam = -1;
	program->no_spheres++;
}