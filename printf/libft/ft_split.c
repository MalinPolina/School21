
#include "libft.h"

static size_t	wrdnum(char const *s, char c)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (!*s)
		return (0);
	n = 1;
	while (*(s + i) == c)
		i++;
	while (*(s + i))
	{
		if (*(s + i) == c && *(s + i - 1) != c)
			n++;
		i++;
	}
	if (*(s + i - 1) == c)
		n--;
	return (n);
}

static size_t	wrdlen(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == c)
			return (i);
		i++;
	}
	return (i);
}

static void		freearr(char **arr, size_t n)
{
	while (n--)
		free(arr[n]);
	free(arr);
}

static void		splittwo(char const *s, char **arr, char c)
{
	size_t	n;
	size_t	l;

	n = 0;
	while (*s)
	{
		if ((l = wrdlen(s, c)))
		{
			if ((arr[n] = malloc(sizeof(char) * (l + 1))))
			{
				ft_strlcpy(arr[n], s, l + 1);
				s = s + (l - 1);
				n++;
			}
			else
			{
				freearr(arr, n);
				break ;
			}
		}
		s++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**arr;
	size_t	n;

	if (!s)
		return (NULL);
	n = wrdnum(s, c);
	arr = malloc(sizeof(char*) * (n + 1));
	if (arr)
	{
		arr[n] = NULL;
		splittwo(s, arr, c);
	}
	return (arr);
}
