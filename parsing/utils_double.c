/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_double.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 02:27:14 by sgo               #+#    #+#             */
/*   Updated: 2023/12/13 20:07:42 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	check_dot(char *str)
{
	int	i;
	int	dot;

	i = 0;
	dot = 0;
	while (str[i])
	{
		if (str[i] == '.')
			dot++;
		i++;
	}
	if (dot > 1)
		return (1);
	return (0);
}

int	array_len(char **array)
{
	int i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

int	check_range_color(double color)
{
	if (color < 0.0 || color > 1.0)
		return (1);
	return (0);
}

double	ft_stod(char *str)
{
	int		sign;
	double	natural_num;
	double	decimal_num;
	char	**split;

	sign = 1;
	if (check_dot(str))
		wrong_double_input();
	split = ft_split(str, '.');
	natural_num = ft_atol(split[0]);
	printf("sgotest natural num %f\n", natural_num);
	if (array_len(split) == 1)
	{
		free_array(split);
		return (natural_num * sign);
	}
	decimal_num = ft_atol(split[1]);
	if (decimal_num < 0)
		wrong_double_input();
	decimal_num /= pow(10, ft_strlen(split[1]));
	free_array(split);
	return ((natural_num + decimal_num) * sign);
}

long long	ft_atol(char *str)
{
	int			sign;
	long long	num;
	int			i;

	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	num = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			error_invalid_input(OTHER);
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}
