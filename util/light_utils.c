/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:03:07 by Sungho            #+#    #+#             */
/*   Updated: 2023/12/15 14:22:02 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	in_shadow(t_scene *scene, t_ray light_ray, double light_ren)
{
	t_hit_record rec;

	rec.tmin = 0;
	rec.tmax = light_ren;
	rec.id = scene->rec.id;
	if (hit(scene->world, &light_ray, &rec))
		return (1);
	return (0);
}

t_vector3	reflect(t_vector3 v, t_vector3 n)
{
	t_vector3 temp_vector;

	temp_vector = vector_multiply_scala(n, 2 * vector_dot(v, n));
	return (vector_minus_vector(v, temp_vector));
}

t_hit_record	record_init(void)
{
	t_hit_record record;

	record.tmin = EPSILON;
	record.tmax = INFINITY;
	record.id = -1;
	return (record);
}

t_color3	point_light_get(t_scene *scene, t_light *light)
{
	t_light_calc	calc;

	calc.light_ray_vector = point_minus_point(light->origin, scene->rec.point);
	calc.light_len = vector_length(calc.light_ray_vector);
	calc.point_temp = vector_plus_point\
		(vector_multiply_scala(scene->rec.normal, EPSILON), scene->rec.point);
	calc.light_ray = ray(calc.point_temp, calc.light_ray_vector);
	if (in_shadow(scene, calc.light_ray, calc.light_len))
		return (color3(0,0,0));
	calc.light_dir = vector_normalize(calc.light_ray_vector);
	calc.kd = fmax(vector_dot(scene->rec.normal, calc.light_dir), 0.0);
	calc.diffuse = color_multiply_scala(light->light_color, calc.kd);
	calc.view_dir = vector_normalize(vector_multiply_scala(scene->ray.dir, -1));
	calc.reflect_dir = reflect(vector_multiply_scala\
		(calc.light_dir, -1), scene->rec.normal);
	calc.ksn = 64;
	calc.ks = 0.2;
	calc.spec = pow(fmax(vector_dot\
		(calc.view_dir, calc.reflect_dir), 0.0), calc.ksn);
	calc.specular = color_multiply_scala\
		(color_multiply_scala(light->light_color, calc.ks), calc.spec);
	calc.brightness = light->bright_ratio * LUMEN;
	calc.color_temp = color_plus_color(scene->ambient, calc.diffuse);
	calc.color_temp = color_plus_color(calc.color_temp, calc.specular);
	return (color_multiply_scala(calc.color_temp, calc.brightness));
}

t_color3	phong_lightning(t_scene *scene)
{
	t_color3 	light_color;
	t_object	*lights;

	light_color = color3(0,0,0);
	lights = scene->light;
	while(lights)
	{
		if (lights->object_type == LIGHT_POINT)
			light_color = color_plus_color(light_color, \
				point_light_get(scene, lights->element));
		lights = lights->next;
	}
	light_color = color_plus_color(light_color, scene->ambient);
	light_color = color_multiply_color(light_color, scene->rec.albedo);
	return (color_min(light_color, color3(1,1,1)));
}
