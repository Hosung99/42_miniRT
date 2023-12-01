/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:55:34 by seoson            #+#    #+#             */
/*   Updated: 2023/04/23 14:07:19 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*casting;
	int		i;

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
