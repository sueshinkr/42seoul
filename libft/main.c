/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:51:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/24 01:25:39 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*func)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*func)(void *), void (*del)(void *));

static void	*func(void *content)
{
	int		i;
	char	*temp;

	temp = (char *)content;
	while (temp[i])
		temp[i++] += 1;
	return (temp);
}

static void	del(void *content)
{
	free(content);
}

int	main(void)
{
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;
	t_list	*newlist;

	list1 = ft_lstnew(ft_strdup("abcde"));
	list2 = ft_lstnew(ft_strdup("12345"));
	list3 = ft_lstnew(ft_strdup("!@#$"));
	list1->next = list2;
	list2->next = list3;

	newlist = ft_lstmap(list1, &func, &del);
	while (newlist)
	{
		printf("%s\n", (char *)newlist->content);
		newlist = newlist->next;
	}
}
