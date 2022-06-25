/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_new_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 01:47:31 by younglee          #+#    #+#             */
/*   Updated: 2022/06/26 04:12:43 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	add_new_env_four(t_env *env, t_shell *shell)
{
	t_list	*new_list;

	new_list = ft_lstnew((void *)env);
	if (new_list == NULL)
		return (FAIL);
	ft_lstadd_back(&shell->env_list, new_list);
	return (SUCCESS);
}

static int	add_new_env_three(char *value, t_env *env, t_shell *shell)
{
	env->value = ft_strdup(value);
	if (env->value == NULL)
		return (FAIL);
	if (add_new_env_four(env, shell) == FAIL)
	{
		my_free((void **)&env->value);
		return (FAIL);
	}
	return (SUCCESS);
}

static int	add_new_env_two(char *key, char *value, t_env *env, t_shell *shell)
{
	env->key = ft_strdup(key);
	if (env->key == NULL)
		return (FAIL);
	if (add_new_env_three(value, env, shell) == FAIL)
	{
		my_free((void **)&env->key);
		return (FAIL);
	}
	return (SUCCESS);
}

int	add_new_env(char *key, char *value, t_shell *shell)
{
	t_env	*env;

	env = (t_env *)malloc(sizeof(t_env));
	if (env == NULL)
		return (FAIL);
	ft_memset(env, 0, sizeof(t_env));
	if (add_new_env_two(key, value, env, shell) == FAIL)
	{
		my_free((void **)&env);
		return (FAIL);
	}
	return (SUCCESS);
}
