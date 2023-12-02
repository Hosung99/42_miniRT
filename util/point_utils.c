/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:03:45 by seoson            #+#    #+#             */
/*   Updated: 2023/12/02 15:04:31 by seoson           ###   ########.fr       */
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

t_point3	point_multiply_scala(t_point3 vec, double t)
{
	vec.x *= t;
	vec.y *= t;
	vec.z *= t;
	return (vec);
}
