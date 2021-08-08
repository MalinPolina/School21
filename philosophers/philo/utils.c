
#include "philo.h"

size_t	get_nbr(const char *str)
{
	int		i;
	size_t	n;

	n = 0;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	if (str[i])
		return (0);
	return (n);
}

static size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

void	ft_putstr(char *s)
{
	if (!s)
		return ;
	write(1, s, ft_strlen(s));
}

static void	ft_putnbr2(size_t n)
{
	char	c;

	if (n)
	{
		c = '0' + n % 10;
		n /= 10;
		ft_putnbr2(n);
		write(1, &c, 1);
	}
}

void	ft_putnbr(size_t n)
{
	if (n == 0)
		write(1, "0", 1);
	else
		ft_putnbr2(n);
}
