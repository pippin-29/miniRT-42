/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 11:53:38 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/18 18:28:13 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

t_v32	scene(t_program *program)
{
	program->view->window = create_window("Sig's Ray Tracing Engine", program);
	mlx_hook(program->view->window, 2, 1L << 0, keypress, program);
	mlx_loop_hook(program->view->mlx, render_scene, program);
	mlx_loop(program->view->mlx);
}

t_s32	render_scene(t_v32 *param)
{
	t_program *program;

	program = (t_program *)param;
	draw_circle(program, 42, 42, 42);
	return (0);
}

t_v32 draw_circle(t_program *program, t_u16 center_x, t_u16 center_y, t_u16 radius)
{
    t_u16 x, y;

    for (double angle = 0; angle < 360; angle += 0.1)
    {
        x = center_x + radius * cos(angle);
        y = center_y + radius * sin(angle);

        mlx_pixel_put(program->view->mlx, program->view->window, x, y, 0xFFFFFF); // Set color to white
    }
}