/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:44:03 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 06:59:00 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_ast(t_ast *node, t_shell *shell, int pipe_flag)
{
	if (node == NULL || shell->status != SHELL_EXECUTOR)
		return ;
	if (node->type == NODE_CMD)
		execute_cmd(node, shell, pipe_flag);
	else if (node->type == NODE_PIPE)
		execute_pipe(node, shell, pipe_flag);
	else if (node->type == NODE_AND)
		execute_and(node, shell, pipe_flag);
	else if (node->type == NODE_OR)
		execute_or(node, shell, pipe_flag);
	else if (node->type == NODE_INPUT_REDIR)
		execute_input_redir(node, shell, pipe_flag);
	else if (node->type == NODE_HEREDOC_REDIR)
		execute_heredoc_redir(node, shell, pipe_flag);
	else if (node->type == NODE_OUTPUT_REDIR)
		execute_output_redir(node, shell, pipe_flag);
	else if (node->type == NODE_APPEND_REDIR)
		execute_append_redir(node, shell, pipe_flag);
}
