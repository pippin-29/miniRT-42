/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:29:34 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/27 08:57:25 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8	draw_pixel(t_u16 x, t_u16 y, t_program *program, t_u32 hex_color)
{
	mlx_pixel_put(program->view->mlx, program->view->window, x, y, hex_color);
}
