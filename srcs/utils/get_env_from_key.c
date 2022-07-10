/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_from_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 23:13:28 by younglee          #+#    #+#             */
/*   Updated: 2022/07/04 23:23:40 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_env_from_key(char *key, t_list *env_list)
{
	t_env	*env;
	size_t	cmp_length;

	cmp_length = ft_strlen(key) + 1;
	while (env_list != NULL)
	{
		env = (t_env *)env_list->content;
		if (ft_strncmp(key, env->key, cmp_length) == 0)
			return (env);
		env_list = env_list->next;
	}
	return (NULL);
}
