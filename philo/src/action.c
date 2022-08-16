/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:45:42 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/16 18:48:57 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	taken_fork(t_ph_data *ph_data)
{
	int	cur_t;

	//if (ph_data->ph_num % 2 == 0 && (ph_data->ph_num + 1) != ph_data->ph_rule->number_of_philosophers)
	if (ph_data->ph_num % 2 == 0)
	{
		pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
		pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num + 1) % ph_data->ph_rule->number_of_philosophers]);
	}
	else
	{
		usleep(200);
		pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num + 1) % ph_data->ph_rule->number_of_philosophers]);
		pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
	}
	if (!ph_data->ph_rule->isph_die)
	{
		pthread_mutex_lock(&ph_data->ph_rule->print_lock);
		if (ph_data->ph_rule->isph_die)
		{
			pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
			return ;
		}
		cur_t = ft_time(ph_data);
		printf("%d %d has taken a fork\n", cur_t, ph_data->ph_num + 1);
		pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
	}
}

void	eating(t_ph_data *ph_data)
{
	int	cur_t;
	int	eating_t;

	pthread_mutex_lock(&ph_data->ph_rule->print_lock);
	if (ph_data->ph_rule->isph_die)
	{
		pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
		return ;
	}
	cur_t = ft_time(ph_data);
	eating_t = cur_t;
	printf("%d %d is eating\n", eating_t, ph_data->ph_num + 1);
	pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
	ph_data->eat_num++;
	ph_data->last_eating_t = eating_t;
	while (eating_t - cur_t < ph_data->ph_rule->time_to_eat)
	{
		usleep(ph_data->ph_rule->time_to_eat * 5);
		eating_t = ft_time(ph_data);
	}
	pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
	pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num + 1) % ph_data->ph_rule->number_of_philosophers]);
}

void	sleeping(t_ph_data *ph_data)
{
	int	cur_t;
	int	sleeping_t;

	pthread_mutex_lock(&ph_data->ph_rule->print_lock);
	if (ph_data->ph_rule->isph_die)
	{
		pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
		return ;
	}
	cur_t = ft_time(ph_data);
	sleeping_t = cur_t;
	printf("%d %d is sleeping\n", sleeping_t, ph_data->ph_num + 1);
	pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
	while (sleeping_t - cur_t < ph_data->ph_rule->time_to_sleep)
	{
		usleep(ph_data->ph_rule->time_to_sleep * 5);
		sleeping_t = ft_time(ph_data);
	}
}

void	thinking(t_ph_data *ph_data)
{
	int	cur_t;
	
	pthread_mutex_lock(&ph_data->ph_rule->print_lock);
	if (ph_data->ph_rule->isph_die)
	{
		pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
		return ;
	}
	cur_t = ft_time(ph_data);
	printf("%d %d is thinking\n", cur_t, ph_data->ph_num + 1);
	pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
	usleep(200);
}
