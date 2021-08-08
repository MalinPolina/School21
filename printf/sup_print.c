
#include "printft.h"

int			ft_istype(int c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' ||
		c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

int			ft_isflag(int c)
{
	if (c == '-' || c == '0' || c == '.' || c == '*')
		return (1);
	return (0);
}

int			ft_width(int w, int f, char c)
{
	int n;

	n = 0;
	while ((w - f) > n)
		n += write(1, &c, 1);
	return (n);
}
