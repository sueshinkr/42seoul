/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:56:56 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/16 22:21:38 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	check_musteat(t_ph_data *ph_data)
{
	if (!(ph_data->ph_rule->musteat == -1) && \
	ph_data->eat_num >= ph_data->ph_rule->musteat)
		return (1);
	else
		return (0);
}

void	*philo_action(void *arg)
{
	t_ph_data	*ph_data;

	ph_data = (t_ph_data *)arg;
	while (!ph_data->ph_rule->isph_die || (ph_data->ph_rule->musteat == -1 || \
	ph_data->eat_num < ph_data->ph_rule->musteat))
	{
		if (ph_data->ph_rule->isph_die || check_musteat(ph_data))
			return (NULL);
		taken_fork(ph_data);
		if (ph_data->ph_rule->isph_die || check_musteat(ph_data))
			return (NULL);
		eating(ph_data);
		if (ph_data->ph_rule->isph_die || check_musteat(ph_data))
			return (NULL);
		sleeping(ph_data);
		if (ph_data->ph_rule->isph_die || check_musteat(ph_data))
			return (NULL);
		thinking(ph_data);
		if (ph_data->ph_rule->isph_die || check_musteat(ph_data))
			return (NULL);
	}
	return (NULL);
}

void	free_all(t_ph_rule *ph_rule, t_ph_data *ph_data, pthread_t *tid_ph)
{
	int	idx;

	idx = -1;
	while (++idx < ph_rule->numofph)
	{
		pthread_mutex_unlock(&ph_rule->fork[idx]);
		pthread_mutex_destroy(&ph_rule->fork[idx]);
	}
	pthread_mutex_unlock(&ph_rule->print_lock);
	pthread_mutex_destroy(&ph_rule->print_lock);
	free(ph_rule->fork);
	free(ph_rule);
	free(ph_data);
	free(tid_ph);
}

void	make_ph(t_ph_data *ph_data)
{
	pthread_t	*tid_ph;
	pthread_t	tid_m;
	int			idx;

	idx = -1;
	tid_ph = (pthread_t *)malloc(ph_data->ph_rule->numofph * sizeof(pthread_t));
	while (++idx < ph_data->ph_rule->numofph)
		pthread_create(&tid_ph[idx], NULL, philo_action, (void *)&ph_data[idx]);
	pthread_create(&tid_m, NULL, death_check, (void *)ph_data);
	pthread_join(tid_m, NULL);
	while (idx-- > 0)
		pthread_join(tid_ph[idx], NULL);
	free_all(ph_data->ph_rule, ph_data, tid_ph);
}

int	main(int argc, char **argv)
{
	t_ph_rule	*ph_rule;
	t_ph_data	*ph_data;

	if (!(argc == 5 || argc == 6))
	{
		printf("Invalid Arguments\n");
		return (1);
	}
	ph_rule = init_ph_rule(argc, argv);
	ph_data = init_ph_data(ph_rule);
	make_ph(ph_data);
	return (0);
}
