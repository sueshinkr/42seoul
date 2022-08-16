/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:45:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/16 22:06:27 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

t_ph_rule	*init_ph_rule(int argc, char **argv)
{
	t_ph_rule	*ph_rule;
	int			num;

	ph_rule = malloc(sizeof(t_ph_rule));
	if (!ph_rule)
		return (NULL);
	ph_rule->numofph = atoi(argv[1]);
	ph_rule->time_to_die = atoi(argv[2]);
	ph_rule->time_to_eat = atoi(argv[3]);
	ph_rule->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		ph_rule->musteat = atoi(argv[5]);
	else
		ph_rule->musteat = -1;
	ph_rule->isph_die = 0;
	num = ph_rule->numofph;
	ph_rule->fork = malloc(ph_rule->numofph * sizeof(pthread_mutex_t));
	while (num-- > 0)
		pthread_mutex_init(&ph_rule->fork[num], NULL);
	pthread_mutex_init(&ph_rule->print_lock, NULL);
	return (ph_rule);
}

t_ph_data	*init_ph_data(t_ph_rule *ph_rule)
{
	t_ph_data	*ph_data;
	int			idx;

	idx = -1;
	ph_data = malloc(ph_rule->numofph * sizeof(t_ph_data));
	if (!ph_data)
		exit(1);
	while (++idx < ph_rule->numofph)
	{
		ph_data[idx].ph_rule = ph_rule;
		ph_data[idx].ph_num = idx;
		ph_data[idx].eat_num = 0;
		ph_data[idx].last_eating_t = 0;
		gettimeofday(&ph_data[idx].base_time, NULL);
	}
	return (ph_data);
}
