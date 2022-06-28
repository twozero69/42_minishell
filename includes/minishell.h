/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:24:41 by jubae             #+#    #+#             */
/*   Updated: 2022/06/28 19:59:09 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>
# include "readline/readline.h"
# include "readline/history.h"
# include "libft.h"

# define TRUE 1
# define FALSE 0
# define SUCCESS 0
# define FAIL -1

# define META_CHARACTERS " \t\n|&()<>"
# define OPERATOR_CHARACTERS "|&()<>"
# define SPACE_CHARACTERS " \t\n"
# define DOUBLE_CHARACTERS "|<>"
# define QUOTE_CHARACTERS "'\""

# define EXIT_SYNTEX_ERROR 2
# define EXIT_

enum e_token
{
	TK_WORD,
	TK_PIPE,
	TK_AND,
	TK_OR,
	TK_INPUT_REDIR,
	TK_HEREDOC_REDIR,
	TK_OUTPUT_REDIR,
	TK_APPEND_REDIR,
	TK_LEFT_PARENTHESIS,
	TK_RIGHT_PARENTHESIS,
	TK_INVALID
};

typedef struct s_token
{
	enum e_token	type;
	char			*str;
}	t_token;

enum e_ast_node
{
	NODE_NONTERMINAL,
	NODE_TERMINAL,
	NODE_INVALID
};

typedef struct s_ast_node
{
	enum e_ast_node		type;
	struct s_ast_node	*left_child;
	struct s_ast_node	*right_child;
	t_list				*token_list;
}	t_ast_node;

typedef struct s_env
{
	char	*key;
	char	*value;
}	t_env;

enum e_shell
{
	SHELL_READLINE,
	SHELL_LEXER,
	SHELL_PARSER,
	SHELL_EXPANDER,
	SHELL_EXECUTOR
};

typedef struct s_shell
{
	int				exit_status;
	int				stdin_fd;
	int				stdout_fd;
	int				stderr_fd;
	t_list			*env_list;
	enum e_shell	status;
	char			*line;
	t_list			*token_list;
	t_ast_node		*ast;
}	t_shell;

// utils/exit_with_error.c
void	exit_with_error(char *error_msg, t_shell *shell);

// utils/print_minishell_error.c
void	print_minishell_error(int shell_name_flag, char *msg1, char *msg2);

// utils/free_resources.c
void	free_resources(t_shell *shell);

// utils/free_token_list.c
void	free_token_list(t_list **token_list);

// utils/init.c
void	init(int argc, char **argv, char **envp, t_shell *shell);

// utils/add_new_env.c
int		add_new_env(char *key, char *value, t_shell *shell);

// utils/my_close.c
void	my_close(int *fd);

// utils/my_free.c
void	my_free(void **mem);

// utils/my_dup2.c
void	my_dup2(int old_fd, int new_fd, t_shell *shell);

// lexer/lexer.c
void	lexer(char *line, t_shell *shell);

// lexer/check_char.c
int		check_char(char c, char *search_str);

// lexer/add_new_token.c
int		add_new_token(char *line, int length, enum e_token type, t_shell *sh);

// parser/parser.c
void	parser(t_shell *shell);

// parser/check_syntax.c
int		check_syntax(t_list *token_list);

// parser/print_syntax_error.c
void	print_syntax_error(char *token_str);

// parser/check_front_and_back_tokens.c
int		check_front_and_back_tokens(t_list *curr);

// parser/check_operator.c
int		check_operator(enum e_token type);

// parser/check_redir.c
int		check_redir(enum e_token type);

#endif
