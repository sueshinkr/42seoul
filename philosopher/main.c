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
	int		idx;

	idx = -1;
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
	gettimeofday(&ph_rule->base_time, NULL);
	ph_rule->fork = malloc(ph_rule->number_of_philosophers * sizeof(pthread_mutex_t));
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

void	*philo_action(void *arg)
{
	pthread_t		tid;
	struct timeval	time;
	int				start_eating_t;
	int				after_eating_t;
	int				after_sleeping_t;
	int				cur_t;
	t_ph_data		 *ph_data;

	ph_data = (t_ph_data *)arg;

	while(1)
	{
		if (ph_data->ph_num % 2 == 0)
		{
			pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num - 1) % ph_data->ph_rule->number_of_philosophers]);
			pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
			gettimeofday(&time, NULL);
			start_eating_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
			
			printf("%d living time : %d\n", ph_data->ph_num, start_eating_t - ph_data->last_eating_t);
			if (start_eating_t - ph_data->last_eating_t> ph_data->ph_rule->time_to_die)
			{
				printf("%d %d is died\n", cur_t, ph_data->ph_num);
				sleep(10);
			}
			
			printf("%d %d is eating\n", start_eating_t, ph_data->ph_num);
			usleep(ph_data->ph_rule->time_to_eat * 1000);
			pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num - 1) % ph_data->ph_rule->number_of_philosophers]);
			pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
			
			gettimeofday(&time, NULL);
			after_eating_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
			ph_data->last_eating_t = after_eating_t;
			printf("%d %d is sleeping\n", after_eating_t, ph_data->ph_num);
			usleep(ph_data->ph_rule->time_to_sleep * 1000);
			
			gettimeofday(&time, NULL);
			after_sleeping_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
			printf("%d %d is thinking\n", after_sleeping_t, ph_data->ph_num);
		}
		else
		{
			pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
			pthread_mutex_lock(&ph_data->ph_rule->fork[(ph_data->ph_num - 1) % ph_data->ph_rule->number_of_philosophers]);
			gettimeofday(&time, NULL);
			start_eating_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
			
			printf("%d living time : %d\n", ph_data->ph_num, start_eating_t - ph_data->last_eating_t);
			if (start_eating_t - ph_data->last_eating_t> ph_data->ph_rule->time_to_die)
			{
				printf("%d %d is died\n", cur_t, ph_data->ph_num);
				sleep(10);
			}
			
			printf("%d %d is eating\n", start_eating_t, ph_data->ph_num);
			usleep(ph_data->ph_rule->time_to_eat * 1000);
			pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num) % ph_data->ph_rule->number_of_philosophers]);
			pthread_mutex_unlock(&ph_data->ph_rule->fork[(ph_data->ph_num - 1) % ph_data->ph_rule->number_of_philosophers]);
			
			gettimeofday(&time, NULL);
			after_eating_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
			ph_data->last_eating_t = after_eating_t;
			printf("%d %d is sleeping\n", after_eating_t, ph_data->ph_num);
			usleep(ph_data->ph_rule->time_to_sleep * 1000);
			
			gettimeofday(&time, NULL);
			after_sleeping_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
			printf("%d %d is thinking\n", after_sleeping_t, ph_data->ph_num);
		}
		/*
		gettimeofday(&time, NULL);
		cur_t = (time.tv_sec - ph_data->ph_rule->base_time.tv_sec) * 1000 + (time.tv_usec - ph_data->ph_rule->base_time.tv_usec) / 1000;
		printf("%d living time : %d\n", ph_data->ph_num, cur_t - after_eating_t);
		if (cur_t - after_eating_t > ph_data->ph_rule->time_to_die)
		{
			printf("%d %d is died\n", cur_t, ph_data->ph_num);
			sleep(10);
		}
		*/
	}
	/*
	각 쓰레드에서 무한루프돌면서 동작해야함. mutex걸면서 오른쪽포크 집고, 왼쪽포크 집음
	둘다 성공시 먹기시작 > 종료
	종료하고 정해진 시간동안 먹지못하면 죽음
	*/
}


int	main(int argc, char **argv)
{
	t_ph_rule	*ph_rule;
	t_ph_data	*ph_data;
	int		idx;
	pthread_t *tid;

	if (!(argc == 5 || argc == 6))
		exit(1);
	ph_rule = init_ph_rule(argc, argv);
	ph_data = init_ph_data(ph_rule);
	tid = (pthread_t *)malloc(ph_rule->number_of_philosophers * sizeof(pthread_t));
	idx = -1;
	while(++idx < ph_rule->number_of_philosophers)
	{
		pthread_create(&tid[idx], NULL, philo_action, (void *)&ph_data[idx]);
	}
	while(1);

}
