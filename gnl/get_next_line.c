
#include "get_next_line.h"

static char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	size;

	if (!src)
		return (NULL);
	size = ft_strlen(src) + 1;
	dup = malloc(sizeof(char) * size);
	if (dup)
		ft_strlcpy(dup, src, size);
	return (dup);
}

static char	*linecpy(char *other, char *tmp)
{
	char	*new;
	int		len;

	if (!other)
		return (NULL);
	len = ft_strlen(other);
	if (!tmp)
		new = ft_strdup(other);
	else
	{
		new = ft_strjoin(tmp, other);
		free(tmp);
	}
	return (new);
}

static char	*whatleft(char *left)
{
	char	*next;
	char	*new;
	int		i;

	i = 0;
	if (!left)
		return (NULL);
	if (!(next = ft_strchr(left, '\n')))
	{
		free(left);
		return (NULL);
	}
	next++;
	if (!(new = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (NULL);
	while (*(next + i) != '\0')
	{
		*(new + i) = *(next + i);
		i++;
	}
	*(new + i) = '\0';
	free(left);
	return (new);
}

static int	gnl(int fd, char **tmp, char **left)
{
	char	*buf;
	int		r;

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((r = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		*(buf + r) = '\0';
		if (!(*tmp = linecpy(buf, *tmp)))
		{
			free(buf);
			return (-1);
		}
		if (ft_strchr(buf, '\n'))
		{
			*left = whatleft(buf);
			break ;
		}
	}
	if (r <= 0)
		free(buf);
	return (r);
}

int			get_next_line(int fd, char **line)
{
	static char	*left;
	char		*tmp;
	int			r;

	tmp = NULL;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!left)
		left = ft_strdup("");
	if ((tmp = ft_strdup(left)))
		if ((left = whatleft(left)))
		{
			*line = tmp;
			return (1);
		}
	r = gnl(fd, &tmp, &left);
	if (tmp)
		*line = tmp;
	if (r <= 0)
		return (r);
	return (1);
}
