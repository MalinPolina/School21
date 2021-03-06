
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	if (dst == src)
		return (dst);
	else if (dst < src)
		ft_memcpy(dst, src, n);
	else
	{
		while (n--)
			*(unsigned char*)(dst + n) = *(unsigned char*)(src + n);
	}
	return (dst);
}
