# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 15:29:00 by jubae             #+#    #+#              #
#    Updated: 2022/06/13 22:44:23 by jubae            ###   ########.fr        #
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
NAME = libft.a

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
		@$(CC) $(CFLAGS) -c $< -o $@
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
