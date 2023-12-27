/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:54:02 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/20 15:26:00 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

/// map_x and map_y transform local(camera) coordinates(3d) to raster space (2d)

t_u16 map_x(t_f32 x, t_f32 z, t_program *program)
{
	program->space->screen[X] = x / z;
	program->space->ndc[X]
		= (program->space->screen[X] + (program->view->resolution[X] / 2))
			/ program->view->resolution[X];
	program->space->raster[X] = floorf(program->space->ndc[X] * program->view->resolution[X]);
	return(program->space->raster[X]);
}

t_u16 map_y(t_f32 y, t_f32 z, t_program *program)
{
	program->space->screen[Y] = y / z;
	program->space->ndc[Y]
		= (program->space->screen[Y] + (program->view->resolution[Y] / 2))
			/ program->view->resolution[Y];
	program->space->raster[Y] = floorf(program->space->ndc[Y] * program->view->resolution[Y]);
	return(program->space->raster[Y]);
}
