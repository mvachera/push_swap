# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvachera <mvachera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/30 17:34:45 by mvachera          #+#    #+#              #
#    Updated: 2023/08/27 21:38:42 by mvachera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= push_swap

BONUS	= checker

CC	= clang

CFLAGS  = -Wall -Wextra -Werror -g3

RM	= rm -f

PRINTF          = ft_printf

FT_PRINTF	= ft_printf/libftprintf.a

SRC     = srcs/main.c srcs/ft_split.c srcs/pileA.c srcs/pileB.c srcs/swap.c srcs/utils.c srcs/utils2.c srcs/utils3.c srcs/handle_five.c srcs/pas_facile.c srcs/move.c srcs/end.c

BONUS_SRC	= bonus_src/bonus.c bonus_src/commande2.c bonus_src/commande.c gnl/get_next_line.c  gnl/get_next_line_utils.c \
			  bonus_src/ft_split.c \
			  bonus_src/move.c \
			  bonus_src/utils.c \
			  bonus_src/ft_arg.c \


OBJ_BONUS	= ${BONUS_SRC:.c=.o}

OBJ     = ${SRC:.c=.o}

all : ${NAME}

${NAME} : ${OBJ}
	${MAKE} -C ${PRINTF}
	${CC} ${OBJ} -o ${NAME} ${FT_PRINTF}

bonus : ${BONUS}

${BONUS} : ${OBJ_BONUS}
	${MAKE} -C ${PRINTF}
	${CC} ${OBJ_BONUS} -o ${BONUS} ${FT_PRINTF}

clean :
	${RM} ${OBJ} ${OBJ_BONUS}

fclean : clean
	${RM} ${NAME} ${BONUS}

re : fclean all

.PHONY : all clean fclean re
