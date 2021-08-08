
NAME = philo

CC = gcc -lpthread
FLAGS = -Wall -Werror -Wextra

HEADER = philo.h

SRC = main.c dinner.c lifecycle.c log.c utils.c

OBJ = $(SRC:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(HEADER)
			$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o: %.c
		$(CC) $(FLAGS) -c $^ -o $@

clean:
		${RM} ${OBJ}

fclean: clean
		${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
