/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 00:56:45 by younglee          #+#    #+#             */
/*   Updated: 2022/07/05 05:42:01 by younglee         ###   ########seoul.kr  */
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
	char	*arg_head;

	arg_head = arg;
	if (ft_isalpha(*arg) == FALSE && *arg != '_')
		return (return_false_with_identifier_error(arg_head));
	arg++;
	while (*arg != '\0' && *arg != '=')
	{
		if (ft_isalnum(*arg) == FALSE && *arg != '_')
			return (return_false_with_identifier_error(arg_head));
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
			shell->exit_status = EXIT_FAILURE;
			return ;
		}
		if (add_arg_to_envp(argv[idx], shell) == FAIL)
			exit_with_clib_error("builtin_export.c: malloc: ", shell);
		idx++;
	}
	shell->exit_status = EXIT_SUCCESS;
}
