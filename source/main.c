/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:34:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/15 12:49:37 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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


void	check_line(char *line, t_program *program)
{
	if (object_present_in_file(line, program))
	{

	}
	else
	{
		printf("Error: Cannot parse;\n");
		exit(1);
	}
}

void	check_identifiers(t_program *program)
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

void	program_init(t_program *program, char *filename)
{
	program->scene_fd = open(filename, O_RDONLY);
	if (program->scene_fd == -1)
	{
		perror("Input Failed: ");
		exit(1);
	}
	program->camera = malloc(sizeof(t_camera));
	program->amb_light = malloc(sizeof(t_amb_light));
	program->light = malloc(sizeof(t_light));
	program->camera->fov = 0;
	program->light->brightness = 0;
	program->amb_light->brightness = 0;
	program->no_cylinders = 0;
	program->no_planes = 0;
	program->no_spheres = 0;
	ft_bzero(program->camera->coord, 3);
	ft_bzero(program->camera->normal_vector, 3);
	ft_bzero(program->light->coord, 3);
	ft_bzero(program->amb_light->rgb, 3);
	check_identifiers(program);
	parse_scene_file(program);
}

int main (int argc, char **argv)
{
	if (argc == 2)
	{
		t_program *program;

		program = malloc(sizeof(t_program));
		program_init(program, argv[1]);
	}
	else
	{
		printf("Please Input One Parameter\n");
		printf("Usage: ./miniRT scene/scene.rt\n");
		return (1);
	}
}