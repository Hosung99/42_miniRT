/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgo <sgo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:09:16 by seoson            #+#    #+#             */
/*   Updated: 2023/12/12 23:30:10 by sgo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char const *s1, char const *set, int index)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (s1[index] == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_front(char const *s1, char const *set)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (is_set(s1, set, i) == 0)
			break ;
		i++;
	}
	return (i);
}

static int	check_back(char const *s1, char const *set)
{
	int	i;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		if (is_set(s1, set, i) == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char *s1, char const *set)
{
	int		front_index;
	int		back_index;
	int		len;
	char	*str;
	int		i;

	if (ft_strlen(set) == 0 || ft_strlen(s1) == 0)
		return (ft_strdup(s1));
	front_index = check_front(s1, set);
	back_index = check_back(s1, set);
	len = back_index - front_index + 1;
	if (front_index > back_index)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (front_index <= back_index)
		str[i++] = s1[front_index++];
	str[i] = '\0';
	free(s1);
	s1 = NULL;
	return (str);
}
