
#include "printft.h"

static int	n_write(int l, int p, long int nbr, char *num)
{
	int n;

	n = 0;
	if (l <= p)
	{
		if (nbr < 0)
		{
			n += write(1, "-", 1);
			num++;
			l--;
		}
		n += ft_width(p, l, '0');
	}
	if (!(!p && !nbr))
		n += write(1, num, l);
	return (n);
}

static int	n_print2(long int nbr, char *num, t_var *var, int l)
{
	int n;
	int w;

	n = 0;
	w = var->width;
	if (nbr < 0 && var->prec >= l)
		w--;
	if (var->minus)
		n += n_write(l, var->prec, nbr, num);
	if (var->zero && !var->minus && var->prec == -1)
	{
		if (nbr < 0)
			w--;
		n += n_write(l, w, nbr, num);
	}
	else
	{
		if (l < var->prec)
			n += ft_width(w, var->prec, ' ');
		else
			n += ft_width(w, l, ' ');
		if (!var->minus)
			n += n_write(l, var->prec, nbr, num);
	}
	return (n);
}

int			n_print(long int nbr, t_var *var, char *num)
{
	int		l;
	int		n;

	n = 0;
	l = ft_strlen(num);
	if (!var->prec && !nbr)
		l--;
	if (var->width <= var->prec || var->width <= l)
		n += n_write(l, var->prec, nbr, num);
	else
		n += n_print2(nbr, num, var, l);
	free(num);
	return (n);
}
