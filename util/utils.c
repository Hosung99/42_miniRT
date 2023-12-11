/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dang-geun <dang-geun@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:38:24 by seoson            #+#    #+#             */
/*   Updated: 2023/12/09 21:02:47 by dang-geun        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector3	vector_normalize(t_vector3 vec)
{
    t_vector3  res;
    double	len;

	len = vector_length(vec);
    if (len == 0)
    {
        printf("Error\n:Devider is 0");
        exit(0);
    }
    // else if (len == 1)
    //     return (vec);
    res.x = vec.x / len;
    res.y = vec.y / len;
    res.z = vec.z / len;
    return (res);
}

t_vector3   vector_cross(t_vector3 vec1, t_vector3 vec2) //벡터 외적
{
    t_vector3   vec;

    vec.x = vec1.y * vec2.z - vec1.z * vec2.y;
    vec.y = vec1.z * vec2.x - vec1.x * vec2.z;
    vec.z = vec1.x * vec2.y - vec1.y * vec2.x;
    return (vec);
}

double	vector_dot(t_vector3 vec, t_vector3 vec2) //내적
{
    return (vec.x * vec2.x + vec.y * vec2.y + vec.z * vec2.z);
}

double	vector_length_double(t_vector3 vec) //벡터 크기의 제곱
{
    return (vec.x * vec.x + vec.y * vec.y + vec.z * vec.z);
}

double	vector_length(t_vector3 vec)
{
    return (sqrt(vector_length_double(vec)));
}
