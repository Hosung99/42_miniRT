/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:38:24 by seoson            #+#    #+#             */
/*   Updated: 2023/12/02 15:05:12 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_vector3	vector_normalize(t_vector3 vec)
{
    double	len;

	len = vector_length(vec);
    if (len == 0)
    {
        printf("Error\n:Devider is 0");
        exit(0);
    }
    vec.x /= len;
    vec.y /= len;
    vec.z /= len;
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
