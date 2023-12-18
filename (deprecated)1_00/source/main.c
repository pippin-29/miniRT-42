/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:34:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 09:58:29 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int argc, char **argv)
{
	t_program	*program;

	program = malloc(sizeof(t_program));
	if (argc == 2)
	{
		program_init(program, argv[1]);
		check_parse_identifiers(program);
		// print_parameters(program);
	}
	else
	{
		printf("Please Input One Parameter\n");
		printf("Usage: ./miniRT scene/scene.rt\n");
		return (1);
	}
	return (0);
}
