# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/09 01:31:45 by jubae             #+#    #+#              #
#    Updated: 2022/06/13 22:44:13 by jubae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
ifeq ($(DEBUG1),true)
	CFLAGS += -g
endif
ifeq ($(DEBUG2),true)
	CFLAGS += -g3 -fsanitize=address
endif
LIBFT_PATH = ../libft
LIBFT_LIB = libft.a
NAME = libgetnextline.a

SRCS = $(shell find . -name "*.c")
OBJS = $(SRCS:.c=.o)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

%o : %c
		@$(CC) $(CFLAGS) -D BUFFER_SIZE=$(GET_NEXT_LINE_BUFFER_SIZE) -c $< -o $@ -I $(LIBFT_PATH)
		@printf $(UP)$(CUT)
		@echo $(Y)Static lib\(.a\) building [$<]...$(X)

$(NAME) : $(OBJS)
		@printf $(UP)$(CUT)
		@echo $(Y)Static lib\(.a\) building [$(NAME)]...$(X)
		@ar -rcs $(NAME) $(OBJS)
		@ranlib $(NAME)
		@echo $(G)Finished lib [$(NAME)]$(X)

all : $(NAME)

clean :
		@rm -f $(OBJS)
		@echo $(R)Removed [$(CPATH)*.o]$(X)

fclean : clean
		@rm -f $(NAME)
		@echo $(R)Removed [$(CPATH)$(NAME)]$(X)

re : fclean all

.PHONY : all clean fclean re bonus
