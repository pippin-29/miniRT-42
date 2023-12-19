/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_translation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:14:45 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/19 10:40:15 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_f32 *assign_vec_x_2d(t_program *program)
{
	t_f32 *vx;

	vx = malloc(sizeof(t_f32) * 2);
	vx[X] = (program->view->vec_3d[X][X] - program->view->vec_3d[X][Z]) / sqrtf(2);
	vx[Y] = (program->view->vec_3d[X][X] + (2 * program->view->vec_3d[X][Y])
		+ program->view->vec_3d[X][Z]) / sqrtf(6);
	return (vx);
}

t_f32 *assign_vec_y_2d(t_program *program)
{
	t_f32 *vy;

	vy = malloc(sizeof(t_f32) * 2);
	vy[X] = (program->view->vec_3d[Y][X] - program->view->vec_3d[Y][Z]) / sqrtf(2);
	vy[Y] = (program->view->vec_3d[Y][X] + (2 * program->view->vec_3d[Y][Y])
		+ program->view->vec_3d[Y][Z]) / sqrtf(6);
	return (vy); 
}

t_f32 *assign_vec_z_2d(t_program *program)
{
	t_f32 *vz;

	vz = malloc(sizeof(t_f32) * 2);
	vz[X] = (program->view->vec_3d[Z][X] - program->view->vec_3d[Z][Z]) / sqrtf(2);
	vz[Y] = (program->view->vec_3d[Z][X] + (2 * program->view->vec_3d[Z][Y])
		+ program->view->vec_3d[Z][Z]) / sqrtf(6);
	return (vz);
}