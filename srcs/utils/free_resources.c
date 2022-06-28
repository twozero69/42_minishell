/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:13:42 by younglee          #+#    #+#             */
/*   Updated: 2022/06/26 04:11:52 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_env_list(t_list **env_list)
{
	t_list	*curr;
	t_list	*next;
	t_env	*env;

	if (*env_list == NULL)
		return ;
	curr = *env_list;
	while (curr != NULL)
	{
		next = curr->next;
		env = (t_env *)curr->content;
		my_free((void **)&env->key);
		my_free((void **)&env->value);
		my_free((void **)&env);
		my_free((void **)&curr);
		curr = next;
	}
	*env_list = NULL;
}

void	free_resources(t_shell *shell)
{
	my_close(&shell->stdin_fd);
	my_close(&shell->stdout_fd);
	my_close(&shell->stderr_fd);
	my_free((void **)&shell->line);
	free_env_list(&shell->env_list);
	free_token_list(&shell->token_list);
}
