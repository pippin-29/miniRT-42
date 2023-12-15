/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:34:54 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/15 11:52:51 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

typedef unsigned char	t_u8;

typedef struct s_sphere
{
	float	coord[3];
	float	diam;
	t_u8	rgb[3];
}	t_sphere;

typedef struct s_plane
{
	float	coord[3];
	float	normal_vector[3];
	t_u8	rgb[3];
}	t_plane;

typedef struct s_cylinder
{
	float	coord[3];
	float	normal_vector[3];
	float	diam;
	float	height;
	t_u8	rgb[3];
}	t_cylinder;

typedef struct s_camera
{
	float	coord[3];
	float	normal_vector[3];
	t_u8	fov;
}	t_camera;

typedef struct s_light
{
	float	coord[3];
	float	brightness;
}	t_light;

typedef struct s_amb_light
{
	float	brightness;
	t_u8	rgb[3];
}	t_amb_light;

typedef struct s_program
{
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_camera	*camera;
	t_light		*light;
	t_amb_light	*amb_light;
	t_u8		no_spheres;
	t_u8		no_planes;
	t_u8		no_cylinders;
	int			scene_fd;
}	t_program;


#endif