/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 09:17:32 by seoson            #+#    #+#             */
/*   Updated: 2023/04/08 19:21:56 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*destination;
	const unsigned char	*source;
	size_t				i;

	destination = dst;
	source = src;
	if (dst == 0 && src == 0)
		return (0);
	if (destination <= source)
	{
		i = -1;
		while (++i < len)
			destination[i] = source[i];
	}
	else
	{
		i = len + 1;
		while (--i > 0)
			destination[i - 1] = source[i - 1];
	}
	return (dst);
}
