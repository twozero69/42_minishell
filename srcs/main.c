/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 00:25:16 by jubae             #+#    #+#             */
/*   Updated: 2022/06/28 18:38:16 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	readline_sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	ft_putchar_fd('\n', STDERR_FILENO);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

static void	wait_exec_sigint_handler(int signo)
{
	if (signo != SIGINT)
		return ;
	ft_putchar_fd('\n', STDERR_FILENO);
}

static int	my_readline(const char *prompt, t_shell *shell)
{
	signal(SIGINT, readline_sigint_handler);
	shell->line = readline(prompt);
	if (shell->line == NULL)
	{
		ft_putendl_fd("exit", STDERR_FILENO);
		return (FALSE);
	}
	signal(SIGINT, wait_exec_sigint_handler);
	shell->status = SHELL_LEXER;
	return (TRUE);
}

static void	reset_resources(t_shell *shell)
{
	my_dup2(shell->stdin_fd, STDIN_FILENO, shell);
	my_dup2(shell->stdout_fd, STDOUT_FILENO, shell);
	my_dup2(shell->stderr_fd, STDERR_FILENO, shell);
	my_free((void **)&shell->line);
	free_token_list(&shell->token_list);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;

	init(argc, argv, envp, &shell);
	while (shell.status == SHELL_READLINE && my_readline("$> ", &shell))
	{
		if (*shell.line != '\0')
			add_history(shell.line);
		if (shell.status == SHELL_LEXER && shell.line != NULL)
			lexer(shell.line, &shell);
		if (shell.status == SHELL_PARSER && shell.token_list != NULL)
			parser(&shell);

		//syntax check test
		shell.status = SHELL_READLINE;

		// if (shell.status == SHELL_EXPANDER)
		// 	expander();
		// if (shell.status == SHELL_EXECUTOR)
		// 	executor();
		reset_resources(&shell);
	}
	free_resources(&shell);
	return (EXIT_SUCCESS);
}
