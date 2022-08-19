/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:45:07 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/19 20:07:32 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static int	set_sem(t_ph_rule *ph_rule)
{
	sem_unlink("sem_fork");
	sem_unlink("sem_print");
	sem_unlink("sem_end");
	sem_unlink("sem_isfull");
	ph_rule->fork = sem_open("sem_fork", \
	O_CREAT | O_EXCL, 644, ph_rule->numofph);
	ph_rule->print_lock = sem_open("sem_print", O_CREAT | O_EXCL, 644, 1);
	ph_rule->end = sem_open("sem_end", O_CREAT | O_EXCL, 644, 0);
	ph_rule->isfull = sem_open("sem_isfull", O_CREAT | O_EXCL, 644, 0);
	if (!ph_rule->fork || !ph_rule->print_lock || \
	!ph_rule->end || !ph_rule->isfull)
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
	ph_rule->isph_die = 0;
	ph_rule->fullph = 0;
	gettimeofday(&ph_rule->base_time, NULL);
	return (0);
}

t_ph_rule	*init_ph_rule(int argc, char **argv)
{
	t_ph_rule	*ph_rule;
	int			errno;

	errno = 0;
	ph_rule = malloc(sizeof(t_ph_rule));
	if (!ph_rule)
		errno = 1;
	if (set_arg(ph_rule, argc, argv))
		errno = 2;
	if (set_sem(ph_rule))
		errno = 3;
	if (errno)
	{
		if (errno != 1)
			free(ph_rule);
		print_error(errno);
		return (NULL);
	}
	return (ph_rule);
}

void	init_ph_data(t_ph_rule *ph_rule, t_ph_data *ph_data, int idx)
{
	ph_data->ph_rule = ph_rule;
	ph_data->ph_num = idx;
	ph_data->eat_num = 0;
	ph_data->last_eating_t = 0;
	//gettimeofday(&ph_data->base_time, NULL);
}
