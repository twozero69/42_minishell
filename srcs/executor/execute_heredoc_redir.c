/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_heredoc_redir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 09:18:57 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 11:17:06 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_heredoc_redir(t_ast *node, t_shell *shell, int pipe_flag)
{
	set_input_redir(node->left_child, node->pipe[0]);
	if (pipe_flag == FALSE)
		my_close(&node->pipe[1]);
	execute_ast(node->left_child, shell, pipe_flag);
	close_pipe(node->pipe);
}
