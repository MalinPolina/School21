
#include "printft.h"

static int	s_write(const char *str, int l, int pr)
{
	if (!str)
		return (write(1, "(null)", 6));
	if (l > pr)
		return (write(1, str, pr));
	return (write(1, str, l));
}

static int	type_s(char *s, t_var *var)
{
	int l;
	int w;
	int n;
	int pr;

	l = ft_strlen(s);
	w = var->width;
	n = 0;
	if ((pr = var->prec) == -1)
		pr = l;
	if (w <= pr && w <= l)
		n += s_write(s, l, pr);
	else
	{
		if (var->minus)
			n += s_write(s, l, pr);
		if (pr < l)
			n += ft_width(w, pr, ' ');
		else
			n += ft_width(w, l, ' ');
		if (!var->minus)
			n += s_write(s, l, pr);
	}
	return (n);
}

int			type_string(const char *str, t_var *var)
{
	int		n;
	char	*s;

	n = 0;
	if (!str && var->prec == 0)
	{
		return (ft_width(var->width, 0, ' '));
	}
	if (!str)
	{
		if (!(s = malloc(sizeof(char) * 7)))
			return (0);
		ft_strlcpy(s, "(null)", 7);
	}
	else
	{
		if (!(s = malloc(sizeof(char) * (ft_strlen(str) + 1))))
			return (0);
		ft_strlcpy(s, str, ft_strlen(str) + 1);
	}
	n += type_s(s, var);
	free(s);
	return (n);
}
