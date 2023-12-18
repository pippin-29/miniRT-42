/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:55:58 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:41:14 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_v8	parse_line(t_s8 *line, t_program *program, t_u16 object)
{
	if (object == EMPTY_LINE)
		return ;
	if (object == AMBIENT)
		parse_amb_light(line, program);
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

t_v8	parse_plane(t_s8 *line, t_program *program)
{
	if (program->no_planes >= 32)
		error_parse("Too Many Planes", program);
	program->plane[program->no_planes]->coord = load_coordinates(line, program);
	program->plane[program->no_planes]->normal_vector = load_normal_vector(line, program);
	program->plane[program->no_planes]->rgb = load_rgb_values(line, program);
	program->no_planes++;
}

t_v8	parse_cylinder(t_s8 *line, t_program *program)
{
	if (program->no_cylinders >= 32)
		error_parse("Too Many Cylinders", program);
	program->cylinder[program->no_cylinders]->coord = load_coordinates(line, program);
	program->cylinder[program->no_cylinders]->normal_vector = load_normal_vector(line, program);
	program->cylinder[program->no_cylinders]->diam = load_dimension(line, program);
	program->cylinder[program->no_cylinders]->height = load_dimension(line, program);
	program->cylinder[program->no_cylinders]->rgb = load_rgb_values(line, program);
	program->no_cylinders++;	
}

t_v8	parse_sphere(t_s8 *line, t_program *program)
{
	if (program->no_spheres >= 32)
		error_parse("Too Many Spheres", program); 
	program->sphere[program->no_spheres]->coord = load_coordinates(line, program);
	program->sphere[program->no_spheres]->diam = load_dimension(line, program);
	program->sphere[program->no_spheres]->rgb = load_rgb_values(line, program);
	program->no_spheres++;		
}


