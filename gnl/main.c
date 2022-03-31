/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 13:55:33 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/31 18:59:52 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{	
	int	fd;

	fd = open("test.txt", O_RDONLY);
	printf("1 : %s:::\n", get_next_line(fd));
	printf("2 : %s:::\n", get_next_line(fd));
	printf("3 : %s:::\n", get_next_line(fd));
	printf("4 : %s:::\n", get_next_line(fd));
}
