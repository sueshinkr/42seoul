/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 22:51:04 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/10 19:19:34 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main(void)
{
	unsigned char	c;
	const char		*s;
	char			str[30] = "abckldefghijklmnop";
	char			src[] = "12345";
	char			src2[] = "klm";
	int 			a[10] = {1, 2, 3, 4, 5, 6, 7};
	int				b[10];
	int 			i = -1;
	char			*s1;
	char			*s2;

	s1 = &str[0];
	s2 = &str[0] + 4;
	printf("***************************\n");

	printf("strnstr:::%s\n", strnstr(str, src2, sizeof(str)));
	printf("ft_strnstr:::%s\n", ft_strnstr(str, src2, sizeof(str)));
	printf("***************************\n");
	
	printf("memcmp:::%d\n", memcmp(str, src, sizeof(src)));
	printf("memcmp:::%d\n", memcmp(str, str, sizeof(src)));
	printf("memcmp:::%d\n", memcmp(src, str, sizeof(src)));
	printf("ft_memcmp:::%d\n", ft_memcmp(str, src, sizeof(src)));
	printf("ft_memcmp:::%d\n", ft_memcmp(str, str, sizeof(src)));
	printf("ft_memcmp:::%d\n", ft_memcmp(src, str, sizeof(src)));
	printf("***************************\n");
	
	printf("memchr:::%d\n", *(int *)memchr(a, 3, sizeof(str)));
	printf("ft_memchr:::%d\n", *(int *)ft_memchr(a, 3, sizeof(str)));
	printf("***************************\n");

	printf("strrchr:::%s\n", strrchr(s2, 'k'));
	printf("ft_strrchr:::%s\n", ft_strrchr(s2, 'k'));
	printf("***************************\n");

	printf("strchr:::%s\n", strchr(str, 'k'));
	printf("ft_strchr:::%s\n", ft_strchr(str, 'k'));
	printf("***************************\n");

	printf("toupper:::%c\n", ft_toupper('^'));
	printf("tolower:::%c\n", ft_tolower('H'));
	printf("***************************\n");

	printf("strlcat:::%lu\n", ft_strlcat(str, src, 30));
	printf("%s\n", str);
	printf("***************************\n");

	printf("strlcpy:::%lu\n", strlcpy(str, src, 2));
	printf("%s\n", str);
	printf("***************************\n");
	
	printf("before memmove s1 : %s\n", s1);
	printf("before memmove s2 : %s\n", s2);

	ft_memmove(s1, s2, strlen(s2));
	printf("s1 : %s\n", s1);
	printf("s2 : %s\n", s2);


	printf("%lu\n", sizeof(a));
	memcpy(b, a, sizeof(a));
	while (++i < 100 && b[i] != 0)
		printf("%d, ", b[i]);

	memcpy(str, src, sizeof(src) - 1);
	printf("%s\n", str);


	memset(str, 'a', 5 * sizeof(char));
	printf("%s\n", str);
	ft_memset(str, '!', 6 * sizeof(char));
	printf("%s\n", str);
	s = "asdfjasdjfpqoef";
	c = 123;
	printf("%zu %ld\n", ft_strlen(s), strlen(s));
	printf("%d %d\n", ft_isascii(c), isascii(c));
	printf("%d %d\n", ft_isprint(c), isprint(c));
}
