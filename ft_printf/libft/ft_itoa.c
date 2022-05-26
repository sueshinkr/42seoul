/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:18:41 by sueshin           #+#    #+#             */
/*   Updated: 2022/05/24 16:54:50 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static int	cal_count(int n)
{
	int				count;
	unsigned int	temp;

	count = 0;
	if (n < 0)
	{
		temp = n * -1;
		count++;
	}
	else
		temp = n;
	if (temp == 0)
		count = 1;
	while (temp > 0)
	{
		temp /= 10;
		count++;
	}
	return (count);
}

static void	recur_cal(char *str, unsigned int n, int count)
{
	count--;
	if (n >= 10)
		recur_cal(str, n / 10, count);
	*(str + count) = n % 10 | '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		count;

	count = cal_count(n);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		recur_cal(str, (unsigned int)(n * -1), count);
	}
	else
		recur_cal(str, n, count);
	*(str + count) = 0;
	return (str);
}
*/

static int	cal_count(long long n)
{
	int				count;

	count = 0;
	if (n <= 0)
	{
		n = n * -1;
		count++;
	}
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			count;
	long long	nb;
	
	nb = n;
	count = cal_count(nb);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (n < 0)
	{
		*str = '-';
		nb = nb * -1;
	}
	if (n == 0)
		*str = '0';
	*(str + count) = 0;
	while (nb > 0)
	{
		*(str + --count) = nb % 10 | '0';
		nb /= 10;
	}
	return (str);
}
