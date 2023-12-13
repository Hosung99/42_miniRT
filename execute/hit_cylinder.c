/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 18:24:24 by Sungho            #+#    #+#             */
/*   Updated: 2023/12/13 14:52:18 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	hit_cylinder(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	int	is_hit;

	cy = world->element;
	if (vector_dot(ray->dir, cy->dir) < 0)
		cy->dir = vector_multiply_scala(cy->dir, -1);
	is_hit = 0;
	is_hit += hit_cylinder_cap(world, ray, rec, cy->height / 2);
	is_hit += hit_cylinder_cap(world, ray, rec, -(cy->height / 2));
	is_hit += hit_cylinder_side(world, ray, rec);
	return (is_hit);
}

void	calc_cylinder(t_calc *calc, t_ray *ray, t_cylinder *cy)
{
	calc->vector = point_minus_point(ray->origin, cy->center);
	calc->a = vector_length_double(vector_cross(ray->dir, cy->dir));
	calc->b = vector_dot(vector_cross(ray->dir, cy->dir), \
			vector_cross(calc->vector, cy->dir));
	calc->c = vector_length_double(vector_cross(calc->vector, cy->dir))\
			- pow(cy->diameter / 2, 2);
	calc->result = calc->b * calc->b - calc->a * calc->c;
}

int	hit_cylinder_side(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_calc		calc;

	cy = world->element;
	calc_cylinder(&calc, ray, cy);
	if (calc.result < 0)
		return (0);
	calc.sqrt_result = sqrt(calc.result);
	calc.root = (-calc.b - calc.sqrt_result) / calc.a;
	if (calc.root < rec->tmin || calc.root > rec->tmax)
	{
		calc.root = (-calc.b + calc.sqrt_result) / calc.a;
		if (calc.root < rec->tmin || calc.root > rec->tmax)
			return (0);
	}
	calc.hit_height = cy_boundary(cy, ray_at(ray, calc.root));
	if (calc.hit_height == -1.0)
		return (0);
	set_rec(rec, world, ray, calc.root);
	rec->normal = cylinder_normal(cy, rec->point, calc.hit_height);
	set_face_normal(ray, rec);
	return (1);
}

int	hit_cylinder_cap(t_object *world, t_ray *ray, \
		t_hit_record *rec, double height)
{
	t_cylinder	*cy;
	t_calc		calc;

	cy = world->element;
	calc.radius = cy->diameter / 2;
	calc.vector = point_plus_vector(cy->center, \
		vector_multiply_scala(cy->dir, height));
	calc.vector_temp = vector_minus_point(calc.vector, ray->origin);
	calc.root = vector_dot(calc.vector_temp, cy->dir) / \
		vector_dot(ray->dir, cy->dir);
	calc.vector_temp = vector_minus_point(calc.vector, ray_at(ray, calc.root));
	calc.diameter = vector_length(calc.vector_temp);
	if (fabs(calc.diameter) > fabs(calc.radius))
		return (0);
	if (calc.root < rec->tmin || calc.root > rec->tmax)
		return (0);
	set_rec(rec, world, ray, calc.root);
	rec->normal = vector_multiply_scala(cy->dir, height);
	return (1);
}
