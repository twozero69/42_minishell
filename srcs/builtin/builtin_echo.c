/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:05:55 by younglee          #+#    #+#             */
/*   Updated: 2022/07/02 19:03:20 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_argv(char **argv)
{
	int	idx;
	int	argv_num;

	argv_num = 0;
	while (argv[argv_num] != NULL)
		argv_num++;
	idx = 0;
	while (idx < argv_num)
	{
		ft_putstr_fd(argv[idx], STDOUT_FILENO);
		if (idx != argv_num - 1)
			ft_putchar_fd(' ', STDERR_FILENO);
		idx++;
	}
}

void	builtin_echo(char **argv, t_shell *shell)
{
	int	newline_flag;

	if (argv[1] != NULL && ft_strncmp(argv[1], "-n", 3) == 0)
	{
		newline_flag = FALSE;
		argv++;
	}
	else
		newline_flag = TRUE;
	print_argv(&argv[1]);
	if (newline_flag)
		ft_putchar_fd('\n', STDOUT_FILENO);
	shell->exit_status = EXIT_SUCCESS;
}
