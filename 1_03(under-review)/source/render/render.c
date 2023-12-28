/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:53:38 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/29 08:14:49 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8	scene(t_program *program)
{
	program->view->window = create_window("Sig's Ray Tracing Engine", program);
	mlx_hook(program->view->window, 2, 1L << 0, keypress, program);
	mlx_loop_hook(program->view->mlx, render_scene, program);
	mlx_loop(program->view->mlx);
}


t_s32	render_scene(t_v8 *param)
{
	t_program	*program;

	program = (t_program *)param;
	
	return (0);
}
