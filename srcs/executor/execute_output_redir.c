/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_output_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:32:18 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 10:27:23 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_output_redir(t_ast *node, int redir_file_fd)
{
	if (node == NULL)
		return ;
	if (node->type == NODE_CMD)
		node->cmd_out_fd = redir_file_fd;
	set_output_redir(node->left_child, redir_file_fd);
	set_output_redir(node->right_child, redir_file_fd);
}

void	execute_output_redir(t_ast *node, t_shell *shell, int pipe_flag)
{
	char	*file_path;

	file_path = node->right_child->argv[0];
	node->redir_file_fd = open(file_path, NORMAL_OPEN, 0644);
	if (node->redir_file_fd == FAIL)
	{
		print_minishell_error(TRUE, file_path, strerror(errno));
		return ;
	}
	set_output_redir(node->left_child, node->redir_file_fd);
	execute_ast(node->left_child, shell, pipe_flag);
	my_close(&node->redir_file_fd);
}
