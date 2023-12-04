/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:40:45 by seoson            #+#    #+#             */
/*   Updated: 2023/12/04 20:22:21 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec) //구가 카메라를 둘러쌈을 고려.
{
	rec->front_face = vector_dot(ray->direction, rec->normal) < 0; //백터 내적
	if (!rec->front_face) //벡터 내적이 0보다 작다면 법선벡터의 반대로 설정해준다.
		rec->normal = vector_multiply_scala(rec->normal, -1);
}

double	hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	t_vector3	temp;
	float	parent;
	float	child;
	float	temp2;

	pl = world->element;
	parent = vector_dot(ray->direction, pl->dir);
	if (parent < EPSILON)
		return (0);
	temp.x = rec->point.x - ray->origin.x;
	temp.y = rec->point.y - ray->origin.y;
	temp.z = rec->point.z - ray->origin.z;
	child = vector_dot(temp, pl->dir);
	temp2 = child / parent;
	if (temp2 < rec->tmin || temp2 > rec->tmax)
		return (0);
	rec->t = child / parent;
	rec->point = ray_at(ray, rec->t);
	rec->normal = vector_normalize(pl->dir);
	rec->albedo = pl->color;
	return (1);
}

double	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_vector3 oc;
	t_sphere *sp;
	double a;
	double half_b;
	double c;
	double result;
	double	sqrt_result;
	double	root;

	sp = world->element;
	oc.x = ray->origin.x - sp->center.x;
	oc.y = ray->origin.y - sp->center.y;
	oc.z = ray->origin.z - sp->center.z;
	a = vector_length_double(ray->direction);
	half_b = vector_dot(oc, ray->direction);
	c = vector_length_double(oc) - sp->radius2;
	result = half_b * half_b - a * c; //짝수 근의공식
	if (result < 0)
		return (0);
	sqrt_result = sqrt(result); //루트 씌우기
	root = (-half_b - sqrt_result) / a; //두 근 중 작은 근
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-half_b + sqrt_result) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (0);
	}
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->normal.x = (rec->point.x - sp->center.x) / sp->radius1;
	rec->normal.y = (rec->point.y - sp->center.y) / sp->radius1;
	rec->normal.z = (rec->point.z - sp->center.z) / sp->radius1;
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (1);
}

int	hit(t_object *world, t_ray *ray, t_hit_record *rec)
{
	int			is_hit;
	t_hit_record *temp_rec;

	temp_rec = rec;
	is_hit = 0;
	while (world)
	{
		if (hit_obj(world, ray, temp_rec))
		{
			is_hit = 1;
			temp_rec->tmax = temp_rec->t; //ray가 object에 hit시 tmax를 히트한 t로 바꾸어 그 다음 오브젝트 검사시에 더 멀리 있는 오브젝트는 hit가 안되도록 설정
			rec = temp_rec;
		}
		world = world->next;
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
	return (hit_result);
}