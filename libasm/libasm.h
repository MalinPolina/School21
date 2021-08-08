#ifndef	LIBASM_H
# define LIBASM_H
# include	<stdlib.h>
# include	<errno.h>

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dst, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_write(int fildes, const void *buf, size_t nbyte);
size_t			ft_read(int fildes, void *buf, size_t nbyte);
char			*ft_strdup(const char *s);

#endif
