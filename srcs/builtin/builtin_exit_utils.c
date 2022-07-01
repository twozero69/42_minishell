/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 00:55:00 by younglee          #+#    #+#             */
/*   Updated: 2022/07/02 03:22:33 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_sign(char c, long *sign_flag)
{
	if (c == '+')
		return (TRUE);
	if (c == '-')
	{
		*sign_flag *= -1;
		return (TRUE);
	}
	return (FALSE);
}

long	my_atoi(const char *arg)
{
	long	sign_flag;
	long	number;

	sign_flag = 1;
	if (check_sign(*arg, &sign_flag))
		arg++;
	number = 0;
	while (*arg != '\0')
	{
		number = 10 * number + sign_flag * (*arg - '0');
		arg++;
	}
	return (number);
}

void	exit_without_error(int exit_status)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		ft_putendl_fd("exit", STDERR_FILENO);
	exit(exit_status);
}

int	return_false_with_numeric_error(char *arg, t_shell *shell)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		ft_putendl_fd("exit", STDERR_FILENO);
	ft_putstr_fd("minishell: exit: ", STDERR_FILENO);
	ft_putstr_fd(arg, STDERR_FILENO);
	ft_putendl_fd(": numeric argument required", STDERR_FILENO);
	shell->exit_status = EXIT_NOT_NUMERIC_ARGUMENTS;
	return (FALSE);
}

int	return_false_with_too_many_error(t_shell *shell)
{
	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO))
		ft_putendl_fd("exit", STDERR_FILENO);
	print_minishell_error(TRUE, "exit", "too many arguments");
	shell->exit_status = EXIT_TOO_MANY_ARGUMENTS;
	return (FALSE);
}
