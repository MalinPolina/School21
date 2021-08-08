
#include "libft.h"

static char	*itoatwo(long int n, int l, int is_neg)
{
	char		*num;
	long int	nb;

	num = malloc(sizeof(char) * (l + 1));
	if (!num)
		return (NULL);
	*(num + l) = '\0';
	if (!n)
		*num = '0';
	l--;
	nb = n;
	if (is_neg)
	{
		nb *= -1;
		*num = '-';
	}
	while (nb)
	{
		*(num + l) = nb % 10 + '0';
		l--;
		nb /= 10;
	}
	return (num);
}

char		*ft_itoa(long int n)
{
	char			*num;
	long int		nb;
	int				l;
	int				is_neg;

	is_neg = 0;
	if (n < 0)
		is_neg++;
	l = is_neg + 1;
	nb = n;
	if (is_neg)
		nb *= -1;
	while ((nb /= 10))
		l++;
	num = itoatwo(n, l, is_neg);
	return (num);
}
