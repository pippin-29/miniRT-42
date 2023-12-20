/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:29:34 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/20 15:57:26 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8	draw_pixel(t_u16 x, t_u16 y, t_program *program)
{
	mlx_pixel_put(program->view->mlx, program->view->window, x, y, 0x00FF0000);
}

t_v8	draw_sphere(t_u16 obj, t_program *program)
{
	t_f32 theta;
	t_f32 phi;
	t_f32 step;
	t_f32 coord[3];

	theta = 0;
	phi = 0;
	step = 0.1;
	while (theta <= 3.1415)
	{
		while (phi <= 2 * 3.1415)
		{
			coord[X] = (program->sphere[obj]->diam / 2) * sinf(theta)
				+ cosf(phi) + program->sphere[obj]->coord[X]; 
			coord[Y] = (program->sphere[obj]->diam / 2) * sinf(theta)
				+ sinf(phi) + program->sphere[obj]->coord[Y]; 
			coord[Z] = (program->sphere[obj]->diam / 2)
				+ cosf(phi) + program->sphere[obj]->coord[Z];
		draw_pixel(map_x(coord[X], coord[Z], program), map_y(coord[Y], coord[Z], program), program);
		}
	}
}