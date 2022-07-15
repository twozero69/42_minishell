# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 13:39:41 by younglee          #+#    #+#              #
#    Updated: 2022/07/15 20:15:10 by jubae            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= minishell
CC				= cc
CFLAGS			= -Wall -Wextra -Werror -g
SRCS			= srcs/main.c \
				srcs/utils/exit_with_custom_error.c \
				srcs/utils/exit_with_clib_error.c \
				srcs/utils/print_minishell_error.c \
				srcs/utils/free_resources.c \
				srcs/utils/free_token_list.c \
				srcs/utils/free_ast.c \
				srcs/utils/init.c \
				srcs/utils/add_new_env.c \
				srcs/utils/my_close.c \
				srcs/utils/my_free.c \
				srcs/utils/my_dup2.c \
				srcs/utils/get_env_from_key.c \
				srcs/utils/set_shlvl.c \
				srcs/lexer/lexer.c \
				srcs/lexer/check_char.c \
				srcs/lexer/add_new_token.c \
				srcs/parser/parser.c \
				srcs/parser/check_syntax.c \
				srcs/parser/print_syntax_error.c \
				srcs/parser/check_front_and_back_tokens.c \
				srcs/parser/check_operator.c \
				srcs/parser/check_redir.c \
				srcs/parser/find_control_operator.c \
				srcs/parser/find_redir_operator.c \
				srcs/parser/get_right_parenthesis.c \
				srcs/parser/make_ast_node.c \
				srcs/parser/make_child_node.c \
				srcs/parser/make_control_node.c \
				srcs/parser/make_redir_node.c \
				srcs/parser/make_cmd_node.c \
				srcs/builtin/builtin_exit.c \
				srcs/builtin/builtin_exit_utils.c \
				srcs/builtin/builtin_echo.c \
				srcs/builtin/builtin_pwd.c \
				srcs/builtin/builtin_env.c \
				srcs/builtin/builtin_export.c \
				srcs/builtin/builtin_export_utils.c \
				srcs/builtin/builtin_export_utils2.c \
				srcs/builtin/builtin_unset.c \
				srcs/builtin/builtin_cd.c \
				srcs/builtin/builtin_cd_utils.c \
				srcs/builtin/builtin_executor.c \
				srcs/expander/expander.c \
				srcs/expander/find_wilcard.c \
				srcs/expander/set_expander.c \
				srcs/utils/my_append_char.c
OBJS			= ${SRCS:.c=.o}
INC				= -I./includes
LIBFT			= -L./libft -lft
LIBFT_INC		= -I./libft
LIBFT_LIB		= libft/libft.a
LIBFT_DIR		= libft
RM				= @rm -f
READLINE		= -L./readline -lreadline -lhistory -lncurses
READLINE_INC	= -I./
READLINE_LIB	= readline/libreadline.a
READLINE_DIR	= readline


.c.o:
				${CC} ${CFLAGS} ${INC} ${LIBFT_INC} ${READLINE_INC} -c $< -o ${<:.c=.o}

${NAME}:		${OBJS} ${LIBFT_LIB} ${READLINE_LIB}
				${CC} ${CFLAGS} -o ${NAME} ${OBJS} ${LIBFT} ${READLINE}

all:			${NAME}

${LIBFT_LIB}:
				@make bonus -C ${LIBFT_DIR}

${READLINE_LIB}:
				@cd $(READLINE_DIR); ./configure
				@make -C ${READLINE_DIR}

clean:
				${RM} ${OBJS}
				@make clean -C ${LIBFT_DIR}

fclean:			clean
				${RM} ${NAME} ${LIBFT_LIB}
				@make clean -C ${READLINE_DIR}

re:
				@make fclean
				@make all

.PHONY:			.c.o all clean fclean re
