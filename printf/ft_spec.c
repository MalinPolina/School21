
#include "printft.h"

static int	ft_spec2(const char *str, t_var **var, int i)
{
	int n;

	n = ft_atoi(str + i);
	if ((*var)->prec == -1)
	{
		if (n <= 0)
			(*var)->width = n * (-1);
		else
			(*var)->width = n;
	}
	else
	{
		if (n <= 0)
			(*var)->prec = 0;
		else
			(*var)->prec = n;
	}
	while (*(str + i) != '.' && !ft_istype(*(str + i)) && *(str + i) != '*')
		i++;
	i--;
	return (i);
}

static void	ft_spec1(va_list args, t_var **var)
{
	if ((*var)->prec == 0)
	{
		if (((*var)->prec = va_arg(args, int)) < 0)
			(*var)->prec = -1;
	}
	else
	{
		if (((*var)->width = va_arg(args, int)) < 0)
		{
			(*var)->width = (*var)->width * (-1);
			(*var)->minus++;
		}
	}
}

t_var		*ft_spec(va_list args, const char *str, t_var *var)
{
	int i;

	i = 0;
	while (!ft_istype(*(str + i)))
	{
		if (*(str + i) == '0' && !var->minus && var->prec < 0)
			var->zero++;
		else if (*(str + i) == '*')
		{
			ft_spec1(args, &var);
		}
		else if (*(str + i) == '.')
			var->prec = 0;
		else if (*(str + i) == '-' && var->prec == -1)
			var->minus++;
		else
			i = ft_spec2(str, &var, i);
		i++;
	}
	return (var);
}
