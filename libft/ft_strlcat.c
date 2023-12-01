/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 11:02:51 by seoson            #+#    #+#             */
/*   Updated: 2023/04/19 14:05:22 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	length_src(const char *restrict src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		i++;
	}
	return (i);
}

static size_t	length_dest(char *restrict dst)
{
	size_t	i;

	i = 0;
	while (dst[i])
	{
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	initial_dest_len;
	size_t	i;

	dest_len = length_dest(dst);
	src_len = length_src(src);
	initial_dest_len = dest_len;
	i = 0;
	if (dstsize == 0)
		return (src_len);
	if (dest_len > dstsize)
		return (src_len + dstsize);
	while (i + initial_dest_len + 1 < dstsize && src[i])
	{
		dst[dest_len] = src[i++];
		dest_len++;
	}
	dst[dest_len] = '\0';
	return (initial_dest_len + src_len);
}
