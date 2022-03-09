/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:51:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/09 20:20:49 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_strlen(const char *s);
void	*ft_memset(void *s, int c, size_t n);

int	main(void)
{
	unsigned char	c;
	const char		*s;
	char			str[] = "ssssssssasdfas";

	memset(str, 'a', 5 * sizeof(char));
	printf("%s\n", str);
	ft_memset(str, '!', 6 * sizeof(char));
	printf("%s\n", str);
	s = "asdfjasdjfpqoef";
	c = 123;
	printf("%d %ld\n", ft_strlen(s), strlen(s));
	printf("%d %d\n", ft_isascii(c), isascii(c));
	printf("%d %d\n", ft_isprint(c), isprint(c));
}
