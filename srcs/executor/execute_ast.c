/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 05:44:03 by younglee          #+#    #+#             */
/*   Updated: 2022/07/16 06:21:10 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	excute_ast(t_ast *node, t_shell *shell)
{
	if (node == NULL || shell->status != SHELL_EXECUTOR)
		return ;
	// if (node->type == NODE_CMD)
	// 	execute_cmd();
	// else if (node->type == NODE_PIPE)
	// 	execute_pipe();
	// else if (node->type == NODE_AND)
	// 	execute_and();
	// else if (node->type == NODE_OR)
	// 	execute_or();
	// else if (node->type == NODE_INPUT_REDIR)
	// 	execute_input_redir();
	// else if (node->type == NODE_HEREDOC_REDIR)
	// 	execute_heredoc_redir();
	// else if (node->type == NODE_OUTPUT_REDIR)
	// 	execute_output_redir();
	// else if (node->type == NODE_APPEND_REDIR)
	// 	execute_append_redir();
}
