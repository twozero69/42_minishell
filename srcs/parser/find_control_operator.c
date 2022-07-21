/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_control_operator.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: younglee <younglee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 19:07:11 by younglee          #+#    #+#             */
/*   Updated: 2022/06/30 05:05:28 by younglee         ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_control_operator(enum e_token type)
{
	if (type == TK_PIPE)
		return (TRUE);
	if (type == TK_AND)
		return (TRUE);
	if (type == TK_OR)
		return (TRUE);
	return (FALSE);
}

int	find_control_operator(t_list *tk_list, t_list **junc, enum e_ast *type)
{
	t_token	*token;

	while (tk_list != NULL)
	{
		token = (t_token *)tk_list->content;
		if (check_control_operator(token->type))
		{
			*junc = tk_list;
			if (token->type == TK_PIPE)
				*type = NODE_PIPE;
			if (token->type == TK_AND)
				*type = NODE_AND;
			if (token->type == TK_OR)
				*type = NODE_OR;
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
