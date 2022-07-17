/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_input_redir.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 07:10:03 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 09:25:58 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_input_redir(t_ast *node, int redir_file_fd)
{
	if (node == NULL)
		return ;
	if (node->type == NODE_CMD)
		node->cmd_in_fd = redir_file_fd;
	set_input_redir(node->left_child, redir_file_fd);
	set_input_redir(node->right_child, redir_file_fd);
}

void	execute_input_redir(t_ast *node, t_shell *shell, int pipe_flag)
{
	char	*file_path;

	file_path = node->right_child->argv[0];
	node->redir_file_fd = open(file_path, O_RDONLY);
	if (node->redir_file_fd == FAIL)
	{
		print_minishell_error(TRUE, file_path, strerror(errno));
		return ;
	}
	set_input_redir(node->left_child, node->redir_file_fd);
	execute_ast(node->left_child, shell, pipe_flag);
	my_close(&node->redir_file_fd);
}
