/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 09:16:25 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/27 09:33:53 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/miniRT.h"

t_u32	rgb_2_hex(t_u16 *rgb, t_f32 shade)
{
	t_u8	r_shade;
	t_u8	g_shade;
	t_u8	b_shade;
	t_u32	hex_rep;

	r_shade = (t_u8)(rgb[R] * shade);
	g_shade = (t_u8)(rgb[B] * shade);
	b_shade = (t_u8)(rgb[G] * shade);

	hex_rep = (r_shade << 16) | (g_shade << 8) | b_shade;
	return (hex_rep);
}