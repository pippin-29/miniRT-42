/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:30:07 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/28 08:41:57 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

/// COLOR_C ///
t_u32	rgb_2_hex(t_u16 *rgb, t_f32 shade);

/// PIXEL_C ///
t_v8	draw_pixel(t_u16 x, t_u16 y, t_program *program, t_u32 hex_color);

/// RENDER_C ///
t_v8	scene(t_program *program);
t_s32	render_scene(t_v8 *param);

/// SPACE_C ///
t_u16	map_x(t_f32 x, t_f32 z, t_program *program);
t_u16	map_y(t_f32 y, t_f32 z, t_program *program);




#endif