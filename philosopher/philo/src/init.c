/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:45:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/19 14:00:42 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	set_mutex(t_ph_rule *ph_rule, int num)
{
	ph_rule->fork = malloc(num * sizeof(pthread_mutex_t));
	if (!ph_rule->fork)
		return (1);
	while (num-- > 0)
	{
		if (pthread_mutex_init(&ph_rule->fork[num], NULL))
		{
			free(ph_rule->fork);
			return (1);
		}
	}
	if (pthread_mutex_init(&ph_rule->print_lock, NULL))
		return (1);
	return (0);
}

static int	set_arg(t_ph_rule *ph_rule, int argc, char **argv)
{
	ph_rule->numofph = ft_atoi(argv[1]);
	ph_rule->time_to_die = ft_atoi(argv[2]);
	ph_rule->time_to_eat = ft_atoi(argv[3]);
	ph_rule->time_to_sleep = ft_atoi(argv[4]);
	if (ph_rule->numofph < 1 || ph_rule->time_to_die < 1 || \
	ph_rule->time_to_eat < 1 || ph_rule->time_to_sleep < 1)
		return (1);
	if (argc == 6)
	{
		ph_rule->musteat = ft_atoi(argv[5]);
		if (ph_rule->musteat < 1)
			return (1);
	}
	else
		ph_rule->musteat = -1;
	return (0);
}

t_ph_rule	*init_ph_rule(int argc, char **argv)
{
	t_ph_rule	*ph_rule;

	ph_rule = malloc(sizeof(t_ph_rule));
	if (!ph_rule)
	{
		print_error(2);
		return (NULL);
	}
	if (set_arg(ph_rule, argc, argv))
	{
		print_error(1);
		free(ph_rule);
		return (NULL);
	}
	ph_rule->isph_die = 0;
	if (set_mutex(ph_rule, ph_rule->numofph))
	{
		print_error(2);
		free(ph_rule);
		return (NULL);
	}
	return (ph_rule);
}

t_ph_data	*init_ph_data(t_ph_rule *ph_rule)
{
	t_ph_data	*ph_data;
	int			idx;

	idx = -1;
	ph_data = malloc(ph_rule->numofph * sizeof(t_ph_data));
	if (!ph_data)
	{
		print_error(2);
		return (NULL);
	}
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
