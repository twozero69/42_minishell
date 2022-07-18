/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_append_redir.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:50:12 by younglee          #+#    #+#             */
/*   Updated: 2022/07/18 19:40:41 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_append_redir(t_ast *node, t_shell *shell, int pipe_flag)
{
	char	*file_path;

	file_path = node->right_child->argv[0];
	node->redir_file_fd = open(file_path, APPEND_OPEN, 0644);
	if (node->redir_file_fd == FAIL)
	{
		print_minishell_error(TRUE, file_path, strerror(errno));
		shell->exit_status = EXIT_NO_SUCH_FILE;
		return ;
	}
	shell->exit_status = EXIT_SUCCESS;
	set_output_redir(node->left_child, node->redir_file_fd);
	execute_ast(node->left_child, shell, pipe_flag);
	my_close(&node->redir_file_fd);
}
