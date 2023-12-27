/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadding <operas.referee.0e@icloud.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 16:34:54 by dhadding          #+#    #+#             */
/*   Updated: 2023/12/27 09:29:06 by dhadding         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_H
# define MINIRT_TYPES_H

typedef void			t_v8;
typedef char			t_s8;
typedef unsigned char	t_u8;
typedef short			t_s16;
typedef unsigned short	t_u16;
typedef int				t_s32;
typedef unsigned int	t_u32;
typedef float			t_f32;
typedef long			t_s64;
typedef unsigned long	t_u64;
typedef double			t_f64;

typedef struct s_sphere
{
	t_f32	*coord;
	t_f32	diam;
	t_u16	*rgb;
}	t_sphere;

typedef struct s_plane
{
	t_f32	*coord;
	t_f32	**normal_vector;
	t_u16	*rgb;
}	t_plane;

typedef struct s_cylinder
{
	t_f32	*coord;
	t_f32	**normal_vector;
	t_f32	diam;
	t_f32	height;
	t_u16	*rgb;
}	t_cylinder;

typedef struct s_camera
{
	t_f32	*coord;
	t_f32	**normal_vector;
	t_f32	fov;
}	t_camera;

typedef struct s_light
{
	t_f32	*coord;
	t_f32	brightness;
}	t_light;

typedef struct s_amb_light
{
	t_f32	brightness;
	t_u16	*rgb;
}	t_amb_light;

typedef struct s_mlx
{
	t_v8	*mlx;
	t_v8	*window;
	t_u16	resolution[2];
}	t_mlx;

typedef struct s_world
{
	
} t_world;

typedef struct s_space
{
	t_f32	screen[2];
	t_f32	ndc[2];
	t_u16	raster[2];
} t_space;

typedef struct s_program
{
	t_mlx		*view;
	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_camera	*camera;
	t_light		*light;
	t_amb_light	*amb_light;
	t_space		*space;
	t_u16		no_spheres;
	t_u16		no_planes;
	t_u16		no_cylinders;
	t_u16		no_light;
	t_u16		no_amb_light;
	t_u16		no_camera;
	t_u16		i;
	t_s32		scene_fd;
}	t_program;

#endif