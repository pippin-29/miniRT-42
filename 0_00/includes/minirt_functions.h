/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:35:03 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 05:41:09 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FUNCTIONS_H
# define MINIRT_FUNCTIONS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <string.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "minirt_macro.h"
# include "minirt_types.h"

/// ERROR1_C ///
void	error_parse(char *mess);

/// INIT1_C ///
void	program_init(t_program *program, char *filename);

/// PARSE1_C ///
int		rt_object(char *line, t_program *program);
int		scene_object(char *line, t_program *program);
int		object_present_in_file(char *line, t_program *program);
void	check_line(char *line, t_program *program);
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

#endif