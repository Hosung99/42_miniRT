/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 23:00:45 by sgo               #+#    #+#             */
/*   Updated: 2023/12/13 03:03:58 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_sphere(t_scene *scene, char **center, char *diameter, char **rgb, int *id)
{
	t_object	*world;

	world = object(SP, sphere(point3(ft_stod(center[0]), ft_stod(center[1]), ft_stod(center[2])), \
			ft_stod(diameter)), \
			color3(ft_stod(rgb[0]) / 255, ft_stod(rgb[1]) / 255, ft_stod(rgb[2]) / 255), (*id)++);
	if (scene->world == NULL)
		scene->world = world;
	else
		oadd(&scene->world, world);
}

void	set_sphere(t_scene *scene, char **array, int *id)
{
	char	**center;
	char	**rgb;

	if (array_len(array) != 4)
		error_invalid_input(OTHER);
	center = ft_split(array[1], ',');
	if (array_len(center) != 3)
		error_invalid_input(VECTOR);
	rgb = ft_split(array[3], ',');
	check_rgb(rgb);
	add_sphere(scene, center, array[2], rgb, id);
	free_array(center);
	free_array(rgb);
}
