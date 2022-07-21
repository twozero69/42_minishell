/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:29:39 by younglee          #+#    #+#             */
/*   Updated: 2022/07/17 19:41:23 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_ast_node(t_ast *node)
{
	ft_memset(node, 0, sizeof(t_ast));
	node->pipe[0] = -1;
	node->pipe[1] = -1;
	node->cmd_in_fd = -1;
	node->cmd_out_fd = -1;
	node->redir_file_fd = -1;
}

static int	make_ast(t_shell *shell)
{
	if (shell->token_list == NULL)
		return (SUCCESS);
	shell->ast = (t_ast *)malloc(sizeof(t_ast));
	if (shell->ast == NULL)
		return (FAIL);
	init_ast_node(shell->ast);
	if (make_ast_node(shell->token_list, shell->ast) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	parser(t_shell *shell)
{
	if (check_syntax(shell->token_list) == FALSE)
	{
		shell->status = SHELL_READLINE;
		shell->exit_status = EXIT_SYNTEX_ERROR;
		return ;
	}
	if (make_ast(shell) == FAIL)
		exit_with_clib_error("parser.c: malloc", shell);
	free_token_list(&shell->token_list);
	shell->status = SHELL_EXPANDER;
}
