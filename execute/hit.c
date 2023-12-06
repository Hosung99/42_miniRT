/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:40:45 by seoson            #+#    #+#             */
/*   Updated: 2023/12/06 18:53:48 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

void	set_face_normal(t_ray *ray, t_hit_record *rec) //구가 카메라를 둘러쌈을 고려.
{
	rec->front_face = vector_dot(ray->direction, rec->normal) < 0; //백터 내적
	if (!rec->front_face) //벡터 내적이 0보다 작다면 법선벡터의 반대로 설정해준다.
		rec->normal = vector_multiply_scala(rec->normal, -1);
}

int	cy_boundary(t_cylinder *cy, t_vector3 point)
{
	double	hit_height;
	double	max_height;

	hit_height = vector_dot(vector_minus_vector(point, cy->center), cy->dir);
	max_height = cy->height / 2;
	if (fabs(hit_height) > max_height)
		return (0);
	return (1);
}

t_vector3	cylinder_normal(t_cylinder *cy, t_vector3 point, double height)
{
	t_point3	center;
	t_vector3	normal;

	center = vector_plus_vector(cy->center, vector_multiply_scala(cy->dir, height));
	normal.x = point.x - center.x;
	normal.y = point.y - center.y;
	normal.z = point.z - center.z;
	return (vector_normalize(normal));
}

int	hit_cylinder_side(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_cylinder	*cy;
	t_vector3	oc;
	double		a;
	double		b;
	double		c;
	double		root;
	double		radius;
	double		result;
	double		sqrt;
	double		hit_height;

	t_vecotr3	u;
	t_vector3	o;


	cy = world->element;
	u = ray->direction;
	o = cy->dir;
	radius = cy->radius / 2;
	oc = ray->origin.x - cy->center.x;
	oc.y = ray->origin.y - cy->center.y;
	oc.z = ray->origin.z - cy->center.z;
	a = vector_length_double(vector_cross(u, o));
	b = vector_dot(vector_cross(u, o), vector_cross(oc, o));
	c = vector_length_double(vector_cross(oc, o)) - pow(r, 2);
	result = b * b - a * c;
	if (result < 0)
		return (0);
	sqrt = sqrt(result);
	root = (-b - sqrt) / a;
	if (root < rec->tmin || root > rec->tmax)
	{
		root = (-b + sqrt) / a;
		if (root < rec->tmin || root > rec->tmax)
			return (0);
	}
	hit_height = cy_boundary(cy, ray_at(ray, root));
	if (hit_height == 0)
		return (0);
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->normal = cylinder_normal(cy, rec->point, hit_height);
	set_face_normal(ray, rec);
	rec->albedo = world->albedo;
	return (1);
}

int	hit_cylinder_cap(t_object *world, t_ray *ray, t_hit_record *rec, double height)
{
	t_cylinder	*cy;
	t_vector3	oc;
	t_vector3	temp;
	double		root;
	double		radius;
	double		diameter;

	cy = world->element;
	radius = cy->radius / 2;
	oc = vector_plus_vector(cy->center, vector_multiply_scala(cy->dir, cy->height / 2));
	temp.x = oc.x - ray->origin.x;
	temp.y = oc.y - ray->origin.y;
	temp.z = oc.z - ray->origin.z;
	root = vector_dot(temp, cy->dir) / vector_dot(ray->direction, cy->dir);
	temp.x = oc.x - ray_at(ray, root).x;
	temp.y = oc.y - ray_at(ray, root).y;
	temp.z = oc.z - ray_at(ray, root).z;
	diameter = vector_length(temp);
	if (fabs(diameter) > radius) //왜?? 이해 필요
		return (0);
	if (root < rec->tmin || root > rec->tmax)
		return (0);
	rec->t = root;
	rec->point = ray_at(ray, root);
	rec->tmax = root;
	if (0 < height)
		rec->normal = cy->dir;
	else
		rec->normal = vector_multiply_scala(cy->dir, -1);
	set_face_normal(ray, rec); //원이 카메라를 둘러 쌈을 고려
	rec->albedo = world->albedo;
	return (1);
}

int	hit_cylinder(t_object	*world, t_ray *ray, t_hit_record *rec)
{
	int	is_hit;

	is_hit = 0;
	is_hit += hit_cylinder_cap(world, ray, rec, world->element.height / 2);
	is_hit += hit_cylinder_cap(world, ray, rec, -world->element.height / 2);
	is_hit += hit_cylinder_side(world, ray, rec);
	return (is_hit);
}

int	hit_plane(t_object *world, t_ray *ray, t_hit_record *rec)
{
	t_plane	*pl;
	t_vector3	temp;
	double	parent;
	double	child;
	double	temp2;

	pl = world->element;
	parent = vector_dot(ray->direction, pl->dir);
    if (!parent) // parent가 0일 경우, 레이와 평면이 평행하므로 교차하지 않음
        return (0);
	temp.x = pl->point.x - ray->origin.x;
	temp.y = pl->point.y - ray->origin.y;
	temp.z = pl->point.z - ray->origin.z;
	child = vector_dot(temp, pl->dir);
	temp2 = -child / parent;
	if (temp2 < rec->tmin || temp2 > rec->tmax)
		return (0);
	rec->t = temp2;
	rec->point = ray_at(ray, rec->t);
	rec->normal = pl->dir;
	rec->albedo = world->albedo;
	return (1);
}

int	hit_sphere(t_object *world, t_ray *ray, t_hit_record *rec)
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
	else if (world->object_type == CY)
		hit_result = hit_cylinder(world, ray, rec);
	if (hit_result && vector_dot(ray->direction, rec->normal) > 0)
		hit_result = 0;
	return (hit_result);
}
