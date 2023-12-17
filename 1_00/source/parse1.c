/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:25:38 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 08:21:55 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int		rt_object(char *line, t_program *program)
{
	int	i;

	i = 0;
	while(line[i] == ' ')
		i++;
	program->i = i + 1;
	if (ft_strncmp(&line[i], "A", 1) == 0)
		return (AMBIENT);
	else if (ft_strncmp(&line[i], "C", 1) == 0)
		return (CAMERA);
	else if (ft_strncmp(&line[i], "L", 1) == 0)
		return (LIGHT);
	return (0);
}

int		scene_object(char *line, t_program *program)
{
 	int	i;

	i = 0;
	while(line[i] == ' ')
		i++;
	program->i = i + 2;
	if (line[i] == '\n')
		return (EMPTY_LINE);
	if (ft_strncmp(&line[i], "pl", 2) == 0)
		return (PLANE);
	else if (ft_strncmp(&line[i], "sp", 2) == 0)
		return (SPHERE);
	else if (ft_strncmp(&line[i], "cy", 2) == 0)
		return (CYLINDER);
	return (0);
}


int		object_present_in_file(char *line, t_program *program)
{
	int ret;

	ret = 0;
	ret = scene_object(line, program);
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