/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:28:58 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/20 14:41:22 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8	view_init(t_program *program)
{
	program->view = malloc(sizeof(t_mlx));
	program->view->resolution[X] = 1024;
	program->view->resolution[Y] = 1024;
	program->view->mlx = mlx_init();
	program->view->window = NULL;
}

// t_v8	assign_translation(t_program *program)
// {
// 	program->world->world_to_cam[0][0] = 1;
// 	program->world->world_to_cam[0][1] = 0;
// 	program->world->world_to_cam[0][2] = 0;
// 	program->world->world_to_cam[0][3] = -(program->camera->coord[X]);
// 	program->world->world_to_cam[1][0] = 0;
// 	program->world->world_to_cam[1][1] = 1;
// 	program->world->world_to_cam[1][2] = 0;
// 	program->world->world_to_cam[1][3] = -(program->camera->coord[Y]);
// 	program->world->world_to_cam[2][0] = 0;
// 	program->world->world_to_cam[2][1] = 0;
// 	program->world->world_to_cam[2][2] = 1;
// 	program->world->world_to_cam[2][3] = -(program->camera->coord[Z]);
// 	program->world->world_to_cam[3][0] = 0;
// 	program->world->world_to_cam[3][1] = 0;
// 	program->world->world_to_cam[3][2] = 0;
// 	program->world->world_to_cam[3][3] = 1;
// }
