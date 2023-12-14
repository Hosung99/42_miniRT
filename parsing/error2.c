/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 01:21:34 by sgo               #+#    #+#             */
/*   Updated: 2023/12/13 01:26:58 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	error_invalid_input(int type)
{
	if (type == COLOR)
		ft_putstr_fd("Error\nInvalid color input\n", 2);
	else if (type == RATIO)
		ft_putstr_fd("Error\nInvalid ratio input\n", 2);
	else if (type == VECTOR)
		ft_putstr_fd("Error\nInvalid vector input\n", 2);
	else
		ft_putstr_fd("Error\nInvalid input\n", 2);
	exit(1);
}
