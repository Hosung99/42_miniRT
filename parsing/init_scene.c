/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:37:28 by sgo               #+#    #+#             */
/*   Updated: 2023/12/14 10:23:28 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	set_scene_null(t_scene *scene)
{
	scene->world = NULL;
	scene->light = NULL;
	scene->mlx = NULL;
	scene->mlx_win = NULL;
}

t_scene *init_scene(char *argv[])
{
	int 	fd;
	char 	*line;
	int 	id;
	t_scene *scene;

	id = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error_open_file();
	scene = (t_scene *)malloc(sizeof(t_scene));
	set_scene_null(scene);
	line = get_next_line(fd);
	while (line)
	{
		if (line[0] == '\n' || line[0] == '\0')
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		line = ft_strtrim(line, "\n");
		set_by_type(scene, line, &id);
		free(line);
		line = get_next_line(fd);
	}
	return (scene);
}

void	set_by_type(t_scene *scene, char *line, int *id)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!ft_strncmp(split[0], "A", 2))
		set_ambient(scene, split);
	else if (!ft_strncmp(split[0], "C", 2))
		set_camera(scene, split);
	else if (!ft_strncmp(split[0], "L", 2))
		set_light(scene, split, id);
	else if (!ft_strncmp(split[0], "sp", 3))
		set_sphere(scene, split, id);
	else if (!ft_strncmp(split[0], "pl", 3))
		set_plane(scene, split, id);
	else if (!ft_strncmp(split[0], "cy", 3))
		set_cylinder(scene, split, id);
	else
		error_invalid_input(OTHER);
	free_array(split);
}
