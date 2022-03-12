/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:51:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/13 04:03:18 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_result(t_list *elem)
{
	int		len;

	len = 0;
	while (((char *)elem->content)[len])
		len++;
	write(1, elem->content, len);
	write(1, "\n", 1);
}
t_list	*ft_lstnewone(void *content)
{
	t_list	*elem;
	elem = (t_list *)malloc(sizeof(t_list));
	if (!elem)
		return (NULL);
	if (!content)
		elem->content = NULL;
	else
		elem->content = content;
	elem->next = NULL;
	return (elem);
}

int main(int argc, const char *argv[])
{
	t_list		*begin;
	t_list		*elem;
	t_list		*elem2;
	t_list		*elem3;
	t_list		*elem4;

	char		*str = strdup("lorem");
	char		*str2 = strdup("ipsum");
	char		*str3 = strdup("dolor");
	char		*str4 = strdup("sit");

	elem = ft_lstnewone(str);
	elem2 = ft_lstnewone(str2);
	elem3 = ft_lstnewone(str3);
	elem4 = ft_lstnewone(str4);
	alarm(5);
	if (argc == 1 || !elem || !elem2 || !elem3 || !elem4)
		return (0);
	else if (atoi(argv[1]) == 1)
	{
		begin = NULL;
		ft_lstadd_back(&begin, elem);
		ft_lstadd_back(&begin, elem2);
		ft_lstadd_back(&begin, elem3);
		ft_lstadd_back(&begin, elem4);
		while (begin)
		{
			ft_print_result(begin);
			begin = begin->next;
		}
	}
	return (0);
}
