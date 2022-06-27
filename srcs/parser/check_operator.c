/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_operator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 01:44:03 by younglee          #+#    #+#             */
/*   Updated: 2022/06/28 01:53:09 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_operator(enum e_token type)
{
	if (type == TK_WORD)
		return (TRUE);
	if (type == TK_INPUT_REDIR)
		return (TRUE);
	if (type == TK_HEREDOC_REDIR)
		return (TRUE);
	if (type == TK_OUTPUT_REDIR)
		return (TRUE);
	if (type == TK_APPEND_REDIR)
		return (TRUE);
	if (type == TK_LEFT_PARENTHESIS)
		return (TRUE);
	return (FALSE);
}
