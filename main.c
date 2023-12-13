/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:27 by seoson            #+#    #+#             */
/*   Updated: 2023/12/13 20:33:53 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

t_scene	*scene_init(void)
{
	t_scene 	*scene;
	t_object	*world;
	t_object	*lights;
	int			id;

	scene = (t_scene *)malloc(sizeof(t_scene));
	if (!scene)
		exit(1);
	id = 0;
	scene->canvas = canvas(WIDTH, HEIGHT, 70);
    scene->camera = camera(&scene->canvas, point3(0, 0, 15), vec3(0,0,1));
    // world = object(SP, sphere(point3(0, 1, 0), 2), color3(0.5, 0, 0), id++); // world 에 구1 추가
	// world = object(SP, sphere(point3(0, -4, 2), 2), color3(0.5, 0, 0), id++);
    // oadd(&world, object(SP, sphere(point3(6, 1, 0), 2), color3(0, 0.5, 0))); // world 에 구2 추가
	// oadd(&world, object(PL, plane(vec3(1, 1, 0), point3(1, 1, 0), color3(1,1,1)), id++)); // world 에 평면 추가
	// world = object(CY, cylinder(point3(0,-3, 0), vec3(1, 1, 0), 1, 5), color3(0, 0, 0.5));
	// oadd(&world, object(CY, cylinder(point3(0, 0, 0), vec3(1, 0.1, 1), 1, 7), color3(0, 0, 0.5), id++));
	world = object(CY, cylinder(point3(0, 0, 0), vec3(1, 1, 1), 3, 5), color3(0, 0, 1), id++);
    scene->world = world;
	// oadd(&world, object(SP, sphere(point3(0, -3, 0), 1), color3(0, 0, 1), id++));
    lights = object(LIGHT_POINT, light_point(point3(0, 20, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0), id++);
	oadd(&lights, object(LIGHT_POINT, light_point(point3(10, 10, 0), color3(1, 1, 1), 0.5), color3(0, 0, 0), id++));
    scene->light = lights;
	scene->ambient_ratio = 0.1;
	scene->ambient = color_multiply_scala(color3(1,1,1), scene->ambient_ratio);
	return (scene);
}

// void	foo()
// {
// 	system("leaks miniRT");
// }

void	draw(t_scene *scene)
{
	int			i;
    int			j;
	double		u;
	double		v;
	t_color3	pixel_color;

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
}

int	main(void)
{
	t_scene		*scene;

	scene = scene_init();
	scene->mlx = mlx_init();
	scene->mlx_win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, "miniRT");
	scene->img.img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	scene->img.addr = mlx_get_data_addr(scene->img.img, &scene->img.bits_per_pixel, \
	&scene->img.line_length, &scene->img.endian);
	draw(scene);
	mlx_put_image_to_window(scene->mlx, scene->mlx_win, scene->img.img, 0, 0);
	mlx_key_hook(scene->mlx_win, key_hook, scene);
	mlx_hook(scene->mlx_win, 17, 0, before_exit, scene);
	mlx_loop(scene->mlx);
	free_all(scene);
	// atexit(foo);
    return (0);
}
