/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:57:39 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 20:26:57 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_v8	program_init(t_program *program, t_s8 *filename)
{
	program->scene_fd = open(filename, O_RDONLY);
	if (program->scene_fd == -1)
		error_parse("Scene File Descriptor Not Assigned!", program);
	struct_malloc(program);
	init_env(program);
	view_init(program);
}

t_v8	struct_malloc(t_program *program)
{
	program->sphere = malloc(sizeof(t_sphere *) * 32);
	program->cylinder = malloc(sizeof(t_cylinder *) * 32);
	program->plane = malloc(sizeof(t_plane *) * 32);
}

t_v8	init_env(t_program *program)
{
	program->no_cylinders = 0;
	program->no_planes = 0;
	program->no_spheres = 0;
	program->no_amb_light = 0;
	program->no_camera = 0;
	program->no_light = 0;
}

t_v8	init_line(t_s8 *line, t_program *program)
{
	t_s32	object;

	object = object_present_in_file(line, program);
	if (object == AMBIENT)
		init_amb_light(program);
	else if (object == LIGHT)
		init_light(program);
	else if (object == CAMERA)
		init_camera(program);
	else if (object == SPHERE)
		init_sphere(program);
	else if (object == CYLINDER)
		init_cylinder(program);
	else if (object == PLANE)
		init_plane(program);
}

t_v8	terminate_scene_object_structs(t_program *program)
{
	t_s32	sp;
	t_s32	pl;
	t_s32	cy;

	sp = program->no_spheres;
	pl = program->no_planes;
	cy = program->no_cylinders;
	while (sp < 32)
		program->sphere[sp++] = NULL;
	while (pl < 32)
		program->plane[pl++] = NULL;
	while (cy < 32)
		program->cylinder[cy++] = NULL;
}
