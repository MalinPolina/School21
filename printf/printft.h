
#ifndef PRINTFT_H
# define PRINTFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

typedef struct	s_var
{
	int minus;
	int zero;
	int width;
	int prec;
}				t_var;

int				ft_printf(const char *str, ...);

t_var			*ft_spec(va_list args, const char *str, t_var *var);

int				type_num(long int nbr, t_var *var);
int				type_lhex(unsigned int nbr, t_var *var, int up);
int				type_uhex(unsigned int nbr, t_var *var);

int				type_string(const char *str, t_var *var);

int				type_char(char c, t_var *var);
int				type_pointer(unsigned long long int str, t_var *var);
int				type_percent(t_var *var);

int				ft_istype(int c);
int				ft_isflag(int c);
int				ft_width(int w, int f, char c);

char			*dec_hex(unsigned long long int nbr, int up);

int				n_print(long int nbr, t_var *var, char *num);

#endif
