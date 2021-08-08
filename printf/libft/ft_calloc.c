
#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*mem;

	mem = malloc(n * size);
	if (mem)
		ft_memset(mem, 0, (n * size));
	return (mem);
}
