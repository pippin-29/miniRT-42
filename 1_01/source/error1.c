/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:43:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:19:39 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_v32	error_parse(t_s8 *mess, t_program *p)
{
	printf("Error; Type: Parse; Explicit: %s\n", mess);
	free_program(p);
	exit(-1);
}

t_v32	rt_objects_check(t_program *program)
{
	if (program->no_camera == 0)
		error_parse("Camera Not Present", program);
	if (program->no_light == 0)
		error_parse("Light Not Present", program);
	if (program->amb_light == 0)
		error_parse("Ambient Light Not Present", program);
}
