/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 12:38:08 by seoson            #+#    #+#             */
/*   Updated: 2023/04/23 14:46:31 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrchr(const char *s, int c)
{
	char	*casting;
	int		i;
	int		save;

	casting = (char *)s;
	i = 0;
	save = -1;
	while (casting[i])
	{
		if (casting[i] == (char)c)
			save = i;
		i++;
	}
	if ((unsigned char)c == 0)
		return (&casting[i]);
	if (save != -1)
		return (&casting[save]);
	else
		return (0);
}
