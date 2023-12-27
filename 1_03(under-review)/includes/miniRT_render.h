/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_render.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:30:07 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/27 09:38:00 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_RENDER_H
# define MINIRT_RENDER_H

t_v8	draw_pixel(t_u16 x, t_u16 y, t_program *program, t_u32 hex_color);
t_u16	map_x(t_f32 x, t_f32 z, t_program *program);
t_u16	map_y(t_f32 y, t_f32 z, t_program *program);
t_u32	rgb_2_hex(t_u16 *rgb, t_f32 shade);

t_v8	scene(t_program *program);
t_s32	render_scene(t_v8 *param);

#endif