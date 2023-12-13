/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:55:34 by seoson            #+#    #+#             */
/*   Updated: 2023/12/13 01:17:37 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*casting;
	int		i;
	
	if (!s)
		return (0);
	casting = (char *)s;
	i = 0;
	while (casting[i])
	{
		if (casting[i] == (char)c)
			return (&casting[i]);
		i++;
	}
	if (casting[i] == (char)c)
		return (&casting[i]);
	else
		return (0);
}
