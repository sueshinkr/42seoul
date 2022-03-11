/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 16:31:27 by sueshin           #+#    #+#             */
/*   Updated: 2022/03/11 18:08:02 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*str)
{
	int	result;
	int	flag;

	result = 0;
	flag = 0;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (flag == 0 && *str == '-')
		flag = -1;
	else if (flag == 0 && *str == '+')
		flag = 1;
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + *str - '0';
		else
			break ;
		str++;
	}
	if (flag == -1)
		return (-result);
	else
		return (result);
}
