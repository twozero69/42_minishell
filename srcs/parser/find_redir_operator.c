/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_redir_operator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 23:59:29 by younglee          #+#    #+#             */
/*   Updated: 2022/06/30 03:51:21 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_redir_operator(enum e_token type)
{
	if (type == TK_INPUT_REDIR)
		return (TRUE);
	if (type == TK_HEREDOC_REDIR)
		return (TRUE);
	if (type == TK_OUTPUT_REDIR)
		return (TRUE);
	if (type == TK_APPEND_REDIR)
		return (TRUE);
	return (FALSE);
}

static enum e_ast	get_node_type(enum e_token type)
{
	if (type == TK_INPUT_REDIR)
		return (NODE_INPUT_REDIR);
	if (type == TK_HEREDOC_REDIR)
		return (NODE_HEREDOC_REDIR);
	if (type == TK_OUTPUT_REDIR)
		return (NODE_OUTPUT_REDIR);
	if (type == TK_APPEND_REDIR)
		return (NODE_APPEND_REDIR);
	print_minishell_error(TRUE, "find_redir_operator.c", "invalid node");
	return (NODE_INVALID);
}

int	find_redir_operator(t_list *tk_list, t_list **junc, enum e_ast *type)
{
	t_token	*token;

	while (tk_list != NULL)
	{
		token = (t_token *)tk_list->content;
		if (check_redir_operator(token->type))
		{
			*junc = tk_list;
			*type = get_node_type(token->type);
			if (*type == NODE_INVALID)
				return (FALSE);
			token->type = TK_PARSER_VISIT;
			return (TRUE);
		}
		if (token->type == TK_PARSER_VISIT)
			return (FALSE);
		if (token->type == TK_LEFT_PARENTHESIS)
			tk_list = get_right_parenthesis(tk_list)->next;
		else
			tk_list = tk_list->next;
	}
	return (FALSE);
}
