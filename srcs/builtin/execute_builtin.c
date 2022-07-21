/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_builtin.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 04:23:57 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 10:23:52 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_builtin(char **argv)
{
	size_t	cmp_len;

	if (argv[0] == NULL)
		return (FALSE);
	cmp_len = ft_strlen(argv[0]);
	if (ft_strncmp("exit", argv[0], cmp_len + 1) == 0)
		return (TRUE);
	if (ft_strncmp("echo", argv[0], cmp_len + 1) == 0)
		return (TRUE);
	if (ft_strncmp("pwd", argv[0], cmp_len + 1) == 0)
		return (TRUE);
	if (ft_strncmp("env", argv[0], cmp_len + 1) == 0)
		return (TRUE);
	if (ft_strncmp("export", argv[0], cmp_len + 1) == 0)
		return (TRUE);
	if (ft_strncmp("unset", argv[0], cmp_len + 1) == 0)
		return (TRUE);
	if (ft_strncmp("cd", argv[0], cmp_len + 1) == 0)
		return (TRUE);
	return (FALSE);
}

void	execute_builtin(char **argv, t_shell *shell)
{
	size_t	cmp_len;

	if (argv[0] == NULL)
		return ;
	cmp_len = ft_strlen(argv[0]);
	if (ft_strncmp("exit", argv[0], cmp_len + 1) == 0)
		builtin_exit(argv, shell);
	else if (ft_strncmp("echo", argv[0], cmp_len + 1) == 0)
		builtin_echo(argv, shell);
	else if (ft_strncmp("pwd", argv[0], cmp_len + 1) == 0)
		builtin_pwd(shell);
	else if (ft_strncmp("env", argv[0], cmp_len + 1) == 0)
		builtin_env(shell);
	else if (ft_strncmp("export", argv[0], cmp_len + 1) == 0)
		builtin_export(argv, shell);
	else if (ft_strncmp("unset", argv[0], cmp_len + 1) == 0)
		builtin_unset(argv, shell);
	else if (ft_strncmp("cd", argv[0], cmp_len + 1) == 0)
		builtin_cd(argv, shell);
}
