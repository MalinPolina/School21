
#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;

	i = 0;
	while (*(str + i))
	{
		if (*(str + i) == (char)c)
			return ((char*)(str + i));
		i++;
	}
	if (*(str + i) == (char)c)
		return ((char*)(str + i));
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	if (size > 0)
	{
		while (*(src + i) && --size && *(src + i) != '\n')
		{
			*(dst + i) = *(src + i);
			i++;
		}
		*(dst + i) = '\0';
	}
	return (ft_strlen(src));
}

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
		while (*(src + i) && --s && *(src + i) != '\n')
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(*s1) * (len + 1));
	if (str)
	{
		ft_strlcpy(str, s1, ft_strlen(s1) + 1);
		ft_strlcat(str, s2, len + 1);
	}
	return (str);
}
