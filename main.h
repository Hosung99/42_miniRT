/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:27:52 by marvin            #+#    #+#             */
/*   Updated: 2023/12/13 18:10:28 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include "structures.h"
# include "./util/utils.h"
# include "./libft/libft.h"

# define TRUE 1
# define FALSE 0
# define SP 1
# define PL 2
# define CY 3
# define LIGHT_POINT 1
# define EPSILON 1e-6
# define LUMEN 2
# define WIDTH 1280
# define HEIGHT 720
# define ESC_CODE 53

t_ray		ray(t_point3 orig, t_vector3 dir);
t_point3	ray_at(t_ray *ray, double t);
t_ray		ray_primary(t_camera *camera, double u, double v); //가장 처음 카메라에서 출발한ray
t_color3	ray_color(t_scene *scene);
int	hit(t_object *world, t_ray *ray, t_hit_record *rec);
int			hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
int			hit_sphere(t_object *sp, t_ray *ray, t_hit_record *rec);
int			hit_plane(t_object *world, t_ray *ray, t_hit_record *rec);
int			hit_cylinder(t_object	*world, t_ray *ray, t_hit_record *rec);

t_color3	point_light_get(t_scene *scene, t_light *light);
t_color3	phong_lightning(t_scene *scene);
int	in_shadow(t_scene *scene, t_ray light_ray, double light_ren);

t_canvas	canvas(int width, int height, double fov);
t_camera	camera(t_canvas *canvas, t_point3 origin);
t_sphere	*sphere(t_point3 center, double radius);
t_plane		*plane(t_vector3 dir, t_point3 point);
t_cylinder	*cylinder(t_point3 center, t_vector3 dir, double radius, double height);
t_object *object(int type, void *element, t_color3 albedo, int id);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

int			write_color(t_color3 pixel_color);
int			key_hook(int keycode, t_scene *scene);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);
int			before_exit(t_scene *scene);

void		check_input(int argc, char *argv[]);
t_scene 	*init_scene(char *argv[]);

#endif
