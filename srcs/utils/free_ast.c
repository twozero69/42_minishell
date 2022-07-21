/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/30 02:58:55 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 10:19:40 by younglee         ###   ########seoul.kr  */
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

void	close_pipe(int *pipe)
{
	my_close(&pipe[0]);
	my_close(&pipe[1]);
}

static int	check_redir_node(enum e_ast type)
{
	if (type == NODE_INPUT_REDIR)
		return (TRUE);
	if (type == NODE_OUTPUT_REDIR)
		return (TRUE);
	if (type == NODE_APPEND_REDIR)
		return (TRUE);
	return (FALSE);
}

static void	free_ast_node(t_ast *node)
{
	if (node == NULL)
		return ;
	free_ast_node(node->left_child);
	free_ast_node(node->right_child);
	free_argv(&node->argv);
	if (node->type == NODE_PIPE || node->type == NODE_HEREDOC_REDIR)
		close_pipe(node->pipe);
	if (check_redir_node(node->type) == TRUE)
		my_close(&node->redir_file_fd);
	my_free((void **)&node);
}

void	free_ast(t_ast **ast)
{
	if (*ast == NULL)
		return ;
	free_ast_node(*ast);
	*ast = NULL;
}
