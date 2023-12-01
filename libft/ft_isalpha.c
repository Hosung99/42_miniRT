/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/14 15:21:38 by seoson            #+#    #+#             */
/*   Updated: 2023/04/08 19:02:59 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isupper(int c)
{
	if (c >= 65 && c <= 90)
		return (1);
	else
		return (0);
}

static int	ft_islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}

int	ft_isalpha(int c)
{
	int	check_upper;
	int	check_lower;

	check_upper = ft_isupper(c);
	check_lower = ft_islower(c);
	if (check_upper || check_lower)
		return (1);
	else
		return (0);
}
