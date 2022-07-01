/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 21:37:09 by younglee          #+#    #+#             */
/*   Updated: 2022/07/02 03:24:24 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_arg_numeric(char *arg, t_shell *shell)
{
	char	*term;

	term = arg;
	if ((*arg == '+' || *arg == '-') && ft_isdigit(*(arg + 1)))
		arg++;
	while (*arg != '\0')
	{
		if (ft_isdigit(*arg) == FALSE)
			return (return_false_with_numeric_error(term, shell));
		arg++;
	}
	return (TRUE);
}

static int	check_arg_limit(char *arg, t_shell *shell)
{
	size_t	arg_len;
	size_t	cmp_len;
	char	sign;
	char	*term;

	term = arg;
	sign = '+';
	if (*arg == '-' || *arg == '+')
	{
		sign = *arg;
		arg++;
	}
	while (*arg == '0')
		arg++;
	arg_len = ft_strlen(arg);
	cmp_len = ft_strlen("9223372036854775807");
	if (arg_len < cmp_len)
		return (TRUE);
	if (arg_len > cmp_len)
		return (return_false_with_numeric_error(term, shell));
	if (sign == '+' && ft_strncmp(arg, "9223372036854775807", cmp_len + 1) <= 0)
		return (TRUE);
	if (sign == '-' && ft_strncmp(arg, "9223372036854775808", cmp_len + 1) <= 0)
		return (TRUE);
	return (return_false_with_numeric_error(term, shell));
}

static int	check_arg(char *arg, t_shell *shell)
{
	if (check_arg_numeric(arg, shell) == FALSE)
		return (FALSE);
	if (check_arg_limit(arg, shell) == FALSE)
		return (FALSE);
	return (TRUE);
}

static int	check_argv(char **argv, t_shell *shell)
{
	if (argv[1] == NULL)
		return (TRUE);
	if (check_arg(argv[1], shell) == FALSE)
		return (FALSE);
	if (argv[2] == NULL)
		return (TRUE);
	return (return_false_with_too_many_error(shell));
}

void	builtin_exit(char **argv, t_shell *shell)
{
	if (check_argv(argv, shell) == FALSE)
		exit(shell->exit_status);
	if (argv[1] == NULL)
		exit_without_error(0);
	exit_without_error(my_atoi(argv[1]) % 256);
}
