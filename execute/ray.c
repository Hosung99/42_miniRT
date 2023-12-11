/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:03:18 by seoson            #+#    #+#             */
/*   Updated: 2023/12/11 14:37:03 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

//ray 생성자(정규화 된 ray)
t_ray ray(t_point3 origin, t_vector3 dir)
{
	t_ray ray;

	ray.origin = origin;
	//vunit 함수에서 방향벡터의 크기를 1로 정규화해준다.
	ray.direction = vector_normalize(dir);
	return (ray);
}

//ray origin point 부터 방향벡터 ray dir * t 만큼 떨어진 점.
t_point3 ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at.x = ray->origin.x + t * ray->direction.x;
	at.y = ray->origin.y + t * ray->direction.y;
	at.z = ray->origin.z + t * ray->direction.z;
	return (at);
}

t_ray	ray_primary(t_camera *camera, double u, double v)
{
	t_ray		ray;
	t_vector3	vec;
	t_vector3	temp;

	ray.origin = camera->origin;
	temp = vector_plus_vector(vector_multiply_scala(camera->horizontal, u), vector_multiply_scala(camera->vertical, -v));
	vec.x = camera->left_top.x + temp.x - camera->origin.x;
	vec.y = camera->left_top.y + temp.y - camera->origin.y;
	vec.z = camera->left_top.z + temp.z - camera->origin.z;
	ray.direction = vector_normalize(vec);
	return (ray);
}

int	in_shadow(t_object *obj, t_ray light_ray, double light_ren)
{
	t_hit_record rec;

	rec.tmin = 0;
	rec.tmax = light_ren;
	if (hit(obj, &light_ray, &rec, -1))
		return (1);
	return (0);
}

t_hit_record		record_init(void)
{
	t_hit_record record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	return (record);
}

t_vector3	reflect(t_vector3 v, t_vector3 n)
{
	t_vector3 temp;

	temp = vector_multiply_scala(n, 2 * vector_dot(v, n));
	return (vector_minus_vector(v, temp));
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_color3 diffuse;
	t_color3 color_temp;
	t_vector3 light_dir;
	t_vector3 temp;
	t_point3 point_temp;
	double	kd; //diffuse 강도
	double	brightness;
	double	light_len;
	t_ray	light_ray;

	t_color3	specular;
	t_vector3	view_dir;
	t_vector3	reflect_dir;
	double		spec;
	double		ks;
	double		ksn;

	scene->rec.normal = vector_normalize(scene->rec.normal);
	temp.x = light->origin.x - scene->rec.point.x; //맞은점에서 광원까지의 벡터
	temp.y = light->origin.y - scene->rec.point.y;
	temp.z = light->origin.z - scene->rec.point.z;
	light_len = vector_length(temp); //그 거리
	point_temp.x = scene->rec.point.x + EPSILON * scene->rec.normal.x; //맞은점에서 광원까지의 벡터와 광원에서 출발하는 ray를 만들기 위해
	point_temp.y = scene->rec.point.y + EPSILON * scene->rec.normal.y;
	point_temp.z = scene->rec.point.z + EPSILON * scene->rec.normal.z;
	// light_ray = ray(point_temp, temp);
	// light_ray = ray(scene->rec.point, temp);
	// if (in_shadow(scene->world, light_ray, light_len))
		// return (color3(0,0,0));
	light_dir = vector_normalize(temp); //교점에서 출발하여 광원을 향하는 벡터 (정규화한)
	//cos세타가 90도일때 , 0이고 세타가 둔각일 시 음수가 되므로 0.0으로 초기화해준다.
	kd = fmax(vector_dot(scene->rec.normal, light_dir), 0.0); //두 벡터의 내적
	diffuse = color_multiply_scala(light->light_color, kd);
	view_dir = vector_normalize(vector_multiply_scala(scene->ray.direction, -1));
	reflect_dir = reflect(vector_multiply_scala(light_dir, -1), scene->rec.normal);
	ksn = 64; //shiness value
	ks = 0.5; //specualr strength
	spec = pow(fmax(vector_dot(view_dir,reflect_dir), 0.0), ksn);
	specular = color_multiply_scala(color_multiply_scala(light->light_color, ks), spec);
	brightness = light->bright_ratio * LUMEN;
	color_temp = color_plus_color(scene->ambient, diffuse);
	color_temp = color_plus_color(color_temp, specular);
	return (color_multiply_scala(color_temp, brightness));
}

t_color3	phong_lightning(t_scene *scene)
{
	t_color3 	light_color;
	t_object	*lights;

	light_color = color3(0,0,0); //광원 초기화
	lights = scene->light;
	while(lights)
	{
		if (lights->object_type == LIGHT_POINT)
			light_color = color_plus_color(light_color, point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = color_plus_color(light_color, scene->ambient); //모든 광원에 의한 빛의 양을 구한 후
	light_color = color_multiply_color(light_color, scene->rec.albedo); //object의 색상과 곱한다.
	return (color_min(light_color, color3(1,1,1))); //만약 광원의 합이 1보다 크면 color(1,1,1)을 반환
}

t_color3	ray_color(t_scene *scene)
{
	double t;

	scene->rec = record_init();
	//ray의 방향벡터의 y 값을 기준으로 그라데이션을 주기 위한 계수.
	if (hit(scene->world, &scene->ray, &scene->rec, -1))
		return (phong_lightning(scene));
	else
	{
		// (1-t) * 흰색 + t * 하늘색
		t = 0.5 * (scene->ray.direction.y + 1.0);
		return (color_plus_color(color_multiply_scala(color3(1,1,1), 1.0-t), color_multiply_scala(color3(0.5,0.7,1.0), t)));
		// return (color3(1, 1, 1));
	}
}
