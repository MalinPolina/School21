
#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	l;

	l = ft_strlen(str) + 1;
	while (l--)
	{
		if (*(str + l) == c)
			return ((char*)(str + l));
	}
	return (NULL);
}
