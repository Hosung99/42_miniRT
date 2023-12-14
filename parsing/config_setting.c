/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_setting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:59:23 by sgo               #+#    #+#             */
/*   Updated: 2023/12/14 13:26:38 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_ambient(t_scene *scene, char **array)
{
	char	**rgb;
	
	if (array_len(array) != 3)
		error_invalid_input(OTHER);
	rgb = ft_split(array[2], ',');
	if (array_len(rgb) != 3)
		error_invalid_input(COLOR);
	scene->ambient_ratio = ft_stod(array[1]);
	if (check_range_color(scene->ambient_ratio))
		wrong_range(RATIO);
	if (check_range_color(ft_stod(rgb[0]) / 255) || \
		check_range_color(ft_stod(rgb[1]) / 255) || \
		check_range_color(ft_stod(rgb[2]) / 255))
		wrong_range(COLOR);
	scene->ambient = color_multiply_scala(\
		color3(ft_stod(rgb[0]) / 255, ft_stod(rgb[1]) / 255, ft_stod(rgb[2]) / 255), \
		scene->ambient_ratio);
	free_array(rgb);
}

void	set_camera(t_scene *scene, char **array)
{
	char	**point;
	char	**vector;
	double	fov;

	if (array_len(array) != 4)
		error_invalid_input(OTHER);
	point = ft_split(array[1], ',');
	if (array_len(point) != 3)
		error_invalid_input(VECTOR);
	vector = ft_split(array[2], ',');
	check_vector(vector);
	fov = ft_stod(array[3]);
	if (fov < 0 || fov > 180)
		wrong_range(FOV);
	scene->canvas = canvas(WIDTH, HEIGHT, fov);
    scene->camera = camera(&scene->canvas, \
	point3(ft_stod(point[0]), ft_stod(point[1]), ft_stod(point[2])), \
	vec3(ft_stod(vector[0]), ft_stod(vector[1]), ft_stod(vector[2])));
}

void	add_light(t_scene *scene, char **light_p, char *ratio, char **rgb, int *id)
{
	t_object	*obj;

	obj = object(LIGHT_POINT, light_point(\
			point3(ft_stod(light_p[0]), ft_stod(light_p[1]), ft_stod(light_p[2])),\
			color3(ft_stod(rgb[0]) / 255, ft_stod(rgb[1]) / 255, ft_stod(rgb[2]) / 255), \
			ft_stod(ratio)), \
			color3(0, 0, 0), (*id)++);
	if (scene->light == NULL)
		scene->light = obj;
	else
		oadd(&scene->light, obj);
}

void	set_light(t_scene *scene, char **array, int *id)
{
	char	**light_point;
	char	**rgb;

	if (array_len(array) != 4)
		error_invalid_input(OTHER);
	light_point = ft_split(array[1], ',');
	if (array_len(light_point) != 3)
		error_invalid_input(VECTOR);
	rgb = ft_split(array[3], ',');
	check_rgb(rgb);
	if (check_range_color(ft_stod(array[2])))
		wrong_range(RATIO);
	if (array_len(rgb) != 3)
		error_invalid_input(COLOR);
	if (check_range_color(ft_stod(rgb[0]) / 255) || \
		check_range_color(ft_stod(rgb[1]) / 255) || \
		check_range_color(ft_stod(rgb[2]) / 255))
		wrong_range(COLOR);
	add_light(scene, light_point, array[2], rgb, id);
}
