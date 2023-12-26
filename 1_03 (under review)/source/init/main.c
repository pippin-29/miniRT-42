/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:34:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/19 05:17:16 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_s32	main(t_s32 argc, t_s8 **argv)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (argc == 2)
	{
		program_init(program, argv[1]);
		check_parse_identifiers(program);
		scene(program);
	}
	else
	{
		printf("Please Input One Parameter\n");
		printf("Usage: ./miniRT scene/scene.rt\n");
		free(program);
		exit(1);
	}
	exit_program(program, SUCCESS);
}
