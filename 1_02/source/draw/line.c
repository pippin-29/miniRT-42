/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:20:33 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/19 10:45:24 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_v8 draw_line(t_f32 x0, t_f32 y0, t_f32 x1, t_f32 y1,t_program *program)
{
    int dx = fabsf((100 * x1) - x0);
    int dy = fabsf((100 * y1) - y0);
    int sx = (x0 < (100 * x1)) ? 1 : -1;
    int sy = (y0 < (100 * y1)) ? 1 : -1;
    int err = dx - dy;

    while (1)
    {
        mlx_pixel_put(program->view->mlx, program->view->window, x0, y0, 0xFFFFFF); // 0xFFFFFF is the color in hexadecimal (white)

        if (x0 == (100 * x1) && y0 == (100 * y1))
            break;

        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y0 += sy;
        }
    }
}
 