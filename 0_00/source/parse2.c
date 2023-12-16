/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:55:58 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 08:29:30 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

void	parse_line(char *line, t_program *program, int object)
{
	if (object == EMPTY_LINE)
		return ;
	if (object == AMBIENT)
		parse_ambient(line, program);
	if (object == LIGHT)
		parse_light(line, program);
	if (object == CAMERA)
		parse_camera(line, program);
	if (object == SPHERE)
		parse_sphere(line, program);
	if (object == CYLINDER)
		parse_cylinder(line, program);
	if (object == PLANE)
		parse_plane(line, program);
}

void	parse_plane(char *line, t_program *program)
{
	program->i = 1;
	program->plane[program->no_planes]->coord = load_coordinates(line, program);
	program->plane[program->no_planes]->normal_vector = load_normal_vector(line, program);
	program->plane[program->no_planes]->rgb = load_rgb_values(line, program);
	program->no_planes++;
}

void	parse_cylinder(char *line, t_program *program)
{
	program->i = 1;
	program->cylinder[program->no_cylinders]->coord = load_coordinates(line, program);
	program->cylinder[program->no_cylinders]->normal_vector = load_normal_vector(line, program);
	program->cylinder[program->no_cylinders]->diam = load_dimension(line, program);
	program->cylinder[program->no_cylinders]->height = load_dimension(line, program);
	program->cylinder[program->no_cylinders]->rgb = load_rgb_values(line, program);
	program->no_cylinders++;	
}

void	parse_sphere(char *line, t_program *program)
{
	program->i = 1;
	program->sphere[program->no_spheres]->coord = load_coordinates(line, program);
	program->sphere[program->no_spheres]->diam = load_dimension(line, program);
	program->sphere[program->no_spheres]->rgb = load_rgb_values(line, program);
	program->no_spheres++;		
}

void	parse_camera(char *line, t_program *program)
{
	program->i = 1;
	if (program->no_camera > 1)
		error_parse("Too Many Cameras Detected!");
	program->camera->coord = load_coordinates(line, program);
	program->camera->normal_vector = load_normal_vector(line, program);
	program->camera->fov = load_dimension(line, program);		
}
