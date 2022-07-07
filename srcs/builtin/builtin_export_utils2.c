/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export_utils2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 22:50:09 by younglee          #+#    #+#             */
/*   Updated: 2022/07/08 03:43:47 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_env_without_value(char *key, t_shell *shell)
{
	t_env	*env;

	env = get_env_from_key(key, shell->env_list);
	if (env == NULL)
	{
		if (add_new_env(key, NULL, shell) == FAIL)
			return (FAIL);
	}
	return (SUCCESS);
}

int	add_env_with_value(char *key, char *value, t_shell *shell)
{
	t_env	*env;

	env = get_env_from_key(key, shell->env_list);
	if (env == NULL)
	{
		if (add_new_env(key, value, shell) == FAIL)
			return (FAIL);
	}
	else
	{
		my_free((void **)&env->value);
		if (value != NULL)
		{
			env->value = ft_strdup(value);
			if (env->value == NULL)
				return (FAIL);
		}
		else
			env->value = NULL;
	}
	return (SUCCESS);
}

int	add_env_to_envp(char *arg, t_shell *shell)
{
	char	*equal;

	equal = ft_strchr(arg, '=');
	if (equal == NULL)
	{
		if (add_env_without_value(arg, shell))
			return (FAIL);
	}
	else
	{
		*equal = '\0';
		if (add_env_with_value(arg, equal + 1, shell))
			return (FAIL);
		*equal = '=';
	}
	return (SUCCESS);
}
