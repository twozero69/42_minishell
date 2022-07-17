/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:24:41 by jubae             #+#    #+#             */
/*   Updated: 2022/07/18 02:56:41 by jubae            ###   ########.fr       */
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
# include <term.h>
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
# define DOUBLE_CHARACTERS "|&<>"
# define QUOTE_CHARACTERS "'\""

// parser exit status
# define EXIT_SYNTEX_ERROR 2

// builtin exit status
# ifdef __linux__
#  define EXIT_TOO_MANY_ARGUMENTS 1
#  define EXIT_NOT_NUMERIC_ARGUMENTS 2
# endif
# ifdef __APPLE__
#  define EXIT_TOO_MANY_ARGUMENTS 1
#  define EXIT_NOT_NUMERIC_ARGUMENTS 255
# endif

enum e_token
{
	TK_INVALID,
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
	TK_PARSER_VISIT
};

typedef struct s_token
{
	enum e_token	type;
	char			*str;
}	t_token;

enum e_ast
{
	NODE_INVALID,
	NODE_CMD,
	NODE_PIPE,
	NODE_AND,
	NODE_OR,
	NODE_INPUT_REDIR,
	NODE_HEREDOC_REDIR,
	NODE_OUTPUT_REDIR,
	NODE_APPEND_REDIR,
	NODE_REDIR_FILE
};

typedef struct s_ast
{
	enum e_ast		type;
	struct s_ast	*left_child;
	struct s_ast	*right_child;
	char			**argv;
}	t_ast;

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
	t_ast			*ast;
}	t_shell;

// utils/exit_with_custom_error.c
void	exit_with_custom_error(char *error_msg, t_shell *shell);

// utils/exit_with_clib_error.c
void	exit_with_clib_error(char *error_msg, t_shell *shell);

// utils/print_minishell_error.c
void	print_minishell_error(int shell_name_flag, char *msg1, char *msg2);

// utils/free_resources.c
void	free_resources(t_shell *shell);

// utils/free_token_list.c
void	free_token_list(t_list **token_list);

// utils/free_ast.c
void	free_ast(t_ast **ast);

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

// utils/get_env_from_key.c
t_env	*get_env_from_key(char *key, t_list *env_list);

// utils/set_shlvl.c
int		set_shlvl(t_shell *shell);

// utils/my_append_char.c
char	*my_append_char(char *before, char c);

// utils/my_append_char_lst.c
void	my_append_char_lst(t_list *lst, char c);

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

// parser/find_control_operator.c
int		find_control_operator(t_list *tk_list, t_list **junc, enum e_ast *type);

// parser/find_redir_operator.c
int		find_redir_operator(t_list *tk_list, t_list **junc, enum e_ast *type);

// parser/get_right_parenthesis.c
t_list	*get_right_parenthesis(t_list *token_list);

// parser/make_ast_node.c
int		make_ast_node(t_list *token_list, t_ast *node);

// parser/make_child_node.c
int		make_child_node(t_ast *node);

// parser/make_control_node.c
int		make_control_node(t_list *l_list, t_list *r_list, t_ast *node);

// parser/make_redir_node.c
int		make_redir_node(t_list *l_list, t_list *r_list, t_ast *node);

// parser/make_cmd_node.c
int		make_cmd_node(t_list *token_list, t_ast *node);

// builtin/builtin_exit.c
void	builtin_exit(char **argv, t_shell *shell);

// builtin/builtin_exit_utils.c
long	my_atoi(const char *arg);
void	exit_without_error(int exit_status, t_shell *shell);
int		return_false_with_numeric_error(char *arg, t_shell *shell);
int		return_false_with_too_many_error(t_shell *shell);

// builtin/builtin_echo.c
void	builtin_echo(char **argv, t_shell *shell);

// builtin/builtin_pwd.c
void	builtin_pwd(t_shell *shell);
void	my_getcwd(char **cwd, t_shell *shell);

// builtin/builtin_env.c
void	builtin_env(t_shell *shell);

// builtin/builtin_export.c
void	builtin_export(char **argv, t_shell *shell);

// builtin/builtin_export_utils.c
int		print_export_list(t_shell *shell);

// builtin/builtin_export_utils2.c
int		add_env_to_envp(char *arg, t_shell *shell);
int		add_env_with_value(char *key, char *value, t_shell *shell);

// builtin/builtin_unset.c
void	builtin_unset(char **argv, t_shell *shell);

// builtin/builtin_cd.c
void	builtin_cd(char **argv, t_shell *shell);

// builtin/builtin_cd_utils.c
int		change_directory(char *dir, t_shell *shell);
void	print_dir_error(char *dir);

// builtin/builtin_executor.c
void	builtin_executor(char **argv, t_shell *shell);

// expander/expander.c
void	tda_free(char **tda);
int		get_lst_num(t_list *ret);
void	expander(t_shell *shell);
void	find_wilcard_lst(char *argv, t_list *ret, int i);
void	find_wilcard(char *argv, char **result, int i);
void	set_expander_lst(char *argv, t_list *env_list, t_list *ret);
char	*set_expander(char *argv, t_list *env_list);

#endif
