/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:33:18 by sueshin           #+#    #+#             */
/*   Updated: 2022/12/04 17:12:46 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cal_count(long long n)
{
	int				count;

	count = 0;
	if (n == 0)
		count++;
	else if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n, int *minus)
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
		*minus = -1;
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

char	*ft_uitoa(unsigned int n)
{
	char		*str;
	int			count;
	long long	nb;

	nb = n;
	count = cal_count(nb);
	str = (char *)malloc((count + 1) * sizeof(char));
	if (!str)
		return (NULL);
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

char	*numtohex(unsigned long long num, int idx, int bigorsmall)
{
	unsigned long long	temp;
	char				*hex;

	temp = num;
	if (temp == 0)
		idx = 1;
	while (temp > 0)
	{
		temp /= 16;
		idx++;
	}
	hex = (char *)malloc((idx + 1) * sizeof(char));
	if (!hex)
		return (NULL);
	hex[idx--] = 0;
	while (idx >= 0)
	{
		if (bigorsmall == 1)
			hex[idx--] = "0123456789ABCDEF"[num % 16];
		else
			hex[idx--] = "0123456789abcdef"[num % 16];
		num /= 16;
	}
	return (hex);
}
