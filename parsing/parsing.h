/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:18:30 by sgo               #+#    #+#             */
/*   Updated: 2023/12/13 19:58:03 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

#include "../main.h"

# define RATIO 1
# define COLOR 2
# define VECTOR 3
# define OTHER 4
# define FOV 5
void		error_wrong_input(void);
void		error_open_file(void);
void		error_malloc(void);
void		wrong_double_input(void);
void		wrong_range(int type);
void		error_invalid_input(int type);

int			check_fileName(char *fileName);
void		check_input(int argc, char *argv[]);
int			array_len(char **array);
double		ft_stod(char *str);
long long	ft_atol(char *str);
int			check_range_color(double color);
void		check_rgb(char **rgb);
void		check_vector(char **vector);

void		set_ambient(t_scene *scene, char **array);
void		set_camera(t_scene *scene, char **array);
void		set_light(t_scene *scene, char **array, int *id);
void		set_sphere(t_scene *scene, char **array, int *id);
void		set_plane(t_scene *scene, char **array, int *id);
void		set_cylinder(t_scene *scene, char **array, int *id);
void		set_by_type(t_scene *scene, char *line, int *id);

#endif