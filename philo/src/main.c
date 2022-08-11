/*
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
number_of_times_each_philospopher_must_eat
*/

#include "philosopher.h"

t_ph_rule	*init_ph_rule(int argc, char **argv)
{
	t_ph_rule	*ph_rule;

	ph_rule = malloc(sizeof(t_ph_rule));
	if (!ph_rule)
		exit(1);
	ph_rule->number_of_philosophers = atoi(argv[1]);
	ph_rule->time_to_die = atoi(argv[2]);
	ph_rule->time_to_eat = atoi(argv[3]);
	ph_rule->time_to_sleep = atoi(argv[4]);
	if (argc == 6)
		ph_rule->number_of_times_each_philosopher_must_eat = atoi(argv[5]);
	else
		ph_rule->number_of_times_each_philosopher_must_eat = -1;
	ph_rule->isph_die = 0;
	gettimeofday(&ph_rule->base_time, NULL);
	ph_rule->fork = malloc(ph_rule->number_of_philosophers * sizeof(pthread_mutex_t));
	ph_rule->is_eating = malloc(ph_rule->number_of_philosophers * sizeof(pthread_mutex_t));
	return (ph_rule);
}

t_ph_data	*init_ph_data(t_ph_rule *ph_rule)
{
	t_ph_data	*ph_data;
	int			idx;

	idx = -1;
	ph_data = malloc(ph_rule->number_of_philosophers * sizeof(t_ph_data));
	if (!ph_data)
		exit(1);
	while(++idx < ph_rule->number_of_philosophers)
	{
		ph_data[idx].ph_rule = ph_rule;
		ph_data[idx].ph_num = idx;
		ph_data[idx].last_eating_t = 0;
	}

	return (ph_data);
}

void	taken_fork(t_ph_data *ph_data)
{
	struct timeval	time;
	int				cur_t;

	if (!ph_data->ph_rule->isph_die)
	{
		gettimeofday(&time, NULL);
		cur_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
		printf("%d %d has taken a fork\n", cur_t, ph_data->ph_num + 1);
	}
	return ;
}

void	eating(t_ph_data *ph_data)
{
	struct timeval	time;
	int				cur_t;
	int				eating_t;

	if (!ph_data->ph_rule->isph_die)
	{
		pthread_mutex_lock(&ph_data->ph_rule->is_eating[ph_data->ph_num]);
		gettimeofday(&time, NULL);
		cur_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
		eating_t = cur_t;

		printf("%d %d is eating\n", eating_t, ph_data->ph_num + 1);
		while (eating_t - cur_t < ph_data->ph_rule->time_to_eat)
		{
			usleep(1);
			gettimeofday(&time, NULL);
			eating_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
		}
		pthread_mutex_unlock(&ph_data->ph_rule->is_eating[ph_data->ph_num]);
		ph_data->last_eating_t = eating_t;
	}
	return ;
}

void	sleeping(t_ph_data *ph_data)
{
	struct timeval	time;
	int				cur_t;
	int				sleeping_t;

	if (!ph_data->ph_rule->isph_die)
	{
		gettimeofday(&time, NULL);
		cur_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
		sleeping_t = cur_t;

		printf("%d %d is sleeping\n", sleeping_t, ph_data->ph_num + 1);
		while (sleeping_t - cur_t < ph_data->ph_rule->time_to_sleep)
		{
			usleep(1);
			gettimeofday(&time, NULL);
			sleeping_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
		}
		printf("%d %d is thinking\n", sleeping_t, ph_data->ph_num + 1);
	}
	return ;
}

void	*philo_action(void *arg)
{
	t_ph_data		 *ph_data;

	ph_data = (t_ph_data *)arg;

	while(!ph_data->ph_rule->isph_die)
	{
		if (ph_data->ph_num % 2 == 0)
		{
			pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
			pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num + 1) % ph_data->ph_rule->number_of_philosophers]);

			taken_fork(ph_data);
			eating(ph_data);
			pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
			pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num + 1) % ph_data->ph_rule->number_of_philosophers]);

			sleeping(ph_data);
			usleep(100);
		}
		else
		{
			pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num + 1) % ph_data->ph_rule->number_of_philosophers]);
			pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
			
			taken_fork(ph_data);
			eating(ph_data);
			pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num + 1) % ph_data->ph_rule->number_of_philosophers]);
			pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);

			sleeping(ph_data);
			usleep(100);
		}
	}
	return (NULL);
	/*
	각 쓰레드에서 무한루프돌면서 동작해야함. mutex걸면서 오른쪽포크 집고, 왼쪽포크 집음
	둘다 성공시 먹기시작 > 종료
	종료하고 정해진 시간동안 먹지못하면 죽음
	*/
}

int	ft_time(t_ph_rule *ph_rule)
{
	struct timeval	time;
	int				cur_t;

	gettimeofday(&time, NULL);
	cur_t = (time.tv_sec - ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_rule->base_time.tv_usec) / 1000;
	return (cur_t);
}

void	*death_check(void *arg)
{
	int	cur_t;
	t_ph_data		 *ph_data;

	ph_data = (t_ph_data *)arg;

	while(!ph_data->ph_rule->isph_die)
	{
		pthread_mutex_lock(&ph_data->ph_rule->is_eating[ph_data->ph_num]);
		cur_t = ft_time(ph_data->ph_rule);
		if (cur_t - ph_data->last_eating_t >= ph_data->ph_rule->time_to_die)
		{
			printf("%d %d is died\n", cur_t, ph_data->ph_num + 1);
			ph_data->ph_rule->isph_die = 1;
		}
		pthread_mutex_unlock(&ph_data->ph_rule->is_eating[ph_data->ph_num]);
	}
	return (NULL);
}


int	main(int argc, char **argv)
{
	t_ph_rule	*ph_rule;
	t_ph_data	*ph_data;
	int		idx;
	pthread_t *tid_ph;
	pthread_t *tid_m;

	if (!(argc == 5 || argc == 6))
		exit(1);
	ph_rule = init_ph_rule(argc, argv);
	ph_data = init_ph_data(ph_rule);
	tid_ph = (pthread_t *)malloc(ph_rule->number_of_philosophers * sizeof(pthread_t));
	tid_m = (pthread_t *)malloc(ph_rule->number_of_philosophers * sizeof(pthread_t));
	idx = -1;
	while(++idx < ph_rule->number_of_philosophers)
	{
		pthread_create(&tid_ph[idx], NULL, philo_action, (void *)&ph_data[idx]);
		pthread_detach(tid_ph[idx]);
		pthread_create(&tid_m[idx], NULL, death_check, (void *)&ph_data[idx]);
		pthread_detach(tid_m[idx]);
	}
	death_check(ph_data);
	//printf("end\n");

}
