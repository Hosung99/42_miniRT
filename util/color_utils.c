/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:57:28 by seoson            #+#    #+#             */
/*   Updated: 2023/12/02 14:59:13 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color3	color_plus_color(t_color3 vec, t_color3 vec2)
{
    vec.r += vec2.r;
    vec.g += vec2.g;
    vec.b += vec2.b;
    return (vec);
}

t_color3	color_multiply_scala(t_color3 vec, double t)
{
	vec.r *= t;
	vec.g *= t;
	vec.b *= t;
	return (vec);
}

t_color3	color_min(t_color3 color1,  t_color3 color2)
{
    if (color1.r > color2.r)
        color1.r = color2.r;
    if (color1.g > color2.g)
        color1.g = color2.g;
    if (color1.b > color2.b)
        color1.b = color2.b;
    return (color1);
}
