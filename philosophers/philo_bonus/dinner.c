
#include "philo.h"

static void	*watcher(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (1)
	{
		ft_usleep(1000);
		if ((what_time() - ph->last_meal) > ph->info->tt_die)
		{
			print_log(ph, DIED, 1);
			break ;
		}
		if (!ph->full && ph->info->must_eat > 0
			&& ph->meals >= ph->info->must_eat)
		{
			ph->full++;
			sem_post(ph->info->full);
		}
	}
	return (NULL);
}

static void	party(t_philo *ph)
{
	pthread_create(&(ph->tid), NULL, watcher, ph);
	pthread_detach(ph->tid);
	while (!ph->info->murder)
	{
		think(ph);
		eat(ph);
		ft_sleep(ph);
	}
	exit (0);
}

static void	kill_everyone(t_philo *philo, t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->nbr)
	{
		if (philo[i].pid)
		{
			if (kill(philo[i].pid, SIGKILL))
				info->error++;
		}
		i++;
	}
	pthread_detach(info->eaten);
}

static void	*diet(void *philo)
{
	t_philo	*ph;
	size_t	i;

	ph = (t_philo *)philo;
	if (ph->info->must_eat > 0)
	{
		i = 0;
		while (i < ph->info->nbr)
		{
			sem_wait(ph->info->full);
			i++;
		}
		sem_post(ph->info->death);
		return (NULL);
	}
	return (NULL);
}

int	dinner(t_philo *philo, t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->nbr)
	{
		philo[i].pid = fork();
		if (philo[i].pid < 0)
			return (1);
		else if (!philo[i].pid)
			party(philo + i);
		i++;
	}
	pthread_create(&(info->eaten), NULL, diet, philo);
	sem_wait(info->death);
	info->murder++;
	kill_everyone(philo, info);
	return (0);
}
