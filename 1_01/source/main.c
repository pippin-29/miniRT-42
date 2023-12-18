/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:34:51 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:36:49 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_s32	main(t_s32 argc, t_s8 **argv)
{
	t_program	*program;
	printf("%lu\n",sizeof(t_f32));
	printf("%lu\n",sizeof(t_u16));
	printf("%lu\n",sizeof(t_u32));
	printf("%lu\n",sizeof(t_s64));
	printf("%lu\n",sizeof(t_s32));
	printf("%lu\n",sizeof(t_s8));
	printf("%lu\n",sizeof(t_v8));
	printf("%lu\n",sizeof(t_f64));
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
		return (1);
	}
	return (0);
}
