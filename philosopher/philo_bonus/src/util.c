/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:18:26 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/19 20:09:58 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_error(int errno)
{
	if (errno == 1 || errno == 4)
		printf("Allocate Error\n");
	else if (errno == 2)
		printf("Invalid Arguments\n");
	else if (errno == 3)
		printf("Semophore Error\n");
}

int	ft_time(t_ph_data *ph_data)
{
	struct timeval	time;
	int				cur_t;

	gettimeofday(&time, NULL);
	/*
	cur_t = (time.tv_sec - ph_data->base_time.tv_sec) * 1000 + \
	(time.tv_usec - ph_data->base_time.tv_usec) / 1000;
	*/
	cur_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + \
	(time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
	return (cur_t);
}

int	ft_atoi(const char	*str)
{
	unsigned long long	result;
	int					sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			result = result * 10 + *str - '0';
		else
			break ;
		str++;
	}
	return (sign * (int)result);
}
