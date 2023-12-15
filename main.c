/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Sungho <Sungho@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 14:22:27 by seoson            #+#    #+#             */
/*   Updated: 2023/12/15 14:19:12 by Sungho           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

// void	foo()
// {
// 	system("leaks miniRT");
// }

int	main(int argc, char *argv[])
{
	t_scene	*scene;

	check_input(argc, argv);
	scene = init_scene(argv);
	scene->mlx = mlx_init();
	scene->mlx_win = mlx_new_window(scene->mlx, WIDTH, HEIGHT, "miniRT");
	scene->img.img = mlx_new_image(scene->mlx, WIDTH, HEIGHT);
	scene->img.addr = mlx_get_data_addr\
		(scene->img.img, &scene->img.bits_per_pixel, \
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
