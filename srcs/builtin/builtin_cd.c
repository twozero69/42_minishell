/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:08:13 by younglee          #+#    #+#             */
/*   Updated: 2022/07/08 22:31:17 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_not_set_error(char *key)
{
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(key, STDERR_FILENO);
	ft_putendl_fd(" not set", STDERR_FILENO);
}

static int	change_directory_to_home(t_shell *shell)
{
	t_env	*env;

	env = get_env_from_key("HOME", shell->env_list);
	if (env == NULL || env->value == NULL)
	{
		print_not_set_error("HOME");
		shell->exit_status = EXIT_FAILURE;
		return (SUCCESS);
	}
	if (change_directory(env->value, shell) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	change_directory_to_oldpwd(t_shell *shell)
{
	t_env	*env;

	env = get_env_from_key("OLDPWD", shell->env_list);
	if (env == NULL || env->value == NULL)
	{
		print_not_set_error("OLDPWD");
		shell->exit_status = EXIT_FAILURE;
		return (SUCCESS);
	}
	if (env->value[0] != '\0' && chdir(env->value) == FAIL)
	{
		print_dir_error(env->value);
		shell->exit_status = EXIT_FAILURE;
		return (SUCCESS);
	}
	if (isatty(STDOUT_FILENO) == TRUE)
		ft_putendl_fd(env->value, STDOUT_FILENO);
	if (change_directory(env->value, shell) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	builtin_cd(char **argv, t_shell *shell)
{
	if (argv[1] == NULL)
	{
		if (change_directory_to_home(shell) == FAIL)
			exit_with_clib_error("builtin_cd.c: malloc", shell);
		return ;
	}
	if (argv[2] != NULL)
	{
		print_minishell_error(TRUE, "cd", "too many arguments");
		shell->exit_status = EXIT_FAILURE;
		return ;
	}
	if (ft_strncmp("-", argv[1], 2) == 0)
	{
		if (change_directory_to_oldpwd(shell))
			exit_with_clib_error("builtin_cd.c: malloc", shell);
		return ;
	}
	if (change_directory(argv[1], shell) == FAIL)
		exit_with_clib_error("builtin_cd.c: malloc", shell);
}
