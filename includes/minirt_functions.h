/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_functions.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 11:35:03 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/15 13:00:31 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_FUNCTIONS_H
# define MINIRT_FUNCTIONS_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <errno.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "minirt_macro.h"
# include "minirt_types.h"

/// INIT1_C ///
void	program_init(t_program *program, char *filename);

/// PARSE1_C ///
int		rt_object(char *line, t_program *program);
int		scene_object(char *line, t_program *program);
int		object_present_in_file(char *line, t_program *program);
int		check_line(char *line, t_program *program);
void	check_parse_identifiers(t_program *program);

/// PARSE2_C ///
void	parse_line(char *line, t_program *program);

#endif