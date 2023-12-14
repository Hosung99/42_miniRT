/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 02:39:12 by sgo               #+#    #+#             */
/*   Updated: 2023/12/13 18:10:44 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_plane(t_scene *scene, char **array, int *id)
{
	char	**point;
	char	**vector;
	char	**rgb;
	t_object	*world;

	if (array_len(array) != 4)
		error_invalid_input(OTHER);
	point = ft_split(array[1], ',');
	if (array_len(point) != 3)
		error_invalid_input(VECTOR);
	vector = ft_split(array[2], ',');
	if (array_len(vector) != 3)
		error_invalid_input(VECTOR);
	rgb = ft_split(array[3], ',');
	check_rgb(rgb);
	check_vector(vector);
	// todo 왜 plane은 color를 plane에 넣는가?
	world = object(PL, plane(vec3(ft_stod(vector[0]), ft_stod(vector[1]), ft_stod(vector[2])), \
			point3(ft_stod(point[0]), ft_stod(point[1]), ft_stod(point[2]))), \
			color3(ft_stod(rgb[0]) / 255, ft_stod(rgb[1]) / 255, ft_stod(rgb[2]) / 255), (*id)++);
	if (scene->world == NULL)
		scene->world = world;
	else
		oadd(&scene->world, world);
	free_array(point);
	free_array(vector);
	free_array(rgb);
}
