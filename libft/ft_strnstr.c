/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 14:49:50 by seoson            #+#    #+#             */
/*   Updated: 2023/04/19 14:05:48 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_correct(unsigned char *haystack, unsigned char *needle, \
		size_t len, size_t index)
{
	size_t		i;

	i = 0;
	while (i < len && needle[i])
	{
		if (haystack[index++] != needle[i++])
			return (0);
	}
	if (needle[i] != '\0' || index > len)
		return (0);
	else
		return (1);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned char	*hs_casting;
	unsigned char	*needle_casting;
	size_t			i;
	size_t			flag;

	hs_casting = (unsigned char *)haystack;
	needle_casting = (unsigned char *)needle;
	i = 0;
	flag = 0;
	if (needle_casting[0] == '\0')
		return ((char *)haystack);
	while (i < len && hs_casting[i])
	{
		if (hs_casting[i] == needle_casting[0])
			flag = word_correct(hs_casting, needle_casting, len, i);
		if (flag)
			return ((char *)&haystack[i]);
		i++;
	}
	return (0);
}
