
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t size)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = ft_strlen(little);
	if (!*little)
		return ((char*)big);
	if (size <= 0)
		return (NULL);
	while (*(big + i) && (size - l + 1))
	{
		if (!ft_memcmp(big + i, little, l))
			return ((char*)(big + i));
		i++;
		size--;
	}
	return (NULL);
}
