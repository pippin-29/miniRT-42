/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_math.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 20:25:08 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/19 10:42:10 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MATH_H
# define MINIRT_MATH_H

/// VECTOR3D_C ///
t_f32	*assign_vec_x_3d(t_v8);
t_f32	*assign_vec_y_3d(t_v8);
t_f32	*assign_vec_z_3d(t_v8);

/// VECTOR_TRANSLATION_C ///
t_f32	*assign_vec_x_2d(t_program *program);
t_f32	*assign_vec_y_2d(t_program *program);
t_f32	*assign_vec_z_2d(t_program *program);


#endif