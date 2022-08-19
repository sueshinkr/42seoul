/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 19:38:46 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/18 11:31:29 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	eat_count(t_ph_data *ph_data)
{
	int	idx;

	idx = -1;
	if (ph_data->ph_rule->musteat == -1)
		return (0);
	while (++idx < ph_data->ph_rule->numofph)
	{
		if (ph_data[idx].eat_num < ph_data->ph_rule->musteat)
			return (0);
	}
	return (1);
}

static void	print_death(t_ph_data *ph_data, int idx)
{
	pthread_mutex_lock(&ph_data->ph_rule->print_lock);
	if (eat_count(ph_data))
	{
		pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
		return ;
	}
	printf("%d %d is died\n", ft_time(ph_data), ph_data[idx].ph_num + 1);
	usleep(100);
	pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
}

void	*death_check(void *arg)
{
	int			idx;
	t_ph_data	*ph_data;

	ph_data = (t_ph_data *)arg;
	while (!ph_data->ph_rule->isph_die || !eat_count(ph_data))
	{
		idx = -1;
		while (++idx < ph_data->ph_rule->numofph)
		{
			if (ft_time(ph_data) - ph_data[idx].last_eating_t >= \
			ph_data->ph_rule->time_to_die)
			{
				ph_data[idx].ph_rule->isph_die = 1;
				print_death(ph_data, idx);
				return (NULL);
			}
		}
	}
	return (NULL);
}
