/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:58:55 by younglee          #+#    #+#             */
/*   Updated: 2022/06/30 03:23:45 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	free_argv(char ***argv_pt)
{
	char	**argv;

	argv = *argv_pt;
	if (argv == NULL)
		return ;
	while (*argv != NULL)
	{
		my_free((void **)argv);
		argv++;
	}
	my_free((void **)argv_pt);
	*argv_pt = NULL;
}

static void	free_ast_node(t_ast *node)
{
	if (node == NULL)
		return ;
	free_ast_node(node->left_child);
	free_ast_node(node->right_child);
	free_argv(&node->argv);
	my_free((void **)&node);
}

void	free_ast(t_ast **ast)
{
	if (*ast == NULL)
		return ;
	free_ast_node(*ast);
	*ast = NULL;
}
