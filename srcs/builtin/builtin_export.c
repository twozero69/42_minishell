/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:56:45 by younglee          #+#    #+#             */
/*   Updated: 2022/07/08 02:19:50 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_identifier_error(char *arg)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
}

static int	check_arg(char *arg)
{
	if (ft_isalpha(*arg) == FALSE && *arg != '_')
		return (FALSE);
	arg++;
	while (*arg != '\0' && *arg != '=')
	{
		if (ft_isalnum(*arg) == FALSE && *arg != '_')
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

void	builtin_export(char **argv, t_shell *shell)
{
	int		idx;

	if (argv[1] == NULL)
	{
		if (print_export_list(shell) == FAIL)
			exit_with_clib_error("builtin_export.c: malloc: ", shell);
		shell->exit_status = EXIT_SUCCESS;
		return ;
	}
	idx = 1;
	while (argv[idx] != NULL)
	{
		if (check_arg(argv[idx]) == FALSE)
		{
			print_identifier_error(argv[idx]);
			shell->exit_status = EXIT_FAILURE;
			return ;
		}
		if (add_env_to_envp(argv[idx], shell) == FAIL)
			exit_with_clib_error("builtin_export.c: malloc: ", shell);
		idx++;
	}
	shell->exit_status = EXIT_SUCCESS;
}
