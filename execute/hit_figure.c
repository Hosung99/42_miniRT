/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_figure.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:41:52 by Sungho            #+#    #+#             */
/*   Updated: 2023/12/13 10:50:05 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_rec(t_hit_record *rec, t_object *world, t_ray *ray, double root)
{
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->albedo = world->albedo;
	rec->id = world->id;
}

int	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_calc		calc;
	t_sphere	*sp;

	sp = world->element;
	calc.vector = point_minus_point(ray->origin, sp->center);
	calc.a = vector_length_double(ray->dir);
	calc.b = vector_dot(calc.vector, ray->dir);
	calc.c = vector_length_double(calc.vector) - sp->radius_double;
	calc.result = calc.b * calc.b - calc.a * calc.c;
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
	set_rec(rec, world, ray, calc.root);
	rec->normal = point_minus_point(rec->point, sp->center);
	rec->normal = vector_divide_scala(rec->normal, sp->radius);
	set_face_normal(ray, rec);
	return (1);
}

int	hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_calc		calc;
	t_plane		*pl;

	pl = world->element;
	calc.denominator = vector_dot(pl->dir, ray->dir);
    if (!calc.denominator)
        return (0);
	calc.molecule = vector_dot(point_minus_point(pl->point, ray->origin),\
		 pl->dir);
	calc.result = -calc.molecule / calc.denominator;
	if (calc.result < rec->tmin || calc.result > rec->tmax)
		return (0);
	set_rec(rec, world, ray, calc.result);
	rec->normal = pl->dir;
	return (1);
}
