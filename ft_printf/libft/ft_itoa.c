/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 15:18:41 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/27 02:32:07 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
