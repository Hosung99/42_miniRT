/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:27:08 by seoson            #+#    #+#             */
/*   Updated: 2023/04/23 14:46:59 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	const unsigned char	*source;
	unsigned char		*destination;
	size_t				i;

	source = src;
	destination = dst;
	i = 0;
	if (!src && !dst)
		return (0);
	while (i < n)
	{
		destination[i] = source[i];
		i++;
	}
	return (dst);
}
