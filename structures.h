/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:24:50 by seoson            #+#    #+#             */
/*   Updated: 2023/12/13 20:46:12 by Sungho           ###   ########.fr       */
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
	int			width; //캔버스 높이
	int			height; //캔버스 길이
	double		aspect_ratio; //종횡비
	double		fov; //수평시야범위 카메라 fov C:FOV
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
	double		viewport_h; //뷰포트 높이
	double		viewport_w; //뷰포트 길이
	double		focal_len; //초점거리
	t_vector3	lookat;
	t_vector3	vup;
	t_vector3	u;
	t_vector3	v;
	t_vector3	w;
	t_vector3	horizontal; //수평길이 벡터
	t_vector3	vertical; //수직길이 벡터
	t_vector3	camera_dir; //카메라 방향벡터 카메라 법선벡터 C:DIR
	t_vector3	left_top_vector; //왼쪽위 코너벡터
	t_point3	origin; //카메라 위치 xyz view point C:XYZ
	t_point3	lookfrom;
	t_point3	left_top; //왼쪽위 코너점
};

struct s_hit_record
{
	double		t; //광선의 원점과 교점사이의 거리
	double		tmin; //카메라 뒷부분. t < 0
	double		tmax; //오브젝트가 카메라보다 너무 먼경우
	int			front_face;
	int			id;
	t_vector3	normal; //교점의 법선벡터
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
	double		bright_ratio; //L: brightness Ratio
	t_point3	origin; // L: light point
	t_color3	light_color; // L: light color RGB
};

struct  s_scene
{
	void			*mlx;
	void			*mlx_win;
	double			ambient_ratio; //ambient lighting  A: ratio
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world; // 도형	넣는곳
	t_object		*light; //L 넣는곳
	t_color3		ambient; //ambient light RGB A:RGB
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
