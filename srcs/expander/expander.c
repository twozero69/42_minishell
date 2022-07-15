/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jubae <jubae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 10:33:30 by jubae             #+#    #+#             */
/*   Updated: 2022/07/16 00:56:30 by jubae            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expander_start(t_ast *node, t_list *env_list, int depth)
{
	int	i;

	i = 0;
	// printf("depth: %d | type: %d\n", depth, node->type);
	while (node->argv != NULL && node->argv[i] != NULL)
	{
		// printf("before expander : [%s]\n", node->argv[i]);
		node->argv[i] = set_expander(node->argv[i], env_list);
		// printf("after  expander : [%s]\n", node->argv[i]);
		i++;
	}
	if (node->left_child != NULL)
		expander_start(node->left_child, env_list, depth + 1);
	if (node->right_child != NULL)
		expander_start(node->right_child, env_list, depth + 1);
}

void	expander(t_shell *shell)
{
	expander_start(shell->ast, shell->env_list, 0);
	// system("leaks minishell");
	shell->status = SHELL_EXECUTOR;
}
