/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:41:04 by seoson            #+#    #+#             */
/*   Updated: 2023/12/15 14:19:05 by Sungho           ###   ########.fr       */
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

t_vector3	get_left_top_vector(t_camera *camera)
{
	t_vector3	res;

	res.x = camera->origin.x + (-camera->horizontal.x / 2) + \
		(camera->vertical.x / 2) - camera->focal_len * camera->w.x;
	res.y = camera->origin.y + (-camera->horizontal.y / 2) + \
		(camera->vertical.y / 2) - camera->focal_len * camera->w.y;
	res.z = camera->origin.z + (-camera->horizontal.z / 2) + \
		(camera->vertical.z / 2) - camera->focal_len * camera->w.z;
	return (res);
}

t_camera	camera(t_canvas *canvas, t_point3 origin, t_vector3 dir)
{
	t_camera	camera;

	camera.camera_dir = vector_normalize(dir);
	camera.origin = origin;
	camera.lookfrom = camera.origin;
	camera.lookat = point_plus_vector(camera.lookfrom, camera.camera_dir);
	camera.vup = vec3(0, 1, 0);
	camera.focal_len = vector_length\
		(point_minus_vector(camera.lookfrom, camera.lookat));
	camera.viewport_w = 2.0 * tan(canvas->fov * M_PI / 360);
	camera.viewport_h = camera.viewport_w / canvas->aspect_ratio;
	camera.w = vector_normalize\
		(point_minus_vector(camera.lookfrom, camera.lookat));
	camera.u = vector_normalize(vector_cross(camera.vup, camera.w));
	camera.v = vector_cross(camera.w, camera.u);
	camera.horizontal = vector_multiply_scala(camera.u, camera.viewport_w);
	camera.vertical = vector_multiply_scala(camera.v, camera.viewport_h);
	camera.left_top_vector = get_left_top_vector(&camera);
	return (camera);
}

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

t_light	*light_point\
	(t_point3 light_origin, t_color3 light_color, double bright_ratio)
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
