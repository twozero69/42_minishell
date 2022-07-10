/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 18:13:50 by younglee          #+#    #+#             */
/*   Updated: 2022/07/08 22:32:14 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_dir_error(char *dir)
{
	if (errno == 0)
		return ;
	ft_putstr_fd("minishell: cd: ", STDERR_FILENO);
	ft_putstr_fd(dir, STDERR_FILENO);
	ft_putstr_fd(": ", STDERR_FILENO);
	ft_putendl_fd(strerror(errno), STDERR_FILENO);
	errno = 0;
}

static int	set_oldpwd(t_shell *shell)
{
	t_env	*pwd;
	char	*pwd_value;

	pwd = get_env_from_key("PWD", shell->env_list);
	if (pwd != NULL)
		pwd_value = pwd->value;
	else
		pwd_value = NULL;
	if (add_env_with_value("OLDPWD", pwd_value, shell) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

static int	set_pwd(t_shell *shell)
{
	char	*cwd;
	int		result;

	my_getcwd(&cwd, shell);
	result = add_env_with_value("PWD", cwd, shell);
	my_free((void **)&cwd);
	return (result);
}

int	change_directory(char *dir, t_shell *shell)
{
	if (*dir != '\0' && chdir(dir) == FAIL)
	{
		print_dir_error(dir);
		shell->exit_status = EXIT_FAILURE;
		return (SUCCESS);
	}
	if (set_oldpwd(shell) == FAIL)
		return (FAIL);
	if (set_pwd(shell) == FAIL)
		return (FAIL);
	shell->exit_status = EXIT_SUCCESS;
	return (SUCCESS);
}
