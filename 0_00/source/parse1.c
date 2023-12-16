/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:25:38 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 07:40:48 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		rt_object(char *line, t_program *program)
{
	int	i;

	i = 0;
	while(line[i] == ' ')
		i++;
	printf("i = %d char = %c\n", i, line[i]);
	if (ft_strcmp(&line[i], "A "))
	{
		program->no_amb_light++;
		return (AMBIENT);
	}
	else if (line[i] == 'C' && line[i + 1] == ' ')
	{
		program->no_camera++;
		return (CAMERA);
	}
	else if (line[i] == 'L' && line[i + 1] == ' ')
	{
		program->no_light++;
		return (LIGHT);
	}
	return (0);
}

int		scene_object(char *line)
{
 	int	i;

	i = 0;
	while(line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (EMPTY_LINE);
	if (line[i] == 'p' && line[i + 1] == 'l' && line[i + 2] == ' ')
		return (PLANE);
	else if (line[i] == 's' && line[i + 1] == 'p' && line[i + 2] == ' ')
		return (SPHERE);
	else if (line[i] == 'c' && line[i + 1] == 'y' && line[i + 2] == ' ')
		return (CYLINDER);
	return (0);
}


int		object_present_in_file(char *line, t_program *program)
{
	int ret;

	ret = 0;
	ret = scene_object(line);
	printf("%d\n", ret);
	if (ret)
		return (ret);
	else
		ret = rt_object(line, program);	
	return (ret);
}

int	check_line(char *line, t_program *program)
{
	int object;

	object = object_present_in_file(line, program);
	if (object)
	{
		parse_line(line, program, object);
		return (1);
	}
	return (0);
		
}

void	check_parse_identifiers(t_program *program)
{
	char *line;

	line = get_next_line(program->scene_fd);
	while (line)
	{
		if (!check_line(line, program))
		error_parse("Line Invalid");

		line = get_next_line(program->scene_fd);
	}
}