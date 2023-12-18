/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:35:03 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:43:20 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FUNCTIONS_H
# define MINIRT_FUNCTIONS_H

/// ERROR1_C ///
t_v8	error_parse(t_s8 *mess, t_program *p);
t_v8	rt_objects_check(t_program *program);

/// EXIT1_C ///
t_v8	exit_program(t_program *program);

/// FREE1_C ///
t_v8	free_program(t_program *program);
t_v8	free_cylinders(t_program *program);
t_v8	free_planes(t_program *program);
t_v8	free_spheres(t_program *program);

/// FREE2_C ///
t_v8	free_camera(t_program *program);
t_v8	free_light(t_program *program);
t_v8	free_amb_light(t_program *program);

/// INIT1_C ///
t_v8	program_init(t_program *program, t_s8 *filename);
t_v8	struct_malloc(t_program *program);
t_v8	init_env(t_program *program);
t_v8	init_line(t_s8 *line, t_program *program);
t_v8	terminate_scene_object_structs(t_program *program);

/// INIT2_C ///
t_v8	init_plane(t_program *program);
t_v8	init_cylinder(t_program *program);
t_v8	init_sphere(t_program *program);

/// INIT3_C ///
t_v8	init_camera(t_program *program);
t_v8	init_light(t_program *program);
t_v8	init_amb_light(t_program *program);

/// INIT4_C ///
t_v8	view_init(t_program *program);

/// KEYPRESS1_C ///
t_s32	keypress(int keycode, t_v8 *param);

/// PARSE1_C ///
t_u16	rt_object(t_s8 *line, t_program *program);
t_u16	scene_object(t_s8 *line, t_program *program);
t_u16	object_present_in_file(t_s8 *line, t_program *program);
t_u16	check_line(t_s8 *line, t_program *program);
t_v8	check_parse_identifiers(t_program *program);

/// PARSE2_C ///
t_v8	parse_line(t_s8 *line, t_program *program, t_u16 object);
t_v8	parse_plane(t_s8 *line, t_program *program);
t_v8	parse_cylinder(t_s8 *line, t_program *program);
t_v8	parse_sphere(t_s8 *line, t_program *program);


/// PARSE3_C ///
t_v8	parse_light(t_s8 *line, t_program *program);
t_v8	parse_amb_light(t_s8 *line, t_program *program);
t_v8	parse_camera(t_s8 *line, t_program *program);

/// PARSE4_C ///
t_f32	load_brightness_ratio(t_s8 *line, t_program *program);
t_f32	*load_normal_vector(t_s8 *line, t_program *program);
t_f32	load_dimension(t_s8 *line, t_program *program);
t_f32	*load_coordinates(t_s8 *line, t_program *program);
t_u16	*load_rgb_values(t_s8 *line, t_program *program);

/// SCENE1_C ///
t_v8	scene(t_program *program);
t_s32	render_scene(t_v8 *param);

/// WINDOW1_C ///
t_v8	*create_window(t_s8 *title, t_program *program);

#endif