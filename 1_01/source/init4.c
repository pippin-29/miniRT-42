/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:28:58 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:40:33 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_v8	view_init(t_program *program)
{
	program->view = malloc(sizeof(t_mlx));
	program->view->resolution[X] = 1024;
	program->view->resolution[Y] = 768;
	program->view->mlx = mlx_init();
	program->view->window = NULL;
}
