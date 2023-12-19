/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:28:58 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/19 10:43:32 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8	view_init(t_program *program)
{
	program->view = malloc(sizeof(t_mlx));
	program->view->resolution[X] = 1024;
	program->view->resolution[Y] = 1024;
	program->view->origin[X] = 512;
	program->view->origin[Y] = 512;
	program->view->vec_3d = malloc(sizeof(t_f32) * 3);
	program->view->vec_3d[X] = assign_vec_x_3d();
	program->view->vec_3d[Y] = assign_vec_y_3d();
	program->view->vec_3d[Z] = assign_vec_z_3d();
	program->view->vec_2d = malloc(sizeof(t_f32) * 3);
	program->view->vec_2d[X] = assign_vec_x_2d(program);
	program->view->vec_2d[Y] = assign_vec_y_2d(program);
	program->view->vec_2d[Z] = assign_vec_z_2d(program);
	program->view->mlx = mlx_init();
	program->view->window = NULL;
}
