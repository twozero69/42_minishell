/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:47:22 by younglee          #+#    #+#             */
/*   Updated: 2022/07/04 04:25:51 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	builtin_env(t_shell *shell)
{
	t_list	*env_list;
	t_env	*env;

	env_list = shell->env_list;
	while (env_list != NULL)
	{
		env = (t_env *)env_list->content;
		if (env->value != NULL)
			printf("%s=%s\n", env->key, env->value);
		env_list = env_list->next;
	}
}
