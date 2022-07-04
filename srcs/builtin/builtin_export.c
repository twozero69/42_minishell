/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:56:45 by younglee          #+#    #+#             */
/*   Updated: 2022/07/04 22:50:15 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	return_false_with_identifier_error(char *arg)
{
	ft_putstr_fd("minishell: export: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": not a valid identifier", STDERR_FILENO);
	return (FALSE);
}

static int	check_arg(char *arg)
{
	if (ft_isalpha(*arg) == FALSE && *arg == '_')
		return (FALSE);
	while (*arg != '\0' && *arg != '=')
	{
		if (ft_isalnum(*arg) == FALSE && *arg != '_')
			return (FALSE);
		arg++;
	}
	return (TRUE);
}

static int	check_argv(char **argv)
{
	while (*argv != NULL)
	{
		if (check_arg(*argv) == FALSE)
			return (return_false_with_identifier_error(*argv));
		argv++;
	}
	return (TRUE);
}

void	builtin_export(char **argv, t_shell *shell)
{
	if (check_argv(&argv[1]) == FALSE)
	{
		shell->exit_status = EXIT_FAILURE;
		return ;
	}
	if (argv[1] == NULL)
	{
		if (print_export_list(shell) == FAIL)
			exit_with_clib_error("builtin_export.c: malloc: ", shell);
	}
	else
	{
		if (add_argv_to_envp(argv, shell) == FAIL)
			exit_with_clib_error("builtin_export.c: malloc: ", shell);
	}
	shell->exit_status = EXIT_SUCCESS;
}
