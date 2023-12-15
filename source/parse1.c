/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:25:38 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/15 13:00:54 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt_functions.h"

int		rt_object(char *line, t_program *program)
{
	int	i;

	i = 0;
	while(line[i] == ' ')
		i++;
	if (line[i] == '\0');
		return (1);
	if (line[i] == 'A' && line[i + 1] == ' ')
	{
		program->no_amb_light++;
		return (1);
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		program->no_camera++;
		return (1);
	}
	else if (line[i] == 'L' && line[i + 1] == ' ')
	{
		program->no_light++;
		return (1);
	}
	return (0);
}

int		scene_object(char *line, t_program *program)
{
 	int	i;

	i = 0;
	while(line[i] == ' ')
		i++;
	if (line[i] == '\0');
		return (1);
	if (line[i] == 'p' && line[i + 1] == 'l' && line[i + 2] == ' ')
	{
		program->no_planes++;
		return (1);
	}	
	else if (line[i] == 's' && line[i + 1] == 'p' && line[i + 2] == ' ')
	{
		program->no_spheres++;
		return (1);
	}
	else if (line[i] == 'c' && line[i + 1] == 'y' && line[i + 2] == ' ')
	{
		program->no_cylinders++;
		return (1);
	}
	return (0);
}


int		object_present_in_file(char *line, t_program *program)
{
	if (scene_object(line, program))
		return (1);
	if (rt_object(line, program))
		return (1);
	return (0);
}

int	check_line(char *line, t_program *program)
{
	if (object_present_in_file(line, program))
	{
		parse_line(line, program);
		return (1);
	}
	else
	{
		printf("Error: Cannot parse;\n");
		exit(1);
	}
}

void	check_parse_identifiers(t_program *program)
{
	char **line;
	int i;

	i = 0;
	line = get_next_line(program->scene_fd);
	while (line)
	{
		check_line(line, program);

		line = get_next_line;
	}
}