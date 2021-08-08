
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*fs;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	fs = malloc(sizeof(*s) * (len + 1));
	i = 0;
	if (!fs)
		return (NULL);
	*(fs + len) = '\0';
	while (i < len)
	{
		*(fs + i) = f(i, *(s + i));
		i++;
	}
	return (fs);
}
