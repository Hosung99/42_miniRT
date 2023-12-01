/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 19:29:32 by seoson            #+#    #+#             */
/*   Updated: 2023/04/19 14:04:43 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long	calc_len(long long save, int *len)
{
	long long	temp;

	temp = save;
	if (save < 0)
	{
		save *= -1;
		*len = *len + 1;
		temp = save;
	}
	if (save == 0)
	{
		*len = *len + 1;
		return (0);
	}
	while (save)
	{
		save = save / 10;
		*len = *len + 1;
	}
	return (temp);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	long long	save;
	int			i;

	len = 0;
	save = (long long)n;
	i = 0;
	save = calc_len(save, &len);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = 0 + '0';
	if (n < 0)
		str[0] = '-';
	str[len--] = 0;
	while (save)
	{
		str[len--] = (save % 10) + '0';
		save = save / 10;
	}
	return (str);
}
