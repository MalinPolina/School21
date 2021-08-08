
#include "libft.h"

void	*ft_memchr(void *buf, int c, size_t n)
{
	while (n--)
	{
		if (*(unsigned char*)buf == (unsigned char)c)
			return (buf);
		buf++;
	}
	return (NULL);
}
