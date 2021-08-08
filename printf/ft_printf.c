
#include "printft.h"

static int		ft_type(va_list args, const char *str, int t)
{
	t_var var;

	ft_memset(&var, 0, sizeof(var));
	var.prec = -1;
	var = *ft_spec(args, str, &var);
	if (*(str + t) == 'c')
		return (type_char(va_arg(args, int), &var));
	else if (*(str + t) == 's')
		return (type_string(va_arg(args, const char *), &var));
	else if (*(str + t) == 'p')
		return (type_pointer(va_arg(args, unsigned long long int), &var));
	else if (*(str + t) == 'i' || *(str + t) == 'd')
		return (type_num(va_arg(args, int), &var));
	else if (*(str + t) == 'u')
		return (type_num(va_arg(args, unsigned int), &var));
	else if (*(str + t) == 'x')
		return (type_lhex(va_arg(args, unsigned int), &var, 0));
	else if (*(str + t) == 'X')
		return (type_uhex(va_arg(args, unsigned int), &var));
	else if (*(str + t) == '%')
		return (type_percent(&var));
	return (0);
}

static int		through_str(va_list args, const char *str)
{
	int n;
	int i;
	int rn;

	n = 0;
	while (*str)
	{
		if (*str == '%')
		{
			i = 1;
			while (ft_isdigit(*(str + i)) || ft_isflag(*(str + i)))
				i++;
			if (ft_istype(*(str + i)))
			{
				rn = ft_type(args, str + 1, i - 1);
				str += i;
				n += rn;
			}
		}
		else
			n += write(1, str, 1);
		str++;
	}
	return (n);
}

int				ft_printf(const char *str, ...)
{
	int		n;
	va_list	args;

	n = 0;
	va_start(args, str);
	n += through_str(args, str);
	va_end(args);
	return (n);
}
