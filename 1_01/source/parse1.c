/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:25:38 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:16:47 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_u16	rt_object(t_s8 *line, t_program *program)
{
	t_u16	i;

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

t_u16	scene_object(t_s8 *line, t_program *program)
{
 	t_u16	i;

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


t_u16	object_present_in_file(t_s8 *line, t_program *program)
{
	t_u16 ret;

	ret = 0;
	ret = scene_object(line, program);
	if (ret)
		return (ret);
	else
		ret = rt_object(line, program);
	return (ret);
}

t_u16	check_line(t_s8 *line, t_program *program)
{
	t_u16 object;

	object = object_present_in_file(line, program);
	if (object)
	{
		parse_line(line, program, object);
		return (1);
	}
	return (0);
		
}



t_v32	check_parse_identifiers(t_program *program)
{
	t_s8 *line;

	line = get_next_line(program->scene_fd);
	while (line)
	{
		init_line(line, program);
		
		line = get_next_line(program->scene_fd);
	}
	lseek(program->scene_fd, SEEK_CUR, 0);
	init_env(program);
	line = get_next_line(program->scene_fd);
	while (line)
	{
		if (!check_line(line, program))
			error_parse("Line Invalid", program);

		line = get_next_line(program->scene_fd);

	}
	terminate_scene_object_structs(program);
	rt_objects_check(program);
}