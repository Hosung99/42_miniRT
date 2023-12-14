/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:11:43 by sgo               #+#    #+#             */
/*   Updated: 2023/12/13 19:39:55 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_fileName(char *fileName)
{
	int	len;

	if (!fileName)
		return (0);
	len = ft_strlen(fileName);
	if (len < 4)
		return (0);
	if (ft_strncmp(fileName + len - 3, ".rt", 3) == 0)
		return (1);
	return (0);	
}

void	check_input(int argc, char *argv[])
{
	if (argc != 2)
		error_wrong_input();
	if (!check_fileName(argv[1]))
		error_wrong_input();
}

void	check_rgb(char **rgb)
{
	if (array_len(rgb) != 3)
		error_invalid_input(COLOR);
	if (check_range_color(ft_stod(rgb[0]) / 255) || \
		check_range_color(ft_stod(rgb[1]) / 255) || \
		check_range_color(ft_stod(rgb[2]) / 255))
		wrong_range(COLOR);
}

int	check_range_vector(double vector)
{
	if (vector < -1 || vector > 1)
		return (1);
	return (0);
}

void	check_vector(char **vector)
{
	if (array_len(vector) != 3)
		error_invalid_input(VECTOR);
	if (check_range_vector(ft_stod(vector[0])) || \
		check_range_vector(ft_stod(vector[1])) || \
		check_range_vector(ft_stod(vector[2])))
		wrong_range(VECTOR);
}
