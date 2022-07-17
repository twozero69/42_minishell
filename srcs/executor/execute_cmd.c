/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:57:19 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 10:26:52 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_redir(t_ast *node, t_shell *shell)
{
	if (node->cmd_in_fd != -1)
		my_dup2(node->cmd_in_fd, STDIN_FILENO, shell);
	if (node->cmd_out_fd != -1)
		my_dup2(node->cmd_out_fd, STDOUT_FILENO, shell);
}

static void	reset_redir(t_shell *shell)
{
	my_dup2(shell->stdin_fd, STDIN_FILENO, shell);
	my_dup2(shell->stdout_fd, STDOUT_FILENO, shell);
}

static void	execute_pipe_cmd(t_ast *node, t_shell *shell)
{
	node->cmd_pid = fork();
	if (node->cmd_pid == 0 && check_builtin(node->argv) == TRUE)
	{
		set_redir(node, shell);
		execute_builtin(node->argv, shell);
		free_resources(shell);
		exit(shell->exit_status);
	}
	if (node->cmd_pid == 0 && check_builtin(node->argv) == FALSE)
		execute_external_cmd(node, shell);
}

static void	execute_simple_cmd(t_ast *node, t_shell *shell)
{
	int	status;

	if (check_builtin(node->argv) == TRUE)
	{
		set_redir(node, shell);
		execute_builtin(node->argv, shell);
		reset_redir(shell);
	}
	else
	{
		node->cmd_pid = fork();
		if (node->cmd_pid == 0)
			execute_external_cmd(node, shell);
		waitpid(node->cmd_pid, &status, 0);
		shell->exit_status = get_child_exit_status(status);
	}
}

void	execute_cmd(t_ast *node, t_shell *shell, int pipe_flag)
{
	if (pipe_flag == TRUE)
		execute_pipe_cmd(node, shell);
	else
		execute_simple_cmd(node, shell);
}
