/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:57:28 by seoson            #+#    #+#             */
/*   Updated: 2023/12/04 12:00:49 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_color3	color_plus_color(t_color3 color1, t_color3 color2)
{
    color1.r += color2.r;
    color1.g += color2.g;
    color1.b += color2.b;
    return (color1);
}

t_color3	color_multiply_scala(t_color3 color, double t)
{
	color.r *= t;
	color.g *= t;
	color.b *= t;
	return (color);
}

t_color3    color_multiply_color(t_color3 color1, t_color3 color2)
{
    color1.r *= color2.r;
    color1.g *= color2.g;
    color1.b *= color2.b;
    return (color1);
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
