/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:45:42 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/21 12:43:22 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher_bonus.h"

void	taken_fork(t_ph_data *ph_data)
{
	int	cur_t;

	sem_wait(ph_data->ph_rule->fork);
	sem_wait(ph_data->ph_rule->fork);
	sem_wait(ph_data->ph_rule->print_lock);
	if (eat_count(ph_data))
	{
		sem_post(ph_data->ph_rule->print_lock);
		return ;
	}
	cur_t = ft_time(ph_data);
	printf("%d %d has taken a fork\n", cur_t, ph_data->ph_num + 1);
}

void	eating(t_ph_data *ph_data)
{
	int	cur_t;
	int	eating_t;

	if (eat_count(ph_data))
	{
		sem_post(ph_data->ph_rule->print_lock);
		return ;
	}
	cur_t = ft_time(ph_data);
	eating_t = cur_t;
	printf("%d %d is eating\n", eating_t, ph_data->ph_num + 1);
	sem_post(ph_data->ph_rule->print_lock);
	ph_data->last_eating_t = eating_t;
	while (eating_t - cur_t < ph_data->ph_rule->time_to_eat)
	{
		usleep(ph_data->ph_rule->time_to_eat);
		eating_t = ft_time(ph_data);
	}
	ph_data->eat_num++;
	sem_post(ph_data->ph_rule->fork);
	sem_post(ph_data->ph_rule->fork);
}

void	sleeping(t_ph_data *ph_data)
{
	int	cur_t;
	int	sleeping_t;

	sem_wait(ph_data->ph_rule->print_lock);
	if (eat_count(ph_data))
	{
		sem_post(ph_data->ph_rule->print_lock);
		return ;
	}
	cur_t = ft_time(ph_data);
	sleeping_t = cur_t;
	printf("%d %d is sleeping\n", sleeping_t, ph_data->ph_num + 1);
	sem_post(ph_data->ph_rule->print_lock);
	while (sleeping_t - cur_t < ph_data->ph_rule->time_to_sleep)
	{
		usleep(ph_data->ph_rule->time_to_sleep);
		sleeping_t = ft_time(ph_data);
	}
}

void	thinking(t_ph_data *ph_data)
{
	int	cur_t;

	sem_wait(ph_data->ph_rule->print_lock);
	if (eat_count(ph_data))
	{
		sem_post(ph_data->ph_rule->print_lock);
		return ;
	}
	cur_t = ft_time(ph_data);
	printf("%d %d is thinking\n", cur_t, ph_data->ph_num + 1);
	sem_post(ph_data->ph_rule->print_lock);
	usleep(200);
}
