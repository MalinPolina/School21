
CC		= gcc

CFLAGS	= -c -Wall -Wextra -Werror -I

SRCS	= ft_printf.c \
		  ft_spec.c \
		  type_num.c \
		  type_string.c \
		  type_other.c \
		  sup_print.c \
		  ft_base.c \
		  n_print.c

HDRS	= printft.h

OBJS	= ${SRCS:.c=.o}

LIBFT	= ./libft/libft.a

RM		= rm -rf

NAME	= libftprintf.a

all:		$(NAME)

$(NAME):	${OBJS}
			${MAKE} -C ./libft
			cp $(LIBFT) $(NAME)
			ar rc $(NAME) ${OBJS}
			ranlib $(NAME)

clean:
			${MAKE} clean -C ./libft
			${RM} ${OBJS}

fclean:		clean
			${MAKE} fclean -C ./libft
			${RM} $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
