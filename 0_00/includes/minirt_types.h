/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:34:54 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/17 06:23:13 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

typedef unsigned int	t_u32;

typedef struct s_sphere
{
	float	*coord;
	float	diam;
	t_u32	*rgb;
}	t_sphere;

typedef struct s_plane
{
	float	*coord;
	float	*normal_vector;
	t_u32	*rgb;
}	t_plane;

typedef struct s_cylinder
{
	float	*coord;
	float	*normal_vector;
	float	diam;
	float	height;
	t_u32	*rgb;
}	t_cylinder;

typedef struct s_camera
{
	float	*coord;
	float	*normal_vector;
	float	fov;
}	t_camera;

typedef struct s_light
{
	float	*coord;
	float	brightness;
}	t_light;

typedef struct s_amb_light
{
	float	brightness;
	t_u32	*rgb;
}	t_amb_light;

typedef struct s_program
{
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_camera	*camera;
	t_light		*light;
	t_amb_light	*amb_light;
	t_u32		no_spheres;
	t_u32		no_planes;
	t_u32		no_cylinders;
	t_u32		no_light;
	t_u32		no_amb_light;
	t_u32		no_camera;
	int			scene_fd;
}	t_program;


#endif