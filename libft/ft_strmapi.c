/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 15:01:23 by seoson            #+#    #+#             */
/*   Updated: 2023/04/13 16:07:48 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*answer;
	unsigned int	i;
	int				len;

	i = 0;
	len = ft_strlen(s);
	answer = (char *)malloc(sizeof(char) * len + 1);
	if (!answer)
		return (0);
	while (s[i])
	{
		answer[i] = f(i, s[i]);
		i++;
	}
	answer[i] = 0;
	return (answer);
}
