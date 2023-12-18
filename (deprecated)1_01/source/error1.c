/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 14:43:55 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 20:26:31 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/miniRT.h"

t_v8	error_parse(t_s8 *mess, t_program *program)
{
	printf("Error; Type: Parse; Explicit: %s\n", mess);
	exit_program(program, -1);
}

t_v8	rt_objects_check(t_program *program)
{
	if (program->no_camera == 0)
		error_parse("Camera Not Present", program);
	if (program->no_light == 0)
		error_parse("Light Not Present", program);
	if (program->amb_light == 0)
		error_parse("Ambient Light Not Present", program);
}
