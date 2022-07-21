/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:59:16 by younglee          #+#    #+#             */
/*   Updated: 2022/07/21 18:08:46 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	executor_signal_handler(int signo)
{
	if (signo == SIGINT)
		ft_putchar_fd('\n', STDERR_FILENO);
	else if (signo == SIGQUIT)
		ft_putendl_fd("Quit (core dumped)", STDERR_FILENO);
}

void	executor(t_shell *shell)
{
	signal(SIGINT, executor_signal_handler);
	open_heredoc(shell->ast, shell);
	if (shell->status != SHELL_EXECUTOR)
		return ;
	signal(SIGQUIT, executor_signal_handler);
	execute_ast(shell->ast, shell, FALSE);
	if (shell->status != SHELL_EXECUTOR)
		return ;
	free_ast(&shell->ast);
	shell->status = SHELL_READLINE;
}
