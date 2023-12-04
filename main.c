/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:27 by seoson            #+#    #+#             */
/*   Updated: 2023/12/04 20:19:02 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	before_exit(t_scene *scene)
{
	mlx_destroy_image(scene->mlx, scene->img.img);
	mlx_destroy_window(scene->mlx, scene->mlx_win);
	exit(0);
}

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

t_scene	*scene_init(void)
{
	t_scene 	*scene;
	t_object	*world;
	t_object	*lights;
	double		ka;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		return (NULL); //exit하도록 수정
	scene->canvas = canvas(WIDTH,HEIGHT,70);
	scene->camera = camera(&scene->canvas, point3(0,0,5));
	//objec추가 함수화하기
    world = object(SP, sphere(point3(-2, 1, -5), 2), color3(0.5, 0, 0)); // world 에 구1 추가
	oadd(&world, object(SP, sphere(point3(2, 1, -5), 2), color3(0, 0.5, 0))); // world 에 구2 추가
	oadd(&world, object(PL, plane(vec3(-1, -1, -1), point3(0, 0, 0), color3(0,0,1)), color3(0,0,1))); // world 에 평면 추가
    scene->world = world;
    lights = object(LIGHT_POINT, light_point(point3(0, 5, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0)); // 더미 albedo
    scene->light = lights;
	ka = 0.1;
	scene->ambient = color_multiply_scala(color3(1,1,1), ka);
	return (scene);
}


int	write_color(t_color3 pixel_color)
{
	int	color;

	color = (int)(pixel_color.r * 255.999) << 16;
	color |= (int)(pixel_color.g * 255.999) << 8;
	color |= (int)(pixel_color.b * 255.999);
	return (color);
}

int	main(void)
{
    int     i;
    int     j;
	double	u;
	double	v;
	t_color3    pixel_color;
	t_scene		*scene;

	scene = scene_init();
	scene->mlx = mlx_init();
	scene->mlx_win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, "miniRT");
	scene->img.img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	scene->img.addr = mlx_get_data_addr(scene->img.img, &scene->img.bits_per_pixel, \
	&scene->img.line_length, &scene->img.endian);
	j = 0;
	while (j < scene->canvas.height)
	{
		i = 0;
		while (i < scene->canvas.width)
		{
			u = (double)i / (scene->canvas.width - 1);
			v = (double)j / (scene->canvas.height - 1);
			scene->ray = ray_primary(&scene->camera, u, v);
			pixel_color = ray_color(scene);
			my_mlx_pixel_put(&(scene->img), i, j, write_color(pixel_color));
			++i;
		}
		++j;
	}
	mlx_put_image_to_window(scene->mlx, scene->mlx_win, scene->img.img, 0, 0);
	mlx_key_hook(scene->mlx_win, key_hook, scene);
	mlx_hook(scene->mlx_win, 17, 0, before_exit, scene);
	mlx_loop(scene->mlx);
    return (0);
}
