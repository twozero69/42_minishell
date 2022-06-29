/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:29:39 by younglee          #+#    #+#             */
/*   Updated: 2022/06/30 01:58:19 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	make_ast(t_shell *shell)
{
	shell->ast = (t_ast *)malloc(sizeof(t_ast));
	if (shell->ast == NULL)
		return (FAIL);
	ft_memset(shell->ast, 0, sizeof(t_ast));
	if (make_ast_node(shell->token_list, shell->ast) == FAIL)
		return (FAIL);
	return (SUCCESS);
}

void	parser(t_shell *shell)
{
	if (check_syntax(shell->token_list) == FALSE)
	{
		shell->exit_status = EXIT_SYNTEX_ERROR;
		return ;
	}
	if (make_ast(shell) == FAIL)
		exit_with_error("parser.c: malloc failed", shell);
	free_token_list(&shell->token_list);
	shell->status = SHELL_EXPANDER;
}
