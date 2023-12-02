/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:27 by seoson            #+#    #+#             */
/*   Updated: 2023/12/02 20:52:09 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	printf("color : %d\n", color);
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
	scene->canvas = canvas(WIDTH,HEIGHT);
	scene->camera = camera(&scene->canvas, point3(0,0,20));
	//objec추가 함수화하기
    world = object(SP, sphere(point3(-2, 0, -5), 2), color3(0.5, 0, 0)); // world 에 구1 추가
    oadd(&world, object(SP, sphere(point3(0, -1000, 0), 995), color3(1, 1, 1))); // world 에 구3 추가
    oadd(&world, object(SP, sphere(point3(2, 1, -5), 2), color3(1, 0.5, 0))); // world 에 구2 추가
	// oadd(&world, object(PL, plane(vec3(0.0,0.0,-1.0), point3(0.0,0.0,-10.0), color3(0,0,0.5)), color3(0.5,0,0)));
    scene->world = world;
   	lights = object(LIGHT_POINT, light_point(point3(0, 3, 0), color3(1, 1, 1), 0.7), color3(0, 0, 0)); // 더미 albedo
    scene->light = lights;
	ka = 0.1;
	scene->ambient = color_multiply_scala(scene->ambient, ka);
	return (scene);
}


int	write_color(t_color3 pixel_color)
{
	int	color;

	color = 0;
	color += pixel_color.r * (int)255.999;
	color <<= 16;
	color += pixel_color.g * (int)255.999;
	color <<= 8;
	color += pixel_color.b * (int)255.999;
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
    // j = scene->canvas.height - 1;
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
		// j--;
	}
	mlx_put_image_to_window(scene->mlx, scene->mlx_win, scene->img.img, 0, 0);
	mlx_loop(scene->mlx);
    return (0);
}
