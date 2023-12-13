/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_utils_vector.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:58:12 by Sungho            #+#    #+#             */
/*   Updated: 2023/12/12 20:39:44 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector3	vector_plus_vector(t_vector3 vec, t_vector3 vec2)
{
    vec.x += vec2.x;
    vec.y += vec2.y;
    vec.z += vec2.z;
    return (vec);
}

t_vector3	vector_minus_vector(t_vector3 vec, t_vector3 vec2)
{
    vec.x -= vec2.x;
    vec.y -= vec2.y;
    vec.z -= vec2.z;
    return (vec);
}

t_vector3	vector_multiply_vector(t_vector3 vec, t_vector3 vec2)
{
    vec.x *= vec2.x;
    vec.y *= vec2.y;
    vec.z *= vec2.z;
    return (vec);
}

t_point3   vector_plus_point(t_vector3 vector, t_point3 point)
{
    t_point3   res;

    res.x = vector.x + point.x;
    res.y = vector.y + point.y;
    res.z = vector.z + point.z;
    return (res);
}
