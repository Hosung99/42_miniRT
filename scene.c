/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:41:04 by seoson            #+#    #+#             */
/*   Updated: 2023/12/14 10:24:51 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_canvas	canvas(int width, int height, double fov)
{
	t_canvas	canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = 16.0 / 9.0;
	canvas.fov = fov;
	return (canvas);
}

// t_vector3	get_left_top_vector(t_camera *camera)
// {
// 	t_vector3	res;

// 	res.x = camera->origin.x + (-camera->horizontal.x / 2) + (camera->vertical.x / 2) - camera->focal_len * camera->w.x;
// 	res.y = camera->origin.y + (-camera->horizontal.y / 2) + (camera->vertical.y / 2) - camera->focal_len * camera->w.y;
// 	res.z = camera->origin.z + (-camera->horizontal.z / 2) + (camera->vertical.z / 2) - camera->focal_len * camera->w.z;
	// camera.left_top.x = camera.origin.x - camera.viewport_w / 2;
	// camera.left_top.y = camera.origin.y + camera.viewport_h / 2;
	// camera.left_top.z = camera.origin.z - camera.focal_len;
// 	return (res);
// }

t_camera	camera(t_canvas *canvas, t_point3 origin, t_vector3 dir)
{
	t_camera	camera;

	// camera.camera_dir = vector_normalize(dir);
	(void)dir;
	camera.origin = origin;
	camera.focal_len = 1.0;
	camera.viewport_w = 2.0 * tan(canvas->fov * M_PI / 360);
	camera.viewport_h = camera.viewport_w / canvas->aspect_ratio;
	camera.horizontal = vec3(camera.viewport_w, 0, 0);
	camera.vertical = vec3(0, camera.viewport_h, 0);
	camera.left_top.x = camera.origin.x - camera.viewport_w / 2;
	camera.left_top.y = camera.origin.y + camera.viewport_h / 2;
	camera.left_top.z = camera.origin.z - camera.focal_len;
	// camera.lookfrom = camera.origin;
	// camera.lookat = point_plus_vector(camera.lookfrom, camera.camera_dir);
	// camera.vup = vec3(0, 1, 0);x
	// camera.focal_len = vector_length(vector_minus_point(camera.lookat, camera.lookfrom));
	// camera.w = vector_normalize(vector_minus_point(camera.lookat, camera.lookfrom));
	// camera.u = vector_normalize(vector_cross(camera.vup, camera.w));
	// camera.v = vector_multiply_scala(vector_cross(camera.w, camera.u), -1);
	// camera.horizontal = vector_multiply_scala(camera.u, camera.viewport_w);
	// camera.vertical = vector_multiply_scala(camera.v, camera.viewport_h);
	// camera.left_top_vector = get_left_top_vector(&camera);
	// printf("camera.left_top_vector.x : %f\n", camera.left_top_vector.x);
	// printf("camera.left_top_vector.y : %f\n", camera.left_top_vector.y);
	// printf("camera.left_top_vector.z : %f\n", camera.left_top_vector.z);
	printf("camera.left_top.x : %f\n", camera.left_top.x);
	printf("camera.left_top.y : %f\n", camera.left_top.y);
	printf("camera.left_top.z : %f\n", camera.left_top.z);
	return (camera);
}

// t_plane *plane(t_vector3 dir, t_point3 point)
// {
// 	t_plane *plane;

// 	plane = (t_plane *)malloc(sizeof(t_plane));
// 	if (!plane)
// 		return (NULL);
// 	plane->dir = vector_normalize(dir);
// 	plane->point = point;
// 	return (plane);
// }

// t_sphere *sphere(t_point3 center, double radius)
// {
// 	t_sphere *sphere;

// 	sphere = (t_sphere *)malloc(sizeof(t_sphere));
// 	if (!sphere)
// 		return (NULL);
// 	sphere->center = center;
// 	sphere->radius = radius;
// 	sphere->radius_double = radius * radius;
// 	return (sphere);
// }

t_object *object(int type, void *element, t_color3 albedo, int id)
{
	t_object *new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		exit(1);
	new->object_type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	new->id = id;
	return (new);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light	*light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		exit(1);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}
