/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 13:36:41 by seoson            #+#    #+#             */
/*   Updated: 2023/03/28 12:10:10 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*casting1;
	unsigned char	*casting2;
	size_t			i;

	casting1 = (unsigned char *)s1;
	casting2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (casting1[i] != casting2[i])
			return (casting1[i] - casting2[i]);
		i++;
	}
	return (0);
}
