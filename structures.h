/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:24:50 by seoson            #+#    #+#             */
/*   Updated: 2023/12/06 19:00:19 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

# include "main.h"
# define TRUE 1
# define FALSE 0
# define SP 1
# define PL 2
# define CY 3
# define LIGHT_POINT 1
# define EPSILON 1e-6
# define LUMEN 2
# define WIDTH 1920
# define HEIGHT 1080
# define ESC_CODE 53

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
	int		width; //캔버스 높이
	int		height; //캔버스 길이
	double	aspect_ratio; //종횡비
	double		fov; //수평시야범위
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
	t_point3	origin;
	t_vector3	direction;
};

struct s_camera
{
	t_point3	origin; //카메라 위치
	double		viewport_h; //뷰포트 높이
	double		viewport_w; //뷰포트 길이
	t_vector3	horizontal; //수평길이 벡터
	t_vector3	vertical; //수직길이 벡터
	double		focal_len; //초점거리
	t_point3	left_top; //왼쪽위 코너점
};

struct s_hit_record
{
	t_point3	point;
	t_vector3	normal; //교점의 법선벡터
	double		t; //광선의 원점과 교점사이의 거리
	double		tmin; //카메라 뒷부분. t < 0
	double		tmax; //오브젝트가 카메라보다 너무 먼경우
	int			front_face;
	t_color3	albedo;
};

struct	s_object
{
	int				object_type;
	void			*element;
	void			*next;
	t_color3		albedo;
};

struct s_light
{
	t_point3	origin;
	t_color3	light_color;
	double		bright_ratio;
};

struct  s_scene
{
	t_canvas		canvas;
	t_camera		camera;
	t_object		*world;
	t_object		*light;
	t_color3		ambient;
	t_ray			ray;
	t_hit_record	rec;
	t_data			img;
	void			*mlx;
	void			*mlx_win;
};

struct s_sphere
{
	t_point3	center;
	double		radius1;
	double		radius2;
};

struct s_plane
{
	t_vector3	dir; //평면의 방향벡터
	t_point3	point; //위치
	t_color3	color; //RGB
};

struct	s_cylinder
{
	t_point3	center;
	t_vector3	dir;
	t_color3	color;
	double		radius;
	double		height;
};

#endif
