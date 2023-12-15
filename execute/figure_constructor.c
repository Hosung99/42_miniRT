/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   figure_constructor.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:12:33 by Sungho            #+#    #+#             */
/*   Updated: 2023/12/15 14:19:26 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

t_plane	*plane(t_vector3 dir, t_point3 point)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		exit(1);
	plane->dir = vector_normalize(dir);
	plane->point = point;
	return (plane);
}

t_sphere	*sphere(t_point3 center, double radius)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	if (!sphere)
		exit(1);
	sphere->center = center;
	sphere->radius = radius;
	sphere->radius_double = radius * radius;
	return (sphere);
}

t_cylinder	*cylinder\
	(t_point3 center, t_vector3 dir, double diameter, double height)
{
	t_cylinder	*cylinder;

	cylinder = (t_cylinder *)malloc(sizeof(t_cylinder));
	if (!cylinder)
		exit(1);
	cylinder->center = center;
	cylinder->dir = vector_normalize(dir);
	cylinder->diameter = diameter;
	cylinder->height = height;
	return (cylinder);
}
