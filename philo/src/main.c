/*
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
number_of_times_each_philospopher_must_eat
*/

#include "philosopher.h"

void	*philo_action(void *arg)
{
	t_ph_data		 *ph_data;

	ph_data = (t_ph_data *)arg;

	while(!ph_data->ph_rule->isph_die)
	{
		if (ph_data->ph_rule->isph_die)
			return (NULL);
		taken_fork(ph_data);
		if (ph_data->ph_rule->isph_die)
			return (NULL);
		eating(ph_data);
		if (ph_data->ph_rule->isph_die)
			return (NULL);
		sleeping(ph_data);
		if (ph_data->ph_rule->isph_die)
			return (NULL);
		thinking(ph_data);
		if (ph_data->ph_rule->isph_die)
			return (NULL);
	}
	return (NULL);
	/*
	각 쓰레드에서 무한루프돌면서 동작해야함. mutex걸면서 오른쪽포크 집고, 왼쪽포크 집음
	둘다 성공시 먹기시작 > 종료
	종료하고 정해진 시간동안 먹지못하면 죽음
	*/
}

int	ft_time(t_ph_data *ph_data)
{
	struct timeval	time;
	int				cur_t;

	gettimeofday(&time, NULL);
	cur_t = (time.tv_sec - ph_data->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->base_time.tv_usec) / 1000;
	return (cur_t);
}

void	*death_check(void *arg)
{
	int	cur_t;
	int	idx;
	t_ph_data		 *ph_data;

	ph_data = (t_ph_data *)arg;
	while(!ph_data->ph_rule->isph_die)
	{
		idx = -1;
		while (++idx < ph_data->ph_rule->number_of_philosophers)
		{
			cur_t = ft_time(ph_data);
			if (cur_t - ph_data[idx].last_eating_t > ph_data->ph_rule->time_to_die)
			{
				ph_data[idx].ph_rule->isph_die = 1;
				pthread_mutex_lock(&ph_data->ph_rule->print_lock);
				printf("%d %d is died\n", cur_t, ph_data[idx].ph_num + 1);
				usleep(100);
				pthread_mutex_unlock(&ph_data->ph_rule->print_lock);
				return(NULL);
			}
		}
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_ph_rule	*ph_rule;
	t_ph_data	*ph_data;
	int		idx;
	pthread_t *tid_ph;
	pthread_t tid_m;

	if (!(argc == 5 || argc == 6))
	{
		printf("Invalid Arguments\n");
		exit(1);
	}
	ph_rule = init_ph_rule(argc, argv);
	ph_data = init_ph_data(ph_rule);
	tid_ph = (pthread_t *)malloc(ph_rule->number_of_philosophers * sizeof(pthread_t));
	idx = -1;
	while(++idx < ph_rule->number_of_philosophers)
	{
		pthread_create(&tid_ph[idx], NULL, philo_action, (void *)&ph_data[idx]);
		pthread_detach(tid_ph[idx]);
	}
	pthread_create(&tid_m, NULL, death_check, (void *)ph_data);
	pthread_join(tid_m, NULL);
	return (0);
}
