/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:35:03 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 08:03:44 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FUNCTIONS_H
# define MINIRT_FUNCTIONS_H

/// ERROR1_C ///
void	error_parse(char *mess);

/// INIT1_C ///
void	program_init(t_program *program, char *filename);
void	struct_malloc(t_program *program);
void	init_env(t_program *program);

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
void	parse_camera(char *line, t_program *program);

/// PARSE3_C ///
void	parse_light(char *line, t_program *program);
void	parse_ambient(char *line, t_program *program);

/// PARSE4_C ///
float	load_brightness_ratio(char *line, t_program *program);
float	*load_normal_vector(char *line, t_program *program);
float	load_dimension(char *line, t_program *program);
float	*load_coordinates(char *line, t_program *program);
t_u32	*load_rgb_values(char *line, t_program *program);

/// PRINT1_C ///
void	print_parameters(t_program *program);

#endif