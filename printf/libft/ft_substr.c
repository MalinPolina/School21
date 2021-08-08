
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = malloc(sizeof(*s) * (len + 1));
	if (str && ft_strlen(s) > start)
	{
		while ((len > i) && *(s + start + i))
		{
			*(str + i) = *(s + start + i);
			i++;
		}
		if (len >= i)
			*(str + i) = '\0';
	}
	return (str);
}
