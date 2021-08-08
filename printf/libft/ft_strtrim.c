
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	finish;
	size_t	start;

	if (!s1 || !*s1)
		return ((char*)s1);
	start = 0;
	while (ft_strchr(set, *(s1 + start)) && *(s1 + start))
		start++;
	finish = ft_strlen(s1) - 1;
	while (ft_strchr(set, *(s1 + finish)) && (finish > start))
		finish--;
	str = ft_substr(s1, start, (finish - start + 1));
	return (str);
}
