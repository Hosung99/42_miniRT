/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:31:53 by seoson            #+#    #+#             */
/*   Updated: 2023/12/02 14:37:12 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector3	vec3(double x, double y, double z)
{
    t_vector3	vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}

t_point3	point3(double x, double y, double z)
{
    t_point3	point;

    point.x = x;
    point.y = y;
    point.z = z;
    return (point);
}

t_color3	color3(double r, double g, double b)
{
    t_color3	color;

    color.r = r;
    color.g = g;
    color.b = b;
    return (color);
}
