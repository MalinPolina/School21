# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daniseed <daniseed@student.21-school.      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/05 14:14:41 by daniseed          #+#    #+#              #
#    Updated: 2021/04/02 19:32:00 by daniseed         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = gcc

CFLAGS  =  -Wall -Wextra -Werror

SRCS    = ft_strlen.s ft_strcpy.s ft_strcmp.s ft_write.s ft_read.s ft_strdup.s

BONUS 	= ft_list_push_front.s ft_list_size.s

HDRS    = libasm.h

OBJS    = ${SRCS:.s=.o}

BOBJS	= ${BONUS:.s=.o}

BHDRS	= libasm_bonus.h

RM      = rm -f

NAME    = libasm.a

%.o: 	%.s Makefile
		nasm -f macho64 $<

TEST 	=	test

BTEST	=	btest

all:        ${NAME}

${NAME}:    ${OBJS} ${HDRS} Makefile
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

test:		all
			${CC} ${CFLAGS} -L. -lasm -o ${TEST} main.c
			./${TEST}

bonus:		${OBJS} ${BOBJS} ${HDRS} ${BHDRS}
			ar rc ${NAME} ${OBJS} ${BOBJS}
			ranlib ${NAME}

btest:		bonus
			${CC} ${CFLAGS} -L. -lasm -o ${BTEST} main_bonus.c
			./${BTEST}

clean:
			${RM} ${OBJS} ${BOBJS}

fclean:		clean
			${RM} ${NAME} ${TEST} ${BTEST}

re:			fclean all

.PHONY:		all test bonus btest clean fclean remake 
