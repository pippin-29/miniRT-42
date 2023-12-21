/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:29:34 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/21 07:07:54 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8	draw_pixel(t_u16 x, t_u16 y, t_program *program)
{
	mlx_pixel_put(program->view->mlx, program->view->window, x, y, 0x00FF0000);
}

t_v8	draw_line(t_u16 a, t_u16 b, t_u16 x, t_u16 y)
{
	
}