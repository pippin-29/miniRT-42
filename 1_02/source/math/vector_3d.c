/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_3d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 09:57:23 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/19 10:43:14 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_f32 *assign_vec_x_3d(t_v8)
{
	t_f32 *vx;

	vx = malloc(sizeof(t_f32) * 3);
	vx[X] = sqrtf(3) / 2;
	vx[Y] = -1 / 2;
	vx[Z] = -1 / sqrtf(2) / 2;
	return (vx);
}
t_f32 *assign_vec_y_3d(t_v8)
{
	t_f32 *vy;
	
	vy = malloc(sizeof(t_f32) * 3);
	vy[X] = -sqrtf(3) / 2;
	vy[Y] = -1 / 2;
	vy[Z] = -1 / sqrtf(2) / 2;
	return (vy); 
}
t_f32 *assign_vec_z_3d(t_v8)
{
	t_f32 *vz;

	vz = malloc(sizeof(t_f32) * 3);
	vz[X] = 0;
	vz[Y] = 1 / 2;
	vz[Z] = -1 / sqrtf(2) / 2;
	return (vz);
}

