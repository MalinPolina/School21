
#include "philo.h"

void	ft_sleep(t_philo *ph)
{
	if (print_log(ph, SLEEP, 0))
	{
		ph->info->error++;
		return ;
	}
	ft_usleep(ph->info->tt_sleep * 1000);
}

void	think(t_philo *ph)
{
	if (print_log(ph, THINK, 0))
		ph->info->error++;
}

static int	eat(t_philo *ph)
{
	ph->last_meal = what_time();
	if (print_log(ph, EAT, 0))
		return (1);
	ft_usleep(ph->info->tt_eat * 1000);
	ph->meals++;
	return (0);
}

int	left_eat(t_philo *ph)
{
	if (pthread_mutex_lock(&ph->info->forks[ph->left])
		|| print_log(ph, FORK, 0))
		return (1);
	if (ph->left == ph->right)
	{
		if (pthread_mutex_unlock(&ph->info->forks[ph->left]))
			return (1);
		return (0);
	}
	if (pthread_mutex_lock(&ph->info->forks[ph->right])
		|| print_log(ph, FORK, 0))
		return (1);
	if (eat(ph))
		return (1);
	if (pthread_mutex_unlock(&ph->info->forks[ph->left]))
		return (1);
	if (pthread_mutex_unlock(&ph->info->forks[ph->right]))
		return (1);
	return (0);
}

int	right_eat(t_philo *ph)
{
	if (pthread_mutex_lock(&ph->info->forks[ph->right])
		|| print_log(ph, FORK, 0))
		return (1);
	if (ph->left == ph->right)
	{
		if (pthread_mutex_unlock(&ph->info->forks[ph->left]))
			return (1);
		return (0);
	}
	if (pthread_mutex_lock(&ph->info->forks[ph->left])
		|| print_log(ph, FORK, 0))
		return (1);
	if (eat(ph))
		return (1);
	if (pthread_mutex_unlock(&ph->info->forks[ph->right]))
		return (1);
	if (pthread_mutex_unlock(&ph->info->forks[ph->left]))
		return (1);
	return (0);
}
