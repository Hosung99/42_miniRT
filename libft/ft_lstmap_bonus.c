/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoson <seoson@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:25:00 by seoson            #+#    #+#             */
/*   Updated: 2023/04/13 16:19:32 by seoson           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*start;
	void	*temp_f;

	if (del == 0 || f == 0 || !lst)
		return (0);
	start = NULL;
	while (lst)
	{
		temp_f = f(lst->content);
		temp = ft_lstnew(temp_f);
		if (!temp)
		{
			free(temp_f);
			ft_lstclear(&start, del);
			return (0);
		}
		ft_lstadd_back(&start, temp);
		lst = lst->next;
	}
	return (start);
}
