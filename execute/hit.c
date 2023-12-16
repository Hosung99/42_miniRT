/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:40:45 by seoson            #+#    #+#             */
/*   Updated: 2023/12/15 17:53:22 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec)
{
	if (vector_dot(ray->dir, rec->normal) > 0)
		rec->normal = vector_multiply_scala(rec->normal, -1);
}

int	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int				is_hit;
	t_hit_record	*temp_rec;
	t_object		*temp_world;

	temp_rec = rec;
	is_hit = 0;
	temp_world = world;
	while (temp_world)
	{
		if (temp_world->id != rec->id && hit_obj(temp_world, ray, temp_rec))
		{
			is_hit = 1;
			temp_rec->tmax = temp_rec->t;
			rec = temp_rec;
		}
		temp_world = temp_world->next;
	}
	return (is_hit);
}

int	hit_obj(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int	hit_result;

	hit_result = 0;
	if (world->object_type == SP)
		hit_result = hit_sphere(world, ray, rec);
	else if (world->object_type == PL)
		hit_result = hit_plane(world, ray, rec);
	else if (world->object_type == CY)
		hit_result = hit_cylinder(world, ray, rec);
	return (hit_result);
}
