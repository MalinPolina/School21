
#include "printft.h"

int			type_num(long int nbr, t_var *var)
{
	char	*num;

	num = ft_itoa(nbr);
	return (n_print(nbr, var, num));
}

int			type_lhex(unsigned int nbr, t_var *var, int up)
{
	char	*num;

	num = dec_hex(nbr, up);
	return (n_print(nbr, var, num));
}

int			type_uhex(unsigned int nbr, t_var *var)
{
	return (type_lhex(nbr, var, 1));
}
