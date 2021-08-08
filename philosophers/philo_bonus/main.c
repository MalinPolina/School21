
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
	info->murder = 0;
	return (0);
}

static int	init_sem(t_info *info)
{
	unsigned long	i;

	info->forks = sem_open("forks", O_CREAT | O_EXCL, 0644, info->nbr);
	info->log = sem_open("log", O_CREAT | O_EXCL, 0644, 1);
	info->death = sem_open("death", O_CREAT | O_EXCL, 0644, 0);
	info->full = sem_open("full", O_CREAT | O_EXCL, 0644, info->nbr);
	info->take = sem_open("take", O_CREAT | O_EXCL, 0644, 1);
	if (info->forks == SEM_FAILED || info->log == SEM_FAILED
		|| info->full == SEM_FAILED || info->death == SEM_FAILED)
		return (1);
	i = 0;
	while (i < info->nbr)
	{
		sem_wait(info->full);
		i++;
	}
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
		i++;
	}
	return (0);
}

static void	destroy_sem(t_info *info)
{
	sem_unlink("forks");
	sem_close(info->forks);
	sem_unlink("log");
	sem_close(info->log);
	sem_unlink("death");
	sem_close(info->death);
	sem_unlink("full");
	sem_close(info->full);
	sem_unlink("take");
	sem_close(info->take);
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
	destroy_sem(&info);
	if (init_sem(&info))
		return (ft_error("failed to init semaphore"));
	if (init_philo(&philo, &info))
		return (ft_error("malloc error"));
	if (dinner(philo, &info))
		return (ft_error("problem with processes"));
	ft_usleep(1000);
	destroy_sem(&info);
	if (philo)
		free(philo);
	return (0);
}
