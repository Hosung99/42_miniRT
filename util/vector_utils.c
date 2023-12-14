/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:37:32 by seoson            #+#    #+#             */
/*   Updated: 2023/12/13 21:00:20 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector3	vector_plus_scala(t_vector3 vec, double x, double y, double z)
{
    vec.x += x;
    vec.y += y;
    vec.z += z;
    return (vec);
}

t_vector3   vector_minus_point(t_vector3 vec, t_point3 point)
{
    t_vector3   res;

    res.x = vec.x - point.x;
    res.y = vec.y - point.y;
    res.z = vec.z - point.z;
    return (res);
}

t_vector3   point_minus_vector(t_point3 point, t_vector3 vec)
{
    t_vector3   res;

    res.x = point.x - vec.x;
    res.y = point.y - vec.y;
    res.z = point.z - vec.z;
    return (res);
}

t_vector3	vector_minus_scala(t_vector3 vec, double x, double y, double z)
{
    vec.x -= x;
    vec.y -= y;
    vec.z -= z;
    return (vec);
}

t_vector3	vector_multiply_scala(t_vector3 vec, double t)
{
    vec.x *= t;
    vec.y *= t;
    vec.z *= t;
    return (vec);
}

t_vector3   vector_divide_scala(t_vector3 vec, double t)
{
    vec.x /= t;
    vec.y /= t;
    vec.z /= t;
    return (vec);
}
