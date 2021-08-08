
#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == ' ' || c == '\t' || (c >= '\n' && c <= '\r'))
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned int	i;
	int				n;
	unsigned int	is_negative;

	i = 0;
	n = 0;
	is_negative = 0;
	while (ft_isspace(*(str + i)))
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			is_negative++;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		n = 10 * n + (*(str + i) - '0');
		i++;
	}
	if ((is_negative % 2))
		n *= -1;
	return (n);
}
