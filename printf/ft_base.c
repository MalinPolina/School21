
#include "printft.h"

static void	ft_rev(char **num)
{
	char	c;
	int		l;
	int		i;

	l = ft_strlen(*num) - 1;
	i = 0;
	while (i <= l / 2)
	{
		c = *(*num + i);
		*(*num + i) = *(*num + l - i);
		*(*num + l - i) = c;
		i++;
	}
}

static void	dec_hex2(char **num, char *hex, unsigned long long int n, int up)
{
	int l;

	l = 0;
	while (n)
	{
		*(*num + l) = *(hex + (n % 16));
		if (up)
			*(*num + l) = ft_toupper(*(*num + l));
		n /= 16;
		l++;
	}
	*(*num + l) = '\0';
}

char		*dec_hex(unsigned long long int nbr, int up)
{
	unsigned long long int	n;
	char					hex[16];
	unsigned int			l;
	char					*num;

	ft_strlcpy(hex, "0123456789abcdef", 17);
	l = 1;
	n = nbr;
	while ((n /= 10))
		l++;
	if (!(num = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	if (nbr == 0)
	{
		*num = *hex;
		*(num + 1) = '\0';
		return (num);
	}
	dec_hex2(&num, hex, nbr, up);
	ft_rev(&num);
	return (num);
}
