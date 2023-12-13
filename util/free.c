/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 00:32:04 by sgo               #+#    #+#             */
/*   Updated: 2023/12/12 02:47:49 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	ft_free(char *tmp)
{
	if (tmp)
		free(tmp);
	tmp = NULL;
}

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		ft_free(array[i]);
		i++;
	}
	free(array);
	array = NULL;
}
