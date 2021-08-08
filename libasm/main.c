#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
	errno = 0;
	char *str = "Hello";
	char *sstr = "Hella";
	char *lstr = "The Thing cannot be described—there is no language for such abysms of shrieking and immemorial lunacy, such eldritch contradictions of all matter, force, and cosmic order. A mountain walked or stumbled. God! … The Thing of the idols, the green, sticky spawn of the stars, had awaked to claim his own.\0";
	char cstr[1000];

	printf("\nSTRLEN\n");
	printf("Just string\n");
	printf("strlen: %lu\n", strlen(str));
	printf("ft_strlen: %lu\n", ft_strlen(str));
	printf("Empty string\n");
	printf("strlen: %lu\n", strlen(""));
	printf("ft_strlen: %lu\n", ft_strlen(""));
	printf("Long string\n");
	printf("strlen: %lu\n", strlen(lstr));
	printf("ft_strlen: %lu\n", ft_strlen(lstr));

	printf("\nSTRCPY\n");
	printf("Just string\n");
	printf("strcpy: %s\n", strcpy(cstr, str));
	printf("ft_strcpy: %s\n", ft_strcpy(cstr, str));
	printf("Empty string\n");
	printf("strcpy: %s\n", strcpy(cstr, ""));
	printf("ft_strcpy: %s\n", ft_strcpy(cstr, ""));
	printf("Long string\n");
	printf("strcpy: %s\n", strcpy(cstr, lstr));
	printf("ft_strcpy: %s\n", ft_strcpy(cstr, lstr));
	
	printf("\nSTRCMP\n");
	printf("Just strings\n");
	printf("strcmp: %d\n", strcmp(sstr, str));
	printf("ft_strcmp: %d\n", ft_strcmp(sstr, str));
	printf("strcmp: %d\n", strcmp(str, sstr));
	printf("ft_strcmp: %d\n", ft_strcmp(str, sstr));
	printf("Empty strings\n");
	printf("strcmp: %d\n", strcmp("", ""));
	printf("ft_strcmp: %d\n", ft_strcmp("", ""));
	printf("One empty\n");
	printf("strcmp: %d\n", strcmp("", str));
	printf("ft_strcmp: %d\n", ft_strcmp("", str));
	printf("strcmp: %d\n", strcmp(str, ""));
	printf("ft_strcmp: %d\n", ft_strcmp(str, ""));


	int i = 0;
	int	fd;
	printf("\nWRITE\n");
	printf("Stdout\n");
	i = write(1, "Here\n", 5);
	//printf("write: %d\n", i);
	i = ft_write(1, "Here\n", 5);
	//printf("ft_write: %d\n", i);
	printf("To file\n");
	fd = open("write_test.txt", O_WRONLY|O_CREAT|O_TRUNC);
	i = write(fd, "Here1\n", 6);
	printf("write: %d\n", i);
	i = ft_write(fd, "Here2\n", 6);
	printf("ft_write: %d\n", i);
	close(fd);
	printf("Wrong file\n");
	fd = open("write_test.txt", O_RDONLY);
	i = write(fd, "Here3\n", 6);
	printf("write: %d %d\n", i, errno);
	errno = 0;
	i = ft_write(fd, "Here4\n", 6);
	printf("ft_write: %d %d\n", i, errno);
	close(fd);
	printf("Wrong file2\n");
	errno = 0;
	i = write(-3, "Here3\n", 6);
	printf("write: %d %d\n", i, errno);
	errno = 0;
	i = ft_write(-3, "Here4\n", 6);
	i = write(-3, "Here3\n", 6);
	printf("ft_write: %d %d\n", i, errno);

	printf("\nREAD\n");
	printf("Stdout\n");
	memset(cstr, 0, 1000);
	i = ft_read(1, cstr, 999);
	printf("ft_read: %s\n", cstr);
	//memset(cstr, 0, 1000);
	//i = read(1, cstr, 999);
	//printf("read: %d\n", i);
	printf("From file\n");
	fd = open("read_test.txt", O_RDONLY);
	memset(cstr, 0, 1000);
	i = read(fd, cstr, 118);
	printf("read: %d\n %s\n", i, cstr);
	close(fd);
	fd = open("read_test.txt", O_RDONLY);
	memset(cstr, 0, 1000);
	i = ft_read(fd, cstr, 118);
	printf("ft_read: %d\n %s\n", i, cstr);
	close(fd);
	printf("Wrong file\n");
	errno = 0;
	fd = open("read_test.txt", O_WRONLY);
	i = read(fd, cstr, 7);
	printf("read: %d %d\n", i, errno);
	errno = 0;
	i = ft_read(fd, cstr, 1);
	printf("ft_read: %d %d\n", i, errno);
	close(fd);
	printf("Wrong file2\n");
	errno = 0;
	i = read(-3, cstr, 6);
	printf("read: %d %d\n", i, errno);
	errno = 0;
	i = ft_read(-3, cstr, 6);
	i = read(-3, "Here3\n", 6);
	printf("ft_read: %d %d\n", i, errno);	

	char *s;
	printf("\nSTRDUP\n");
	printf("Just string\n");
	s = strdup(str);
	printf("strdup: %s\n", s);
	free(s);
	s = ft_strdup(str);
	printf("ft_strdup: %s\n", s);
	free(s);
	printf("Empty string\n");
	printf("strdup: %s\n", strdup(""));
	printf("ft_strdup: %s\n", ft_strdup(""));
	printf("Long string\n");
	s = strdup(lstr);
	printf("strdup: %s\n", s);
	free(s);
	s = ft_strdup(lstr);
	printf("ft_strdup: %s\n", s);
	free(s);
	return (0);
}
