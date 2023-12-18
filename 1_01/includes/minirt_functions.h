/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:35:03 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 12:22:57 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FUNCTIONS_H
# define MINIRT_FUNCTIONS_H

/// ERROR1_C ///
void	error_parse(char *mess, t_program *p);
void	rt_objects_check(t_program *program);

/// EXIT1_C ///
void	exit_program(t_program *program);

/// FREE1_C ///
void	free_program(t_program *program);
void	free_cylinders(t_program *program);
void	free_planes(t_program *program);
void	free_spheres(t_program *program);

/// FREE2_C ///
void	free_camera(t_program *program);
void	free_light(t_program *program);
void	free_amb_light(t_program *program);

/// INIT1_C ///
void	program_init(t_program *program, char *filename);
void	struct_malloc(t_program *program);
void	init_env(t_program *program);
void	init_line(char *line, t_program *program);
void	terminate_scene_object_structs(t_program *program);

/// INIT2_C ///
void	init_plane(t_program *program);
void	init_cylinder(t_program *program);
void	init_sphere(t_program *program);

/// INIT3_C ///
void	init_camera(t_program *program);
void	init_light(t_program *program);
void	init_amb_light(t_program *program);

/// INIT4_C ///
void	view_init(t_program *program);

/// KEYPRESS1_C ///
int		keypress(int keycode, void *param);

/// PARSE1_C ///
int		rt_object(char *line, t_program *program);
int		scene_object(char *line, t_program *program);
int		object_present_in_file(char *line, t_program *program);
int		check_line(char *line, t_program *program);
void	check_parse_identifiers(t_program *program);

/// PARSE2_C ///
void	parse_line(char *line, t_program *program, int object);
void	parse_plane(char *line, t_program *program);
void	parse_cylinder(char *line, t_program *program);
void	parse_sphere(char *line, t_program *program);


/// PARSE3_C ///
void	parse_light(char *line, t_program *program);
void	parse_amb_light(char *line, t_program *program);
void	parse_camera(char *line, t_program *program);

/// PARSE4_C ///
float	load_brightness_ratio(char *line, t_program *program);
float	*load_normal_vector(char *line, t_program *program);
float	load_dimension(char *line, t_program *program);
float	*load_coordinates(char *line, t_program *program);
t_u32	*load_rgb_values(char *line, t_program *program);

/// SCENE1_C ///
void	scene(t_program *program);
int		render_scene(void *param);

/// WINDOW1_C ///
void	*create_window(char *title, t_program *program);


void draw_circle(t_program *program, int center_x, int center_y, int radius);
#endif