/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:51:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/14 00:10:21 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


int main(void)
{

	char	*str = "01234";
	size_t	size = 10;
	char	*ret = ft_substr(str, 10, size);
	//char	*ret2 = substr(str, 10, size);
	printf("%s \n", ret);
}
