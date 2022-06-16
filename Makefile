# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 00:28:23 by jubae             #+#    #+#              #
#    Updated: 2022/06/17 00:33:26 by jubae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror
ifeq ($(DEBUG1),true)
	CFLAGS += -g
endif
ifeq ($(DEBUG2),true)
	CFLAGS += -g3 -fsanitize=address
endif
NAME = minishell
NAME_BONUS = minishell_bonus

FT_LIBS_DIR = ft_libs/
LIBFT_A = libft.a
LIBFT_DIR = $(FT_LIBS_DIR)libft/
LIBFT = $(addprefix $(LIBFT_DIR), $(LIBFT_A))
FT_PRINTF_A = libftprintf.a
FT_PRINTF_DIR = $(FT_LIBS_DIR)ft_printf/
FT_PRINTF = $(addprefix $(FT_PRINTF_DIR), $(FT_PRINTF_A))
GET_NEXT_LINE_A = libgetnextline.a
GET_NEXT_LINE_DIR = $(FT_LIBS_DIR)get_next_line/
GET_NEXT_LINE_BUFFER_SIZE = 981
GET_NEXT_LINE = $(addprefix $(GET_NEXT_LINE_DIR), $(GET_NEXT_LINE_A))

INCS_DIR = ./includes

SRCS_DIR = ./srcs
SRCS = $(shell find $(SRCS_DIR) -name "*.c")
OBJS = $(SRCS:%.c=%.o)

SRCS_BONUS_DIR = ./srcs_bonus
SRCS_BONUS = $(shell find $(SRCS_BONUS_DIR) -name "*.c")
OBJS_BONUS = $(SRCS_BONUS:%.c=%.o)

Y = "\033[33m"
R = "\033[31m"
G = "\033[32m"
B = "\033[34m"
X = "\033[0m"
UP = "\033[A"
CUT = "\033[K"

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCS_DIR) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(GET_NEXT_LINE_DIR)
		@echo $(Y)Compiling [$<]...$(X)

$(NAME) : $(OBJS)
		make -C $(LIBFT_DIR) DEBUG1=$(DEBUG1) DEBUG2=$(DEBUG2)
		make -C $(FT_PRINTF_DIR) DEBUG1=$(DEBUG1) DEBUG2=$(DEBUG2)
		make -C $(GET_NEXT_LINE_DIR) DEBUG1=$(DEBUG1) DEBUG2=$(DEBUG2) GET_NEXT_LINE_BUFFER_SIZE=$(GET_NEXT_LINE_BUFFER_SIZE)
		@$(CC) $(CFLAGS) $(MLX_FLAGS) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(GET_NEXT_LINE_DIR) $^ $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $@
		@echo $(G)Finished execute [$(NAME)]$(X)

$(NAME_BONUS) : $(OBJS_BONUS)
		make -C $(LIBFT_DIR)
		make -C $(FT_PRINTF_DIR)
		make -C $(GET_NEXT_LINE_DIR) GET_NEXT_LINE_BUFFER_SIZE=$(GET_NEXT_LINE_BUFFER_SIZE)
		@$(CC) $(CFLAGS) $(MLX_FLAGS) -I $(LIBFT_DIR) -I $(FT_PRINTF_DIR) -I $(GET_NEXT_LINE_DIR) $^ $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) -o $@
		@echo $(G)Finished execute [$(NAME_BONUS)]$(X)	

all : $(NAME)

bonus : $(NAME_BONUS)

clean :
		@make -C $(LIBFT_DIR) CPATH="./$(LIBFT_DIR)" clean
		@make -C $(FT_PRINTF_DIR) CPATH="./$(FT_PRINTF_DIR)" clean
		@make -C $(GET_NEXT_LINE_DIR) CPATH="./$(GET_NEXT_LINE_DIR)" clean
		@rm -f $(OBJS) $(OBJS_BONUS)
		@echo $(R)Removed [$(SRCS_DIR)/*.o]$(X)
		@echo $(R)Removed [$(SRCS_BONUS_DIR)/*.o]$(X)
		

fclean :
		@make -C $(LIBFT_DIR) CPATH="./$(LIBFT_DIR)" fclean
		@make -C $(FT_PRINTF_DIR) CPATH="./$(FT_PRINTF_DIR)" fclean
		@make -C $(GET_NEXT_LINE_DIR) CPATH="./$(GET_NEXT_LINE_DIR)" fclean
		@rm -f $(OBJS) $(OBJS_BONUS)
		@echo $(R)Removed [$(SRCS_DIR)/*.o]$(X)
		@echo $(R)Removed [$(SRCS_BONUS_DIR)/*.o]$(X)
		@rm -f $(NAME) $(NAME_BONUS)
		@echo $(R)Removed [$(NAME)]$(X)
		@echo $(R)Removed [$(NAME_BONUS)]$(X)
		@rm -rf *.dSYM
		@echo $(R)Removed [*.dSYM]$(X)

re :
		make fclean
		make all

.PHONY : all bonus clean fclean re