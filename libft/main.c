/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:51:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/20 21:30:26 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	func(unsigned int i, char *c)
{
	*c += i;
}

int	main(void)
{
	char	str[] = "aaaaaa";

	ft_striteri(str, *func);
	printf("%s\n", str);

	
	/*
	char *s1 = "\t   \n\n\n  \n\n\t    Hello \t  Please\n Trim me !\t\t\t\n  \t\t\t\t  ";
    char *s2 = "Hello \t  Please\n Trim me !";
	char *s3;

	s3 = ft_strtrim(s1, " \n\t");
	printf("%s\n", s3);
	printf("%zu, %zu \n", ft_strlen(s3), ft_strlen(s2));


	//trimstr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	*/
}
