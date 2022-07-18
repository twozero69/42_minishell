/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_and.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 07:03:32 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 07:04:50 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_and(t_ast *node, t_shell *shell, int pipe_flag)
{
	execute_ast(node->left_child, shell, pipe_flag);
	if (shell->exit_status != EXIT_SUCCESS)
		return ;
	execute_ast(node->right_child, shell, pipe_flag);
}
