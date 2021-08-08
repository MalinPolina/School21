
#ifndef PHILO_H
# define PHILO_H

# include <string.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

# include <sys/time.h>
# include <pthread.h>

# define SLEEP 	" is sleeping\n"
# define EAT	" is eating\n"
# define FORK 	" has taken a fork\n"
# define THINK	" is thinking\n"
# define DIED 	" died\n"

typedef struct s_info
{
	size_t			nbr;
	size_t			tt_die;
	size_t			tt_eat;
	size_t			tt_sleep;
	size_t			must_eat;

	size_t			start;

	pthread_mutex_t	*forks;
	pthread_mutex_t	log;

	int				error;
	int				death;
	int				full;
}				t_info;

typedef struct s_philo
{
	size_t			id;
	size_t			meals;
	size_t			right;
	size_t			left;
	int				full;

	size_t			last_meal;

	pthread_t		tid;
	t_info			*info;
}				t_philo;

//dinner
int		dinner(t_philo *philo, t_info *info);

//lifecycle
void	ft_sleep(t_philo *ph);
void	think(t_philo *ph);
int		left_eat(t_philo *ph);
int		right_eat(t_philo *ph);

//log
int		ft_usleep(size_t time);
size_t	what_time(void);
int		ft_error(char *s);
int		print_log(t_philo *ph, char *type, int dead);

//utils
size_t	get_nbr(const char *str);
void	ft_putstr(char *s);
void	ft_putnbr(size_t n);

#endif
