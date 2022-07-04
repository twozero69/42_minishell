/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:50:09 by younglee          #+#    #+#             */
/*   Updated: 2022/07/05 05:38:40 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_arg_without_value(char *arg, t_shell *shell)
{
	t_env	*env;

	env = get_env_from_key(arg, shell->env_list);
	if (env == NULL)
	{
		if (add_new_env(arg, NULL, shell) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

static int	add_arg_with_value(char *arg, char *equal, t_shell *shell)
{
	t_env	*env;

	*equal = '\0';
	env = get_env_from_key(arg, shell->env_list);
	if (env == NULL)
	{
		if (add_new_env(arg, equal + 1, shell) == FAIL)
			return (FAIL);
	}
	else
	{
		my_free((void **)&env->value);
		env->value = ft_strdup(equal + 1);
		if (env->value == NULL)
			return (FAIL);
	}
	*equal = '=';
	return (SUCCESS);
}

int	add_arg_to_envp(char *arg, t_shell *shell)
{
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (equal == NULL)
	{
		if (add_arg_without_value(arg, shell))
			return (FAIL);
	}
	else
	{
		if (add_arg_with_value(arg, equal, shell))
			return (FAIL);
	}
	return (SUCCESS);
}
