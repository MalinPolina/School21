
#include "libft.h"

static void	putpnb(unsigned int nb, int fd)
{
	char	c;

	if (nb)
	{
		c = '0' + nb % 10;
		nb = nb / 10;
		putpnb(nb, fd);
		ft_putchar_fd(c, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	unsigned int	nb;

	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			nb = n * (-1);
		}
		else
			nb = n;
		putpnb(nb, fd);
	}
}
