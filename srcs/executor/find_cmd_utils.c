/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 20:54:12 by younglee          #+#    #+#             */
/*   Updated: 2022/07/18 22:48:19 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_with_permission_error(char *cmd, t_shell *shell)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd(": Permission denied", STDERR_FILENO);
	free_resources(shell);
	exit(EXIT_PERMISSION_DENIED);
}

void	exit_with_cmd_error(char *cmd, t_shell *shell, int file_exist_flag)
{
	if (file_exist_flag == TRUE)
		exit_with_permission_error(cmd, shell);
	ft_putstr_fd(cmd, STDERR_FILENO);
	ft_putendl_fd(": command not found", STDERR_FILENO);
	free_resources(shell);
	exit(EXIT_CMD_COMMAND_NOT_FOUND);
}

void	exit_with_file_error(char *cmd, t_shell *shell, int file_exist_flag)
{
	if (file_exist_flag == TRUE)
		exit_with_permission_error(cmd, shell);
	print_minishell_error(TRUE, cmd, strerror(errno));
	free_resources(shell);
	exit(EXIT_CMD_COMMAND_NOT_FOUND);
}
