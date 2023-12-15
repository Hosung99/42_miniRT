/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:03:18 by seoson            #+#    #+#             */
/*   Updated: 2023/12/14 17:15:16 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_ray ray(t_point3 origin, t_vector3 dir)
{
	t_ray ray;

	ray.origin = origin;
	ray.dir = vector_normalize(dir);
	return (ray);
}

t_point3 ray_at(t_ray *ray, double t)
{
	t_point3 at;

	at.x = ray->origin.x + t * ray->dir.x;
	at.y = ray->origin.y + t * ray->dir.y;
	at.z = ray->origin.z + t * ray->dir.z;
	return (at);
}

t_ray	ray_primary(t_camera *camera, double u, double v)
{
	t_ray		ray;
	t_vector3	vec;
	t_vector3	vec_dir;

	ray.origin = camera->origin;
	vec_dir = vector_plus_vector(vector_multiply_scala(camera->horizontal, u), \
	 vector_multiply_scala(camera->vertical, -v));
	vec.x = camera->left_top_vector.x + vec_dir.x - camera->origin.x;
	vec.y = camera->left_top_vector.y + vec_dir.y - camera->origin.y;
	vec.z = camera->left_top_vector.z + vec_dir.z - camera->origin.z;
	ray.dir = vec;
	return (ray);
}

t_color3	ray_color(t_scene *scene)
{
	scene->rec = record_init();
	if (hit(scene->world, &scene->ray, &scene->rec))
		return (phong_lightning(scene));
	else
		return (color3(0, 0, 0));
}
