/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 00:12:35 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/14 00:42:42 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cur;

	new = ft_lstnew(func(lst->content));
	cur = new;
	lst = lst->next;
	while (lst)
	{
		func(lst->content);
		cur->next = ft_lstnew(func(lst->content));
		cur = cur->next;
		if (cur == NULL)
		{
			del(cur->content);
			free(cur);
			return (NULL);
		}
		lst = lst->next;
	}
	return (new);
}
