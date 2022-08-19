/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 22:18:26 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/17 19:58:09 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	print_error(int errno)
{
	if (errno == 1)
		printf("Invalid Arguments\n");
	else if (errno == 2)
		printf("Allocate Error\n");
}

int	ft_time(t_ph_data *ph_data)
{
	struct timeval	time;
	int				cur_t;

	gettimeofday(&time, NULL);
	cur_t = (time.tv_sec - ph_data->base_time.tv_sec) * 1000 + \
	(time.tv_usec - ph_data->base_time.tv_usec) / 1000;
	return (cur_t);
}
