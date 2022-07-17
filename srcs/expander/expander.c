/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:33:30 by jubae             #+#    #+#             */
/*   Updated: 2022/07/17 11:38:31 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander_start(t_ast *node, t_list *env_list)
{
	int	i;

	if (node == NULL)
		return ;
	i = 0;
	while (node->argv != NULL && node->argv[i] != NULL)
	{
		node->argv[i] = set_expander(node->argv[i], env_list);
		i++;
	}
	if (node->left_child != NULL)
		expander_start(node->left_child, env_list);
	if (node->right_child != NULL)
		expander_start(node->right_child, env_list);
}

void	expander(t_shell *shell)
{
	expander_start(shell->ast, shell->env_list);
	shell->status = SHELL_EXECUTOR;
}
