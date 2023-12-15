/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:24:50 by seoson            #+#    #+#             */
/*   Updated: 2023/12/15 14:28:36 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "main.h"

typedef struct s_vector3	t_vector3;
typedef struct s_point3		t_point3;
typedef struct s_color3		t_color3;
typedef struct s_ray		t_ray;
typedef struct s_camera		t_camera;
typedef struct s_canvas		t_canvas;
typedef struct s_sphere		t_sphere;
typedef struct s_hit_record	t_hit_record;
typedef struct s_object		t_object;
typedef struct s_light		t_light;
typedef struct s_scene		t_scene;
typedef struct s_plane		t_plane;
typedef struct s_cylinder	t_cylinder;
typedef struct s_calc		t_calc;
typedef struct s_light_calc	t_light_calc;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_data;

struct s_canvas
{
	int			width;
	int			height;
	double		aspect_ratio;
	double		fov;
};

struct s_vector3
{
	double	x;
	double	y;
	double	z;
};

struct s_color3
{
	double	r;
	double	g;
	double	b;
};

struct s_point3
{
	double	x;
	double	y;
	double	z;
};

struct s_ray
{
	t_vector3	dir;
	t_point3	origin;
};

struct s_camera
{
	double		viewport_h;
	double		viewport_w;
	double		focal_len;
	t_vector3	lookat;
	t_vector3	vup;
	t_vector3	u;
	t_vector3	v;
	t_vector3	w;
	t_vector3	horizontal;
	t_vector3	vertical;
	t_vector3	camera_dir;
	t_vector3	left_top_vector;
	t_point3	origin;
	t_point3	lookfrom;
	t_point3	left_top;
};

struct s_hit_record
{
	double		t;
	double		tmin;
	double		tmax;
	int			id;
	t_vector3	normal;
	t_point3	point;
	t_color3	albedo;
};

struct	s_object
{
	void			*element;
	void			*next;
	int				object_type;
	int				id;
	t_color3		albedo;
};

struct s_light
{
	double		bright_ratio;
	t_point3	origin;
	t_color3	light_color;
};

struct  s_scene
{
	void			*mlx;
	void			*mlx_win;
	double			ambient_ratio;
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
	t_data			img;
};

struct s_sphere
{
	double		radius;
	double		radius_double;
	t_point3	center;
};

struct s_plane
{
	t_vector3	dir;
	t_point3	point;
	t_color3	color;
};

struct	s_cylinder
{
	double		diameter;
	double		height;
	t_vector3	dir;
	t_point3	center;
	t_color3	color;
};

struct	s_calc
{
	double		a;
	double		b;
	double		c;
	double		root;
	double		radius;
	double		diameter;
	double		result;
	double		sqrt_result;
	double		hit_height;
	double		denominator;
	double		molecule;
	t_object	*element;
	t_vector3	vector;
	t_vector3	vector_temp;
};

struct	s_light_calc
{
	double		kd;
	double		brightness;
	double		light_len;
	double		spec;
	double		ks;
	double		ksn;
	t_ray		light_ray;
	t_vector3	light_dir;
	t_vector3	temp;
	t_vector3	light_ray_vector;
	t_vector3	view_dir;
	t_vector3	reflect_dir;
	t_color3	diffuse;
	t_color3	color_temp;
	t_color3	specular;
	t_point3	point_temp;
};

#endif
