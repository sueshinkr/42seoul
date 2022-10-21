/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:56:56 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/21 12:50:45 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	*philo_action(void *arg)
{
	t_ph_data	*ph_data;

	ph_data = (t_ph_data *)arg;
	if (ph_data->ph_rule->numofph == 1)
		return (NULL);
	while (ph_data->ph_rule->musteat == -1 || \
	ph_data->eat_num < ph_data->ph_rule->musteat)
	{
		taken_fork(ph_data);
		eating(ph_data);
		sleeping(ph_data);
		thinking(ph_data);
	}
	return (NULL);
}

void	free_all(t_ph_rule *ph_rule)
{
	sem_close(ph_rule->fork);
	sem_close(ph_rule->end);
	sem_close(ph_rule->print_lock);
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_end");
	free(ph_rule);
}

void	kill_process(t_ph_rule *ph_rule, pid_t *pid_fork)
{
	int	idx;

	idx = -1;
	while (++idx < ph_rule->numofph)
		kill(pid_fork[idx], SIGTERM);
	free(pid_fork);
}

void	make_ph(t_ph_rule *ph_rule, pid_t *pid_fork)
{
	t_ph_data	ph_data;
	pthread_t	tid_m;
	int			idx;

	idx = -1;
	while (++idx < ph_rule->numofph)
	{
		pid_fork[idx] = fork();
		if (pid_fork[idx] == 0)
		{
			init_ph_data(ph_rule, &ph_data, idx);
			pthread_create(&tid_m, NULL, death_check, (void *)&ph_data);
			philo_action(&ph_data);
			pthread_join(tid_m, NULL);
			exit(0);
		}
	}
	pthread_create(&tid_m, NULL, eating_check, (void *)ph_rule);
	pthread_detach(tid_m);
	sem_wait(ph_rule->end);
}

int	main(int argc, char **argv)
{
	t_ph_rule	*ph_rule;
	pid_t		*pid_fork;

	if (!(argc == 5 || argc == 6))
	{
		printf("Invalid Arguments\n");
		return (1);
	}
	ph_rule = init_ph_rule(argc, argv);
	if (!ph_rule)
		return (1);
	pid_fork = malloc(sizeof(pid_t) * ph_rule->numofph);
	if (!pid_fork)
	{
		print_error(4);
		free_all(ph_rule);
		exit(1);
	}
	make_ph(ph_rule, pid_fork);
	kill_process(ph_rule, pid_fork);
	free_all(ph_rule);
	return (0);
}
