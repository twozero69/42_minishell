/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 23:08:13 by younglee          #+#    #+#             */
/*   Updated: 2022/07/08 04:33:45 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_not_set_error(char *key)
{
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(key, STDERR_FILENO);
	ft_putendl_fd(" not set", STDERR_FILENO);
}

static void	print_dir_error(char *dir)
{
	if (errno == 0)
		return ;
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(dir, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	errno = 0;
}

static int	change_directory(char *dir, t_shell *shell)
{
	t_env	*pwd;
	char	*pwd_value;
	char	*cwd;
	int		result;

	if (chdir(dir) == FAIL)
	{
		print_dir_error(dir);
		shell->exit_status = FAIL;
		return (SUCCESS);
	}
	pwd = get_env_from_key("PWD", shell->env_list);
	if (pwd != NULL)
		pwd_value = pwd->value;
	else
		pwd_value = NULL;
	if (add_env_with_value("OLDPWD", pwd_value, shell) == FAIL)
		return (FAIL);
	my_getcwd(&cwd, shell);
	result = add_env_with_value("PWD", cwd, shell);
	my_free((void **)&cwd);
	shell->exit_status = SUCCESS;
	return (result);
}

static int	change_directory_to_env(char *key, t_shell *shell)
{
	t_env	*env;

	env = get_env_from_key(key, shell->env_list);
	if (env == NULL || env->value == NULL)
	{
		print_not_set_error(key);
		shell->exit_status = EXIT_FAILURE;
		return (SUCCESS);
	}
	if (change_directory(env->value, shell) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	builtin_cd(char **argv, t_shell *shell)
{
	if (argv[1] == NULL)
	{
		if (change_directory_to_env("HOME", shell) == FAIL)
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
		if (change_directory_to_env("OLDPWD", shell))
			exit_with_clib_error("builtin_cd.c: malloc", shell);
		return ;
	}
	if (change_directory(argv[1], shell) == FAIL)
		exit_with_clib_error("builtin_cd.c: malloc", shell);
}
