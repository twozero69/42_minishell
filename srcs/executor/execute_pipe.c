/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_pipe.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 14:50:29 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 11:27:19 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_pipe_entrance(t_ast *node, int pipe_entrance_fd)
{
	if (node == NULL)
		return ;
	if (node->type == NODE_CMD)
		node->cmd_out_fd = pipe_entrance_fd;
	set_pipe_entrance(node->left_child, pipe_entrance_fd);
	set_pipe_entrance(node->right_child, pipe_entrance_fd);
}

static void	set_pipe_exit(t_ast *node, int pipe_exit_fd)
{
	if (node == NULL)
		return ;
	if (node->type == NODE_CMD)
		node->cmd_in_fd = pipe_exit_fd;
	set_pipe_exit(node->left_child, pipe_exit_fd);
	set_pipe_exit(node->right_child, pipe_exit_fd);
}

static void	wait_pipeline(t_ast *node, t_shell *shell)
{
	int	status;

	if (node == NULL)
		return ;
	if (node->type == NODE_CMD)
	{
		waitpid(node->cmd_pid, &status, 0);
		shell->exit_status = get_child_exit_status(status);
	}
	wait_pipeline(node->left_child, shell);
	wait_pipeline(node->right_child, shell);
}

void	execute_pipe(t_ast *node, t_shell *shell, int pipe_flag)
{
	if (pipe(node->pipe) == FAIL)
		exit_with_clib_error("execute_pipe.c: pipe", shell);
	set_pipe_entrance(node->left_child, node->pipe[1]);
	set_pipe_exit(node->right_child, node->pipe[0]);
	execute_ast(node->left_child, shell, TRUE);
	execute_ast(node->right_child, shell, TRUE);
	close_pipe(node->pipe);
	if (pipe_flag == FALSE)
		wait_pipeline(node, shell);
}
