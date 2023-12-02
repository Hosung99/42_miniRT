/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:27:52 by marvin            #+#    #+#             */
/*   Updated: 2023/12/02 17:13:46 by seoson           ###   ########.fr       */
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

t_ray     ray(t_point3 orig, t_vector3 dir);
t_point3    ray_at(t_ray *ray, double t);
t_ray	ray_primary(t_camera *camera, double u, double v); //가장 처음 카메라에서 출발한ray
t_color3	ray_color(t_scene *scene);
int		hit(t_object *obj, t_ray *ray, t_hit_record *rec);
int		hit_obj(t_object *obj, t_ray *ray, t_hit_record *rec);
int	in_shadow(t_object *obj, t_ray light_ray, double light_ren);
t_color3	point_light_get(t_scene *scene, t_light *light);
t_color3	phong_lightning(t_scene *scene);
double	hit_sphere(t_object *sp, t_ray *ray, t_hit_record *rec);

t_canvas	canvas(int  width, int height);
t_camera	camera(t_canvas *canvas, t_point3 origin);
t_sphere	*sphere(t_point3 center, double radius);
t_plane		*plane(t_vector3 dir, t_point3 point, t_color3 color);
t_object	*object(int type, void *element, t_color3 albedo);
t_light		*light_point(t_point3 light_origin, t_color3 light_color, double bright_ratio);

int    write_color(t_color3 pixel_color);

#endif
