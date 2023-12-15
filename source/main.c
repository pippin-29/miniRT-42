/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:34:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/15 12:29:32 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

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