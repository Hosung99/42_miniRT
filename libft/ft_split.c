/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:58:16 by seoson            #+#    #+#             */
/*   Updated: 2023/04/19 14:13:14 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int		i;
	int		save;
	int		flag;

	i = 0;
	save = 0;
	flag = 1;
	while (s[i])
	{
		if (s[i] != c && flag)
		{
			flag = 0;
			save++;
		}
		if (s[i] == c)
			flag = 1;
		i++;
	}
	return (save);
}

static int	len_word(char const *s, char c)
{
	int	save;

	save = 0;
	while (*s)
	{
		if (*s != c)
		{
			s++;
			save++;
		}
		else
			break ;
	}
	return (save);
}

static void	set_string(char **str, const char **s, \
		int word_len)
{
	int	k;

	k = 0;
	while (k < word_len)
	{
		(*str)[k++] = **s;
		*s = *s + 1;
	}
}

static char	**free_malloc(char **str, int i)
{
	while (i)
		free(str[--i]);
	free(str);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		word_cnt;
	char	**str;

	i = 0;
	word_cnt = count_word(s, c);
	str = (char **)malloc(sizeof(char *) * (word_cnt + 1));
	if (!str)
		return (0);
	str[word_cnt] = 0;
	while (word_cnt--)
	{
		while (*s && *s == c)
			s++;
		str[i] = (char *)malloc(sizeof(char) * (len_word(s, c) + 1));
		if (!str[i])
			return (free_malloc(str, i));
		str[i][len_word(s, c)] = 0;
		set_string(&str[i++], &s, len_word(s, c));
	}
	return (str);
}
