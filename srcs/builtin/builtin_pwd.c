/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 23:42:53 by younglee          #+#    #+#             */
/*   Updated: 2022/07/08 04:12:26 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	my_getcwd(char **cwd, t_shell *shell)
{
	*cwd = getcwd(NULL, 0);
	if (*cwd == NULL)
		exit_with_clib_error("builtin_pwd.c: getcwd", shell);
}

void	builtin_pwd(t_shell *shell)
{
	char	*cwd;

	my_getcwd(&cwd, shell);
	printf("%s\n", cwd);
	my_free((void **)&cwd);
	shell->exit_status = EXIT_SUCCESS;
}
