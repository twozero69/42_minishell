/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:25:16 by jubae             #+#    #+#             */
/*   Updated: 2022/07/17 18:31:14 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	readline_signal_handler(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', STDERR_FILENO);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

static void	wait_exec_signal_handler(int signo)
{
	if (signo == SIGINT)
		ft_putchar_fd('\n', STDERR_FILENO);
	else if (signo == SIGQUIT)
		ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
}

static int	my_readline(const char *prompt, t_shell *shell)
{
	signal(SIGINT, readline_signal_handler);
	signal(SIGQUIT, SIG_IGN);
	shell->line = readline(prompt);
	if (shell->line == NULL)
	{
		// ft_putstr_fd("\x1b[1A", STDERR_FILENO); // maybe not necessary
		// ft_putstr_fd("\033[3C", STDERR_FILENO);
		if (isatty(STDERR_FILENO))
			ft_putendl_fd("exit", STDERR_FILENO);
		return (FALSE);
	}
	signal(SIGINT, wait_exec_signal_handler);
	signal(SIGQUIT, wait_exec_signal_handler);
	shell->status = SHELL_LEXER;
	return (TRUE);
}

static void	reset_resources(t_shell *shell)
{
	my_dup2(shell->stdin_fd, STDIN_FILENO, shell);
	my_dup2(shell->stdout_fd, STDOUT_FILENO, shell);
	my_free((void **)&shell->line);
	free_token_list(&shell->token_list);
	free_ast(&shell->ast);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	init(argc, argv, envp, &shell);
	while (shell.status == SHELL_READLINE && my_readline("minishell$ ", &shell))
	{
		if (*shell.line != '\0')
			add_history(shell.line);
		if (shell.status == SHELL_LEXER)
			lexer(shell.line, &shell);
		if (shell.status == SHELL_PARSER)
			parser(&shell);
		if (shell.status == SHELL_EXPANDER)
			expander(&shell);
		if (shell.status == SHELL_EXECUTOR)
			executor(&shell);
		reset_resources(&shell);
	}
	free_resources(&shell);
	return (EXIT_SUCCESS);
}
