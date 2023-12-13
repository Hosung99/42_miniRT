/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 16:13:43 by Sungho            #+#    #+#             */
/*   Updated: 2023/12/12 21:34:46 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

double	cy_boundary(t_cylinder *cy, t_point3 point)
{
	t_vector3	temp;
	double		hit_height;
	double		max_height;

	temp.x = point.x - cy->center.x;
	temp.y = point.y - cy->center.y;
	temp.z = point.z - cy->center.z;
	hit_height = vector_dot(temp, cy->dir);
	max_height = cy->height / 2;
	if (fabs(hit_height) > max_height)
		return (-1);
	return (hit_height);
}

t_vector3	 cylinder_normal(t_cylinder *cy, t_point3 point, double height)
{
	t_point3	center;
	t_vector3	normal;

	center.x = cy->center.x + cy->dir.x * height;
	center.y = cy->center.y + cy->dir.y * height;
	center.z = cy->center.z + cy->dir.z * height;
	normal.x = point.x - center.x;
	normal.y = point.y - center.y;
	normal.z = point.z - center.z;
	return (vector_normalize(normal));
}
