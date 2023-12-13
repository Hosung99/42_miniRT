/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:03:45 by seoson            #+#    #+#             */
/*   Updated: 2023/12/12 20:41:53 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_point3	point_plus_point(t_point3 vec, t_point3 vec2)
{
    vec.x += vec2.x;
    vec.y += vec2.y;
    vec.z += vec2.z;
    return (vec);
}

t_vector3	point_plus_vector(t_point3 point, t_vector3 vec)
{
	t_vector3	result;

	result.x = point.x + vec.x;
	result.y = point.y + vec.y;
	result.z = point.z + vec.z;
	return (result);
}

t_vector3	point_minus_point(t_point3 point1, t_point3 point2)
{
	t_vector3	result;

	result.x = point1.x - point2.x;
	result.y = point1.y - point2.y;
	result.z = point1.z - point2.z;
	return (result);
}

t_vector3	point_divide_scala(t_point3 point, double t)
{
	t_vector3	result;

	result.x = point.x / t;
	result.y = point.y / t;
	result.z = point.z / t;
	return (result);
}

t_point3	point_multiply_scala(t_point3 point, double t)
{
	point.x *= t;
	point.y *= t;
	point.z *= t;
	return (point);
}
