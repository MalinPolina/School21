
#include "philo.h"

static void	*party(void *philo)
{
	t_philo	*ph;

	ph = (t_philo *)philo;
	while (!ph->info->death && !ph->info->full && !ph->info->error)
	{
		think(ph);
		if (!(ph->id % 2))
		{
			if (right_eat(ph))
				ph->info->error++;
		}
		else
		{
			ft_usleep(500);
			if (left_eat(ph))
				ph->info->error++;
		}
		if (ph->right == ph->left || ph->info->error)
			break ;
		ft_sleep(ph);
	}
	return (NULL);
}

static void	kill_everyone(t_philo *philo, t_info *info)
{
	size_t	i;

	i = 0;
	while (i < info->nbr)
	{
		if (pthread_join((philo[i].tid), NULL))
			info->error++;
		i++;
	}
}

static int	starved(t_philo *philo, t_info *info, size_t *meals)
{
	size_t	i;

	i = 0;
	while (i < info->nbr)
	{
		if (what_time() - philo[i].last_meal > info->tt_die)
		{
			if (print_log(&philo[i], DIED, 1))
				info->error++;
			return (1);
		}
		if (philo[i].meals >= info->must_eat && !philo[i].full)
		{
			philo[i].full++;
			(*meals)++;
			if (*meals == info->nbr)
			{
				info->full++;
				return (1);
			}
		}
		i++;
	}
	return (0);
}

static void	find_corpse(t_philo *philo, t_info *info)
{
	size_t		meals;

	meals = 0;
	while (!info->error)
	{
		if (starved(philo, info, &meals))
			break ;
	}
	kill_everyone(philo, info);
}

int	dinner(t_philo *philo, t_info *info)
{
	size_t	i;
	int		j;

	i = 0;
	while (i < info->nbr)
	{
		if (pthread_create(&(philo[i].tid), NULL, party, philo + i))
		{
			j = i - 1;
			while (j >= 0)
				pthread_detach(philo[i].tid);
			return (1);
		}
		i++;
	}
	find_corpse(philo, info);
	return (info->error);
}
