/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_external_cmd.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 22:14:54 by younglee          #+#    #+#             */
/*   Updated: 2022/07/21 18:12:00 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_external_cmd_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	execute_external_cmd(t_ast *node, t_shell *shell)
{
	char	*path;
	char	**envp;
	char	**argv;

	errno = 0;
	path = find_cmd(node->argv[0], shell);
	envp = make_envp_arr(shell->env_list);
	argv = node->argv;
	node->argv = NULL;
	set_redir(node, shell);
	set_external_cmd_signal();
	free_resources(shell);
	execve(path, argv, envp);
	exit(EXIT_SUCCESS);
}
