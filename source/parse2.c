/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 12:55:58 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/15 18:00:46 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt_functions.h"

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

}

void	parse_cylinder(char *line, t_program *program)
{
	
}

void	parse_sphere(char *line, t_program *program)
{
	
}

void	parse_camera(char *line, t_program *program)
{
	
}
