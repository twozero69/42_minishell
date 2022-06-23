# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 13:39:41 by younglee          #+#    #+#              #
#    Updated: 2022/06/23 22:09:43 by younglee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= minishell
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g
SRCS		= srcs/main.c \
			srcs/utils/exit_with_error.c \
			srcs/utils/free_resources.c \
			srcs/utils/init.c \
			srcs/utils/print_clib_error.c
OBJS		= ${SRCS:.c=.o}
INC			= -I./includes
LIBFT		= -L./libft -lft
LIBFT_INC	= -I./libft
LIBFT_LIB	= libft/libft.a
LIBFT_DIR	= libft
READLINE	= -lreadline
RM			= @rm -f


.c.o:
			${CC} ${CFLAGS} ${INC} ${LIBFT_INC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS} ${LIBFT_LIB}
			${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${READLINE}

all:		${NAME}

${LIBFT_LIB}:
			@make bonus -C ${LIBFT_DIR}

clean:
			${RM} ${OBJS}
			@make clean -C ${LIBFT_DIR}

fclean:		clean
			${RM} ${NAME} ${LIBFT_LIB}

re:
			@make fclean
			@make all

.PHONY:		.c.o all clean fclean re
