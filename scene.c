/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:41:04 by seoson            #+#    #+#             */
/*   Updated: 2023/12/11 12:26:52 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_canvas canvas(int width, int height, double fov)
{
	t_canvas canvas;

	canvas.width = width;
	canvas.height = height;
	canvas.aspect_ratio = 16.0 / 9.0;
	canvas.fov = fov;
	return (canvas);
}

t_camera camera(t_canvas *canvas, t_point3 origin)
{
	t_camera camera;

	camera.origin = origin;
	camera.focal_len = 1.0;
	camera.viewport_w = 2.0 * tan(canvas->fov * M_PI / 180);
	camera.viewport_w = 2.0 * tan(canvas->fov);
	camera.viewport_h = camera.viewport_w / canvas->aspect_ratio;
	camera.horizontal = vec3(camera.viewport_w, 0, 0);
	camera.vertical = vec3(0, camera.viewport_h, 0);
	camera.left_top.x = camera.origin.x - camera.viewport_w / 2;
	camera.left_top.y = camera.origin.y + camera.viewport_h / 2;
	camera.left_top.z = camera.origin.z - camera.focal_len;
	return (camera);
}


t_plane *plane(t_vector3 dir, t_point3 point, t_color3 color)
{
	t_plane *plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		return (NULL);
	plane->dir = vector_normalize(dir);
	plane->point = point;
	plane->color = color;
	return (plane);
}

t_sphere *sphere(t_point3 center, double radius)
{
	t_sphere *sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		return (NULL);
	sphere->center = center;
	sphere->radius1 = radius;
	sphere->radius2 = radius * radius;
	return (sphere);
}

t_object *object(int type, void *element, t_color3 albedo, int id)
{
	t_object *new;

	new = (t_object *)malloc(sizeof(t_object));
	if (!new)
		return (NULL);
	new->object_type = type;
	new->element = element;
	new->next = NULL;
	new->albedo = albedo;
	new->id = id;
	return (new);
}

t_light	*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio)
{
	t_light *light;

	light = (t_light *)malloc(sizeof(t_light));
	if (!light)
		return (NULL);
	light->origin = light_origin;
	light->light_color = light_color;
	light->bright_ratio = bright_ratio;
	return (light);
}

t_cylinder *cylinder(t_point3 center, t_vector3 dir, double diameter, double height)
{
	t_cylinder *cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		return (NULL);
	cylinder->center = center;
	cylinder->dir = vector_normalize(dir);
	cylinder->diameter = diameter;
	cylinder->height = height;
	return (cylinder);
}
