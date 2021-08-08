
#include "printft.h"

int			type_char(char c, t_var *var)
{
	int n;
	int w;

	n = 0;
	w = var->width;
	if (var->minus)
		n += write(1, &c, 1);
	n += ft_width(w, 1, ' ');
	if (!var->minus)
		n += write(1, &c, 1);
	return (n);
}

int			type_pointer(unsigned long long int str, t_var *var)
{
	int		n;
	int		l;
	char	*num;

	n = 0;
	if (!str && !var->prec)
		num = ft_strdup("");
	else
		num = dec_hex(str, 0);
	l = ft_strlen(num);
	if (var->minus)
	{
		n += write(1, "0x", 2);
		n += write(1, num, l);
	}
	n += ft_width(var->width, l + 2, ' ');
	if (!var->minus)
	{
		n += write(1, "0x", 2);
		n += write(1, num, l);
	}
	free(num);
	return (n);
}

int			type_percent(t_var *var)
{
	int n;

	n = 0;
	if (var->minus)
		n += write(1, "%", 1);
	if (var->zero && !var->minus)
		n += ft_width(var->width, 1, '0');
	else
		n += ft_width(var->width, 1, ' ');
	if (!var->minus)
		n += write(1, "%", 1);
	return (n);
}
