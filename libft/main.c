/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:51:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/22 20:00:25 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	t_list	*start;
	t_list	*list1;
	t_list	*list2;
	t_list	*list3;

	list1 = ft_lstnew("abcde");
	list2 = ft_lstnew("12345");
	list3 = ft_lstnew("!@#$");
	start = NULL;

	ft_lstadd_back(&start, list1);
	printf("%s\n", (char *)ft_lstlast(start)->content);
	ft_lstadd_back(&start, list2);
	printf("%s\n", (char *)ft_lstlast(start)->content);
	ft_lstadd_back(&start, list3);
	printf("%s\n", (char *)ft_lstlast(start)->content);
}
