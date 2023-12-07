/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:48:07 by seoson            #+#    #+#             */
/*   Updated: 2023/12/07 11:48:38 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../main.h"

int	key_hook(int keycode, t_scene *scene)
{
	if (keycode == ESC_CODE)
		before_exit(scene);
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIDTH || y < 0 || y >= HEIGHT)
		return ;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	write_color(t_color3 pixel_color)
{
	int	color;

	color = (int)(pixel_color.r * 255.999) << 16;
	color |= (int)(pixel_color.g * 255.999) << 8;
	color |= (int)(pixel_color.b * 255.999);
	return (color);
}
