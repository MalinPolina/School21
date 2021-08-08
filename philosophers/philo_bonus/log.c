
#include "philo.h"

int	ft_usleep(size_t time)
{
	size_t	fin;

	fin = what_time() + time / 1000;
	while (what_time() <= fin)
		usleep(50);
	return (0);
}

size_t	what_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, 0);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

int	ft_error(char *s)
{
	write(1, "Error: ", 7);
	if (s)
		ft_putstr(s);
	write(1, "\n", 1);
	return (1);
}

void	print_log(t_philo *ph, char *type, int dead)
{
	sem_wait(ph->info->log);
	if (ph->info->murder)
	{
		sem_post(ph->info->log);
		return ;
	}
	ft_putnbr(what_time() - ph->info->start);
	write(1, " ", 1);
	ft_putnbr(ph->id);
	ft_putstr(type);
	if (dead)
	{
		sem_post(ph->info->death);
		return ;
	}
	sem_post(ph->info->log);
}
