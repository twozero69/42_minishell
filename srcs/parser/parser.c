/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 22:29:39 by younglee          #+#    #+#             */
/*   Updated: 2022/06/28 15:02:50 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// static int	make_ast(t_shell *shell)
// {

// 	return (SUCCESS);
// }

void	parser(t_shell *shell)
{
	if (check_syntax(shell->token_list) == FALSE)
		return ;
	// if (make_ast(shell) == FAIL)
	// 	exit_with_error("parser.c: malloc failed", shell);
	free_token_list(&shell->token_list);
	shell->status = SHELL_EXPANDER;
}
