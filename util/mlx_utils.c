/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 11:48:07 by seoson            #+#    #+#             */
/*   Updated: 2023/12/12 11:58:44 by Sungho           ###   ########.fr       */
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

int	before_exit(t_scene *scene)
{
	mlx_destroy_image(scene->mlx, scene->img.img);
	mlx_destroy_window(scene->mlx, scene->mlx_win);
	exit(0);
}

void	free_all(t_scene *scene)
{
	t_object	*world_temp;
	t_object	*light_temp;

	world_temp = scene->world;
	while(scene->world)
	{
		free(world_temp->element);
		scene->world = scene->world->next;
		free(world_temp);
		world_temp = scene->world;
	}
	light_temp = scene->light;
	while(scene->light)
	{
		free(light_temp->element);
		scene->light = scene->light->next;
		free(light_temp);
		light_temp = scene->light;
	}
	free(scene);
}
