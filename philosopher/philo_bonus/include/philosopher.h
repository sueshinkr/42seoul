/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sueshin <sueshin@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 23:26:21 by sueshin           #+#    #+#             */
/*   Updated: 2022/08/19 13:58:47 by sueshin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

typedef struct s_philo_rule
{
	int		numofph;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		musteat;
	int		fullph;
	int		isph_die;
	pid_t	*pid_fork;
	sem_t	*fork;
	sem_t	*print_lock;
	sem_t	*isfull;
	sem_t	*end;
}	t_ph_rule;

typedef struct s_ph_data
{
	t_ph_rule		*ph_rule;
	struct timeval	base_time;
	int				ph_dead;
	int				ph_num;
	int				eat_num;
	int				last_eating_t;
}	t_ph_data;

t_ph_rule	*init_ph_rule(int argc, char **argv);
void		init_ph_data(t_ph_rule *ph_rule, t_ph_data *ph_data, int idx);

void		taken_fork(t_ph_data *ph_data);
void		eating(t_ph_data *ph_data);
void		sleeping(t_ph_data *ph_data);
void		thinking(t_ph_data *ph_data);

int			eat_count(t_ph_data *ph_data);
void		*death_check(void *arg);
void		*eating_check(void *arg);

void		print_error(int errno);
int			ft_time(t_ph_data *ph_data);
int			ft_atoi(const char	*str);

#endif
