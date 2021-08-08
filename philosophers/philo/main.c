
#include "philo.h"

static int	fill_info(t_info *info, int argc, char **argv)
{
	info->nbr = get_nbr(argv[1]);
	info->tt_die = get_nbr(argv[2]);
	info->tt_eat = get_nbr(argv[3]);
	info->tt_sleep = get_nbr(argv[4]);
	if (argc == 6)
		info->must_eat = get_nbr(argv[5]);
	else
		info->must_eat = -1;
	if (!info->nbr || !info->tt_die
		|| !info->tt_eat || !info->tt_sleep
		|| (argc == 6 && !info->must_eat))
		return (1);
	info->start = what_time();
	info->death = 0;
	return (0);
}

static int	init_mutex(t_info *info)
{
	unsigned long	i;

	info->forks = malloc(sizeof(pthread_mutex_t) * info->nbr);
	if (!info->forks)
		return (1);
	i = 0;
	while (i < info->nbr)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
			return (1);
		i++;
	}
	if (pthread_mutex_init(&info->log, NULL))
		return (1);
	return (0);
}

static int	init_philo(t_philo **philo, t_info *info)
{
	unsigned long	i;

	i = 0;
	*philo = malloc(sizeof(t_philo) * info->nbr);
	if (!*philo)
		return (1);
	while (i < info->nbr)
	{
		memset(&((*philo)[i]), 0, sizeof(t_philo));
		(*philo)[i].info = info;
		(*philo)[i].last_meal = info->start;
		(*philo)[i].id = i + 1;
		(*philo)[i].left = i;
		if (i + 1 < info->nbr)
			(*philo)[i].right = i + 1;
		i++;
	}
	return (0);
}

static int	destroy_mutex(t_info *info)
{
	unsigned long	i;
	int				err;

	i = 0;
	err = 0;
	while (i < info->nbr)
	{
		if (pthread_mutex_destroy(&info->forks[i]))
			err++;
		i++;
	}
	if (pthread_mutex_destroy(&info->log))
		err++;
	return (err);
}

int	main(int argc, char **argv)
{
	t_info	info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (ft_error("wrong number of options"));
	memset(&info, 0, sizeof(t_info));
	if (fill_info(&info, argc, argv))
		return (ft_error("options error"));
	if (init_mutex(&info))
		return (ft_error("failed to init mutex"));
	if (init_philo(&philo, &info))
		return (ft_error("malloc error"));
	if (dinner(philo, &info))
		return (ft_error("problem with threads"));
	ft_usleep(1000);
	if (destroy_mutex(&info))
		return (ft_error("failed to destroy mutex"));
	if (info.forks)
		free(info.forks);
	if (philo)
		free(philo);
	return (0);
}
