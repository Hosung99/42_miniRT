/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:59:33 by seoson            #+#    #+#             */
/*   Updated: 2023/04/13 15:48:18 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	s1_len;
	unsigned int	s2_len;
	char			*str;
	int				i;
	int				save;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	i = 0;
	save = 0;
	if (!str)
		return (0);
	while (s1[i])
		str[save++] = s1[i++];
	i = 0;
	while (s2[i])
		str[save++] = s2[i++];
	str[s1_len + s2_len] = '\0';
	return (str);
}
