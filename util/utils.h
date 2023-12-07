#ifndef UTILS_H
# define UTILS_H

#include "../main.h"

t_vector3	vec3(double x, double y, double z);
t_vector3	vector_plus_vector(t_vector3 vec, t_vector3 vec2);
t_vector3	vector_multiply_vector(t_vector3 vec, t_vector3 vec2);
t_vector3	vector_multiply_scala(t_vector3 vec, double t);
t_vector3	vector_plus_scala(t_vector3 vec, double x, double y, double z);
t_vector3	vector_minus_vector(t_vector3 vec, t_vector3 vec2);
t_vector3	vector_minus_scala(t_vector3 vec, double x, double y, double z);
t_vector3	vector_normalize(t_vector3 vec);
double		vector_dot(t_vector3 vec, t_vector3 vec2);
t_vector3   vector_cross(t_vector3 vec1, t_vector3 vec2);
double		vector_length(t_vector3 vec);
double		vector_length_double(t_vector3 vec);

t_color3    color3(double r, double g, double b);
t_color3	color_plus_color(t_color3 vec, t_color3 vec2);
t_color3	color_multiply_scala(t_color3 color1, double t);
t_color3    color_multiply_color(t_color3 color1, t_color3 color2);
t_color3	color_min(t_color3 color1,  t_color3 color2);
t_point3	point3(double x, double y, double z);
t_point3	point_plus_point(t_point3 vec, t_point3 vec2);
t_point3	point_minus_point(t_point3 vec, t_point3 vec2);
t_point3	point_multiply_scala(t_point3 vec, double t);
t_object	*olast(t_object *list);
void		oadd(t_object **list, t_object *new);

#endif
