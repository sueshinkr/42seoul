/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:38:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/21 12:43:23 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

int	eat_count(t_ph_data *ph_data)
{
	if (ph_data->ph_rule->musteat == -1)
		return (0);
	else if (ph_data->eat_num == ph_data->ph_rule->musteat)
		return (1);
	return (0);
}

static void	print_death(t_ph_data *ph_data)
{
	sem_wait(ph_data->ph_rule->print_lock);
	printf("%d %d is died\n", ft_time(ph_data), ph_data->ph_num + 1);
	sem_post(ph_data->ph_rule->end);
}

void	*death_check(void *arg)
{
	t_ph_data	*ph_data;
	int			flag;

	flag = 0;
	ph_data = (t_ph_data *)arg;
	while (1)
	{	
		if (eat_count(ph_data) && flag == 0)
		{
			sem_post(ph_data->ph_rule->isfull);
			flag = 1;
		}
		if (ft_time(ph_data) - ph_data->last_eating_t >= \
		ph_data->ph_rule->time_to_die)
		{
			print_death(ph_data);
			return (0);
		}
	}
	return (NULL);
}

void	*eating_check(void *arg)
{
	t_ph_rule	*ph_rule;
	int			idx;

	idx = -1;
	ph_rule = (t_ph_rule *)arg;
	while (++idx < ph_rule->numofph)
		sem_wait(ph_rule->isfull);
	sem_post(ph_rule->end);
	return (NULL);
}
