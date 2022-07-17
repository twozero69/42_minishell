/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:20:47 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 11:21:44 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	my_dup(int *dst_fd, int src_fd, t_shell *shell)
{
	*dst_fd = dup(src_fd);
	if (*dst_fd == FAIL)
		exit_with_clib_error("init.c: dup", shell);
}

static void	init_env_list(char **envp, t_shell *shell)
{
	char	*equal;

	while (*envp != NULL)
	{
		equal = ft_strchr(*envp, '=');
		if (equal != NULL)
		{
			*equal = '\0';
			if (add_new_env(*envp, equal + 1, shell) == FAIL)
				exit_with_clib_error("init.c: malloc", shell);
			*equal = '=';
		}
		envp++;
	}
}

void	init(int argc, char **argv, char **envp, t_shell *shell)
{
	errno = 0;
	ft_memset(shell, 0, sizeof(t_shell));
	shell->stdin_fd = -1;
	shell->stdout_fd = -1;
	shell->status = SHELL_READLINE;
	shell->heredoc_line_count = 0;
	if (argc != 1 || argv == NULL || envp == NULL)
		exit_with_custom_error("argument error", shell);
	my_dup(&shell->stdin_fd, STDIN_FILENO, shell);
	my_dup(&shell->stdout_fd, STDOUT_FILENO, shell);
	init_env_list(envp, shell);
	if (set_shlvl(shell))
		exit_with_clib_error("init.c: malloc", shell);
}
