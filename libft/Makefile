# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/24 17:09:11 by younglee          #+#    #+#              #
#    Updated: 2022/05/10 16:56:09 by younglee         ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a
CC			= @cc
CFLAGS		= -Wall -Wextra -Werror
INC			= -I.
M_SRCS		= ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c \
			ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
			ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
B_SRCS		= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
M_OBJS		= ${M_SRCS:.c=.o}
B_OBJS		= ${B_SRCS:.c=.o}
RM			= @rm -f
AR			= @ar -rcs

ifdef WITH_BONUS
	OBJS	= ${M_OBJS} ${B_OBJS}
else
	OBJS	= ${M_OBJS}
endif

.c.o:
			${CC} ${CFLAGS} ${INC} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

all:		${NAME}

clean:
			${RM} ${M_OBJS} ${B_OBJS}

fclean:		clean
			${RM} ${NAME}

re:
			@make fclean
			@make all

bonus:
			@make WITH_BONUS=1 all

.PHONY:		.c.o all clean fclean re bonus
