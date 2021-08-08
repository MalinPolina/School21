
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		dl;
	size_t		i;
	long int	s;

	dl = ft_strlen(dst);
	s = size;
	if ((s -= dl) > 0)
	{
		i = 0;
		while (*(src + i) && --s)
		{
			*(dst + dl + i) = *(src + i);
			i++;
		}
		*(dst + dl + i) = '\0';
	}
	if (size < dl)
		dl = size;
	return (dl + ft_strlen(src));
}
