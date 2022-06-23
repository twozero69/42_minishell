/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_resources.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 10:13:42 by younglee          #+#    #+#             */
/*   Updated: 2022/06/23 20:13:38 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stddef.h>
#include "minishell.h"

static void	my_close(int *fd)
{
	if (*fd == -1)
		return ;
	close(*fd);
	*fd = -1;
}

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
		free(env->key);
		free(env->value);
		free(env);
		free(curr);
		curr = next;
	}
	*env_list = NULL;
}

void	free_resources(t_minishell *minishell)
{
	my_close(&minishell->stdin_fd);
	my_close(&minishell->stdout_fd);
	my_close(&minishell->stderr_fd);
	free_env_list(&minishell->env_list);
}
