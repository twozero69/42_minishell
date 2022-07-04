/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:50:09 by younglee          #+#    #+#             */
/*   Updated: 2022/07/05 06:02:31 by younglee         ###   ########seoul.kr  */
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

	env = get_env_from_key(arg, shell->env_list);
	if (env == NULL)
	{
		if (add_new_env(arg, equal + 1, shell) == FAIL)
			return (FAIL);
	}
	else
	{
		if (ft_strncmp("_", env->key, 2) == 0)
			return (SUCCESS);
		my_free((void **)&env->value);
		env->value = ft_strdup(equal + 1);
		if (env->value == NULL)
			return (FAIL);
	}
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
		*equal = '\0';
		if (add_arg_with_value(arg, equal, shell))
			return (FAIL);
		*equal = '=';
	}
	return (SUCCESS);
}
