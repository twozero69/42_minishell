/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_envp_arr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 04:04:15 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 11:15:58 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	get_env_num(t_list *env_list)
{
	int		env_num;
	t_env	*env;

	env_num = 0;
	while (env_list != NULL)
	{
		env = (t_env *)env_list->content;
		if (env->value != NULL)
			env_num++;
		env_list = env_list->next;
	}
	return (env_num);
}

char	**make_envp_arr(t_list *env_list)
{
	int		env_num;
	char	**envp;
	int		idx;
	t_env	*env;
	char	*term;

	env_num = get_env_num(env_list);
	envp = (char **)malloc((env_num + 1) * sizeof(char *));
	idx = 0;
	while (env_list != NULL)
	{
		env = (t_env *)env_list->content;
		if (env->value != NULL)
		{
			term = ft_strjoin(env->key, "=");
			envp[idx] = ft_strjoin(term, env->value);
			idx++;
		}
		env_list = env_list->next;
	}
	envp[idx] = NULL;
	return (envp);
}
