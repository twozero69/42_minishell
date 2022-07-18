/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 23:59:16 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 11:37:25 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	executor(t_shell *shell)
{
	open_heredoc(shell->ast, shell);
	if (shell->status != SHELL_EXECUTOR)
		return ;
	execute_ast(shell->ast, shell, FALSE);
	if (shell->status != SHELL_EXECUTOR)
		return ;
	free_ast(&shell->ast);
	shell->status = SHELL_READLINE;
}
