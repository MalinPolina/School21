
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	size;

	size = ft_strlen(src) + 1;
	dup = malloc(sizeof(*src) * size);
	if (dup)
		ft_strlcpy(dup, src, size);
	return (dup);
}
