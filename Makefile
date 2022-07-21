# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/23 13:39:41 by younglee          #+#    #+#              #
#    Updated: 2022/07/19 17:55:57 by younglee         ###   ########seoul.kr   #
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
				srcs/utils/my_append_char.c \
				srcs/utils/my_append_char_lst.c \
				srcs/utils/my_append_str_lst.c \
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
				srcs/builtin/execute_builtin.c \
				srcs/expander/expander_util.c \
				srcs/expander/expander.c \
				srcs/expander/find_wilcard_lst.c \
				srcs/expander/find_wilcard.c \
				srcs/expander/set_expander_lst.c \
				srcs/expander/set_expander.c \
				srcs/expander/wilcard_match.c \
				srcs/expander/wilcard_util.c \
				srcs/executor/executor.c \
				srcs/executor/open_heredoc.c \
				srcs/executor/execute_ast.c \
				srcs/executor/execute_cmd.c \
				srcs/executor/execute_pipe.c \
				srcs/executor/execute_and.c \
				srcs/executor/execute_or.c \
				srcs/executor/execute_input_redir.c \
				srcs/executor/execute_heredoc_redir.c \
				srcs/executor/execute_output_redir.c \
				srcs/executor/execute_append_redir.c \
				srcs/executor/execute_external_cmd.c \
				srcs/executor/make_envp_arr.c \
				srcs/executor/find_cmd.c \
				srcs/executor/find_cmd_utils.c \
				srcs/executor/get_child_exit_status.c
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
