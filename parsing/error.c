/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:17:01 by sgo               #+#    #+#             */
/*   Updated: 2023/12/13 19:57:39 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_wrong_input(void)
{
	printf("Error\n");
	printf("enter input in the following format ./miniRT [file_name].rt\n");
	exit(1);
}

void	error_open_file(void)
{
	printf("Error\n");
	printf("file does not exist\n");
	exit(1);
}

void	error_malloc(void)
{
	printf("Error\n");
	printf("malloc failed\n");
	exit(1);
}

void	wrong_double_input(void)
{
	printf("Error\n");
	printf("wrong double type input\n");
	exit(1);
}

void	wrong_range(int type)
{
	if (type == RATIO)
		printf("Error\nyou must set ratio in range [0.0, 1.0]\n");
	if (type == COLOR)
		printf("Error\nyou must set color in range [0.0, 255.0]\n");
	if (type == VECTOR)
		printf("Error\nyou must set vector in range [-1.0, 1.0]\n");
	if (type == FOV)
		printf("Error\nyou must set fov in range [0.0, 180.0]\n");
	exit(1);
}
