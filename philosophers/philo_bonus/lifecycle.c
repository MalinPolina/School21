
#include "philo.h"

void	ft_sleep(t_philo *ph)
{
	print_log(ph, SLEEP, 0);
	ft_usleep(ph->info->tt_sleep * 1000);
}

void	think(t_philo *ph)
{
	print_log(ph, THINK, 0);
}

void	eat(t_philo *ph)
{
	if (ph->info->nbr > 1)
		sem_wait(ph->info->take);
	sem_wait(ph->info->forks);
	print_log(ph, FORK, 0);
	sem_wait(ph->info->forks);
	print_log(ph, FORK, 0);
	ph->last_meal = what_time();
	print_log(ph, EAT, 0);
	sem_post(ph->info->take);
	ft_usleep(ph->info->tt_eat * 1000);
	sem_post(ph->info->forks);
	sem_post(ph->info->forks);
	ph->meals++;
}
