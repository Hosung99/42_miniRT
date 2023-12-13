/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 03:04:01 by sgo               #+#    #+#             */
/*   Updated: 2023/12/13 11:16:18 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_cylinder(t_scene *scene, char **array, int *id)
{
	char	**center;
	char	**vector;
	char	**rgb;
	t_object	*world;

	if (array_len(array) != 6)
		error_invalid_input(OTHER);
	center = ft_split(array[1], ',');
	if (array_len(center) != 3)
		error_invalid_input(VECTOR);
	vector = ft_split(array[2], ',');
	rgb = ft_split(array[5], ',');
	check_rgb(rgb);
	check_vector(vector);
	world = object(CY, cylinder(point3(ft_stod(center[0]), ft_stod(center[1]), ft_stod(center[2])), \
			vec3(ft_stod(vector[0]), ft_stod(vector[1]), ft_stod(vector[2])), \
			ft_stod(array[3]), ft_stod(array[4])), \
			color3(ft_stod(rgb[0]) / 255, ft_stod(rgb[1]) / 255, ft_stod(rgb[2]) / 255), *id++);
	if (scene->world == NULL)
		scene->world = world;
	else
		oadd(&scene->world, world);
	free_array(center);
	free_array(vector);
	free_array(rgb);
}
